/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CLCD_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 4, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _HAL
 * SWC   : CLCD
 */

/***************************************************************************************/
#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../_LIB/STD_TYPES.h"
#include "../../_LIB/BIT_MATH.h"

#include "../../_MCAL/2_DIO/DIO_interface.h"

#include "../../_HAL/5_CLCD/CLCD_interface.h"
#include "../../_HAL/5_CLCD/CLCD_private.h"
#include "../../_HAL/5_CLCD/CLCD_config.h"
#include "../../_HAL/5_CLCD/CLCD_extrachar.h"

/***************************************************************************************/

/*

###########  8 Bits Mode
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PA7|---------------->|D7        |
 |        PA6|---------------->|D6        |
 |        PA5|---------------->|D5        |
 |        PA4|---------------->|D4        |
 |        PA3|---------------->|D3        |
 |        PA2|---------------->|D2        |
 |        PA1|---------------->|D1        |
 |        PA0|---------------->|D0        |
 |           |                 |          |
 |        PC2|---------------->|E         |
 |        PC1|---------------->|RW        |
 |        PC0|---------------->|RS        |
 -----------                   ----------
 */
/***************************************************************************************/


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function Apply initialization sequence for LCD module
* Parameters : nothing
* return : nothing
*/
void CLCD_voidInit        ( void ){



	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	#if   CLCD_MODE == 8

	// 1- must wait more than 30 ms before any action (VDD rises to 4.5 v)
	_delay_ms(50);

	// All Pins as OutPut pins
	DIO_EnumSetPortDirection ( CLCD_DATA_PORT    , DIO_PORT_OUTPUT           );
	DIO_EnumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT  );
	DIO_EnumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT  );
	DIO_EnumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT  );

	/* Return cursor to the first position on the first line  */
	CLCD_VoidSendCommand(lcd_Home);
	_delay_ms(1);

	/*FUNCTION SET Command : 2 lines , 5*8 font size */
	CLCD_VoidSendCommand( EIGHT_BITS ); // 8 Bit Mode ==> 0x38
	_delay_ms(1); // wait more than 39 Ms

	/* DISPLAY & Cursor (ON / OFF) Control */
	CLCD_VoidSendCommand( lcd_DisplayOn_CursorOff );
	_delay_ms(1);

	/* DISPLAY CLEAR */
	CLCD_VoidClearScreen();

	/* ENTRY MODE  SET*/
	CLCD_VoidSendCommand( lcd_EntryMode );
	_delay_ms(1);



	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	#elif   CLCD_MODE == 4

	// 1- must wait more than 30 ms before any action (VDD rises to 4.5 v)
	_delay_ms(50);
	DIO_EnumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_EnumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_EnumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_EnumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_EnumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT  );
	DIO_EnumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT  );
	DIO_EnumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT  );



	/*return home*/
	CLCD_VoidSendCommand( lcd_Home );
	_delay_ms(30);

	/*FUNCTION SET Command*/
	CLCD_VoidSendCommand( FOUR_BITS ); // 4 Bit Mode
	_delay_ms(1);

	/* DISPLAY & Cursor (ON / OFF) Control */
	CLCD_VoidSendCommand( lcd_DisplayOn_CursorOff );
	_delay_ms(1);

	/* DISPLAY CLEAR */
	CLCD_VoidClearScreen();

	/* ENTRY MODE  Set*/
	CLCD_VoidSendCommand( lcd_EntryMode );
	_delay_ms(1);


	#endif




}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function send data to the port which is defined in config.h
* Parameters :
            => Copy_u8Data --> Data that you want to display (for every pixel )
* return : nothing
*/
void CLCD_VoidSendData    ( u8 Copy_u8Data ){

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if   CLCD_MODE == 8

	DIO_EnumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Data        );
	DIO_EnumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH );
	DIO_EnumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	CLCD_VoidSendFallingEdge();

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif   CLCD_MODE == 4

	DIO_EnumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH );
	DIO_EnumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	DIO_VoidWriteHighNibbles (CLCD_DATA_PORT ,(Copy_u8Data>>4));            // send the most 4 bits of data to high nibbles
	CLCD_VoidSendFallingEdge();
	DIO_VoidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Data);               // send the least 4 bits of data to high nibbles
	CLCD_VoidSendFallingEdge();

	#endif

	_delay_ms(1);

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function Interface to send the configuration commands to the LCD Driver
* Parameters :
            => Copy_u8Command --> Command number
* return : nothing
*Hint : RS pin Mode is the difference between this function and the previous (CLCD_voidSendData)
*/
void CLCD_VoidSendCommand ( u8 Copy_u8Command ){

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if   CLCD_MODE == 8

	DIO_EnumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Command     );
	DIO_EnumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW  );
	// RW always connect to GND to Write
	DIO_EnumSetPinValue          (CLCD_CONTROL_PORT,CLCD_RW , DIO_PIN_LOW    );
	CLCD_VoidSendFallingEdge();

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif   CLCD_MODE == 4

	DIO_EnumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW  );
	DIO_EnumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	DIO_VoidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Command>>4);             // send the most 4 bits of data to high nibbles
	CLCD_VoidSendFallingEdge();
	DIO_VoidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Command);                // send the least 4 bits of data to high nibbles
	CLCD_VoidSendFallingEdge();

	#endif

	_delay_ms(1);

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function send string to the port which is defined in config.h
* Parameters :
            => * Copy_u8ptrString  --> Pointer to the string
* return : nothing
*/
void CLCD_VoidSendString  ( const u8 * Copy_u8ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[LOC_u8Iterator] != '\0' ){

		CLCD_VoidSendData( Copy_u8ptrString[LOC_u8Iterator] );
		LOC_u8Iterator++ ;

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function send number to the port which is defined in config.h
* Parameters :
            => Copy_u64Number --> number that you want to display
* return : nothing
*/
void CLCD_VoidSendNumber   ( u64 Copy_u64Number    ){

	u64 LOC_u64Reversed = 1 ;

	if( Copy_u64Number == 0 ){ CLCD_VoidSendData('0'); }

	else{

		while( Copy_u64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 );
			Copy_u64Number /= 10 ;

		}
		while( LOC_u64Reversed != 1 ){

			CLCD_VoidSendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set the curser position
* Parameters :
            => Copy_u8Row --> row number (CLCD_ROW_1 or CLCD_ROW_2)
			=> Copy_u8Col --> column number (CLCD_COL_1 ... CLCD_COL_16)
* return : nothing
*Hint :-
   In This function we send a command which =0b1xxxxxxx
   MSB = 1  ===> refers that it is command to set cursor
   xxxxxxx  ===> refers to AC ( Address Counter 7Bits / DDRAM Locations 128Location )
*/
void CLCD_VoidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col ){

	u8 LOC_u8data ;

	/* In These cases will set at (0,0) ==> if the user enter invalid location */
	if(Copy_u8Row>2||Copy_u8Row<1||Copy_u8Col>16||Copy_u8Col<1)  //check
	{
		LOC_u8data = lcd_SetCursor ;   // first location
	}

	else if( Copy_u8Row == CLCD_ROW_1 ){

		LOC_u8data = ( ( lcd_SetCursor ) + ( Copy_u8Col - 1 ) );              //Row1 -> 0x80+col-1

	}

	else if( Copy_u8Row == CLCD_ROW_2 ){

		LOC_u8data = ( ( lcd_SetCursor ) + (64) + ( Copy_u8Col - 1 ) );       //Row2 -> 0xc0+col-1

	}
	CLCD_VoidSendCommand ( LOC_u8data );
	_delay_ms(1);

}


/*=============================================================================================*/
/*================================== Custom Character ========================================*/
/*=============================================================================================*/

void CLCD_VoidLoadLastNameSet(void)
{
    u8 LOC_u8Iterator = 0;

    // Go To CGRAM
    CLCD_VoidSendCommand(lcd_CGRAM); // Make AC refers to the first Place/Address at CGRAM

	/* Draw Character in CGRAM        */
	/* Hint : it will be copied to DDRAM automatically */
    for(LOC_u8Iterator = 0;
        LOC_u8Iterator < sizeof(CLCD_u8LastNameSet);
        LOC_u8Iterator++)
    {
        CLCD_VoidSendData(CLCD_u8LastNameSet[LOC_u8Iterator]);
    }
}


void CLCD_VoidLoadNameSet(void)
{
    u8 LOC_u8Iterator = 0;

    // Go To CGRAM
    CLCD_VoidSendCommand(lcd_CGRAM);

    // Send Character Address
    for(LOC_u8Iterator = 0;
        LOC_u8Iterator < sizeof(CLCD_u8NameSet);
        LOC_u8Iterator++)
    {
        CLCD_VoidSendData(CLCD_u8NameSet[LOC_u8Iterator]);
    }
}


void CLCD_VoidLoadSymbolSet(void)
{
    u8 LOC_u8Iterator = 0;

    // Go To CGRAM
    CLCD_VoidSendCommand(lcd_CGRAM);

    // Send Character Address
    for(LOC_u8Iterator = 0;
        LOC_u8Iterator < sizeof(CLCD_u8SymbolSet);
        LOC_u8Iterator++)
    {
        CLCD_VoidSendData(CLCD_u8SymbolSet[LOC_u8Iterator]);
    }
}


void CLCD_VoidSendExtraChar(u8 Copy_u8Row,
                            u8 Copy_u8Col,
                            u8 Copy_u8Char)
{
	// Back (AC) To DDRAM
    CLCD_VoidSetPosition(Copy_u8Row, Copy_u8Col);

    CLCD_VoidSendData(Copy_u8Char);
}


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function clear LCD
* Parameters : nothing
* return : nothing
*/
void CLCD_VoidClearScreen(void)
{
	CLCD_VoidSendCommand(lcd_Clear);
	_delay_ms(10); //wait more than 1.53 ms
}


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function send a pulse (falling edge ) to Enable Pin
* Parameters : nothing
* return : nothing
*
* Hint : static Function to forbid calling it out this file
*
*/
static void CLCD_VoidSendFallingEdge(void)
{
	DIO_EnumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_HIGH );
	_delay_ms(1);
	DIO_EnumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_LOW  );
	_delay_ms(1);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
