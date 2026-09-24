/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_program.C >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: August 9, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : DIO/GPIO
 */

#include "../../_LIB/BIT_MATH.h"
#include "../../_LIB/STD_TYPES.h"
#include "../../_MCAL/2_DIO/DIO_config.h"
#include "../../_MCAL/2_DIO/DIO_interface.h"
#include "../../_MCAL/2_DIO/DIO_private.h"


/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>IO PINS<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 */
// SET PIN DIRECTION FUNCTION
DIO_ErrorStatus DIO_EnumSetPinDirection (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction)
{
	DIO_ErrorStatus LOC_EnumState = DIO_OK;
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
			if (Copy_u8Direction == DIO_PIN_OUTPUT)
			{
				switch (Copy_u8PORT)
				{
				case DIO_PORTA : SET_BIT(DDRA, Copy_u8PIN); break;
				case DIO_PORTB : SET_BIT(DDRB, Copy_u8PIN); break;
				case DIO_PORTC : SET_BIT(DDRC, Copy_u8PIN); break;
				case DIO_PORTD : SET_BIT(DDRD, Copy_u8PIN); break;
				}
			}
			else if (Copy_u8Direction == DIO_PIN_INPUT)
			{
				switch (Copy_u8PORT)
				{
				case DIO_PORTA : CLR_BIT(DDRA, Copy_u8PIN); break;
				case DIO_PORTB : CLR_BIT(DDRB, Copy_u8PIN); break;
				case DIO_PORTC : CLR_BIT(DDRC, Copy_u8PIN); break;
				case DIO_PORTD : CLR_BIT(DDRD, Copy_u8PIN); break;
				}
			}
			else
			{
				LOC_EnumState = DIO_NOK;
			}
	}
	else
	{
		LOC_EnumState = DIO_NOK;
	}
	return LOC_EnumState;
}


// SET PIN VALUE FUNCTION
DIO_ErrorStatus DIO_EnumSetPinValue     (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value)
{
	DIO_ErrorStatus LOC_EnumState = DIO_OK;
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		if (Copy_u8Value == DIO_PIN_HIGH)
		{
			switch (Copy_u8PORT)
			{
			case DIO_PORTA : SET_BIT(PORTA, Copy_u8PIN); break;
			case DIO_PORTB : SET_BIT(PORTB, Copy_u8PIN); break;
			case DIO_PORTC : SET_BIT(PORTC, Copy_u8PIN); break;
			case DIO_PORTD : SET_BIT(PORTD, Copy_u8PIN); break;
			}
		}
		else if (Copy_u8Value == DIO_PIN_LOW)
		{
			switch (Copy_u8PORT)
			{
			case DIO_PORTA : CLR_BIT(PORTA, Copy_u8PIN); break;
			case DIO_PORTB : CLR_BIT(PORTB, Copy_u8PIN); break;
			case DIO_PORTC : CLR_BIT(PORTC, Copy_u8PIN); break;
			case DIO_PORTD : CLR_BIT(PORTD, Copy_u8PIN); break;
			}
		}
		else
		{
			LOC_EnumState = DIO_NOK;
		}
	}
	else
	{
		LOC_EnumState = DIO_NOK;
	}

	return LOC_EnumState;
}


// GET PIN VALUE FUNCTION
DIO_ErrorStatus   DIO_EnumGetPinValue     (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData)
{

	DIO_ErrorStatus LOC_EnumState = DIO_OK;
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7) && (Copy_PtrData != NULL))
	{
		switch (Copy_u8PORT)
		{
		case DIO_PORTA : *Copy_PtrData = GET_BIT(PINA, Copy_u8PIN); break;
		case DIO_PORTB : *Copy_PtrData = GET_BIT(PINB, Copy_u8PIN); break;
		case DIO_PORTC : *Copy_PtrData = GET_BIT(PINC, Copy_u8PIN); break;
		case DIO_PORTD : *Copy_PtrData = GET_BIT(PIND, Copy_u8PIN); break;
		}
	}
	else
	{
		LOC_EnumState = DIO_NOK;
	}
	return LOC_EnumState;

}


// TOGGLE PIN VALUE FUNCTION
DIO_ErrorStatus DIO_EnumTogglePinValue  (u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	DIO_ErrorStatus LOC_EnumState = DIO_OK;
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		switch (Copy_u8PORT)
		{
		case DIO_PORTA : TOG_BIT(PORTA, Copy_u8PIN); break;
		case DIO_PORTB : TOG_BIT(PORTB, Copy_u8PIN); break;
		case DIO_PORTC : TOG_BIT(PORTC, Copy_u8PIN); break;
		case DIO_PORTD : TOG_BIT(PORTD, Copy_u8PIN); break;
		}
	}
	else
	{
		LOC_EnumState = DIO_NOK;
	}
	return LOC_EnumState;
}


/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>IO PORTS<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 */

DIO_ErrorStatus DIO_EnumSetPortDirection (u8 Copy_u8PORT, u8 Copy_u8Direction)
{
    DIO_ErrorStatus LOC_EnumState = DIO_OK;

    if (Copy_u8PORT <= DIO_PORTD)
    {
        switch (Copy_u8PORT)
        {
            case DIO_PORTA:
                // DDRA
            	DDRA = Copy_u8Direction; break;

            case DIO_PORTB:
                // DDRB
            	DDRB = Copy_u8Direction; break;

            case DIO_PORTC:
                // DDRC
            	DDRC = Copy_u8Direction; break;

            case DIO_PORTD:
                // DDRD
            	DDRD = Copy_u8Direction; break;
        }
    }
    else
    {
        LOC_EnumState = DIO_NOK;
    }

    return LOC_EnumState;


}
DIO_ErrorStatus DIO_EnumSetPortValue     (u8 Copy_u8PORT, u8 Copy_u8Value)
{
	DIO_ErrorStatus LOC_EnumState = DIO_OK;
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch (Copy_u8PORT)
		{
		case DIO_PORTA:
			PORTA = Copy_u8Value; break;

		case DIO_PORTB:
			PORTB = Copy_u8Value; break;

		case DIO_PORTC:
			PORTC = Copy_u8Value; break;

		case DIO_PORTD:
			PORTD = Copy_u8Value; break;
		}

	}
	else
	{
		LOC_EnumState = DIO_NOK;
	}

	return LOC_EnumState;
}

DIO_ErrorStatus   DIO_EnumGetPortValue   (u8 Copy_u8PORT, u8 * Copy_PtrData)
{
	DIO_ErrorStatus LOC_EnumState = DIO_OK;
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_PtrData != NULL))
	{
		switch (Copy_u8PORT)
		{
			case DIO_PORTA:
				* Copy_PtrData = PINA; break;

			case DIO_PORTB:
				* Copy_PtrData = PINB; break;

			case DIO_PORTC:
				* Copy_PtrData = PINC; break;

			case DIO_PORTD:
				* Copy_PtrData = PIND; break;
		}
	}
	else
	{
		LOC_EnumState = DIO_NOK;
	}

	return LOC_EnumState;
}

DIO_ErrorStatus DIO_EnumTogglePortValue  (u8 Copy_u8PORT)
{
	DIO_ErrorStatus LOC_EnumState = DIO_OK;
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch (Copy_u8PORT)
		{
			case DIO_PORTA:
				PORTA = ~PORTA; break;

			case DIO_PORTB:
				PORTB = ~PORTB; break;

			case DIO_PORTC:
				PORTC = ~PORTC; break;

			case DIO_PORTD:
				PORTD = ~PORTD; break;
		}
	}
	else
	{
		LOC_EnumState = DIO_NOK;
	}

	return LOC_EnumState;
}



//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function connected internal pull up
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 	  =>Copy_u8ConnectPullup --> [DIO_PIN_HIGH , DIO_PIN_LOW ]
 * return : its status
 */
DIO_ErrorStatus DIO_EnumConnectPullup (u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup)
{

	DIO_ErrorStatus LOC_EnumState = DIO_OK ;

	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		switch(Copy_u8PORT)
		{
		/* Connect or disconnect the pull up resistance to the given pin in port A */
		case DIO_PORTA:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR, PUD);
				CLR_BIT(DDRA, Copy_u8PIN);
				SET_BIT(PORTA, Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTA, Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port B */
		case DIO_PORTB:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR, PUD);
				CLR_BIT(DDRB, Copy_u8PIN);
				SET_BIT(PORTB, Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTB, Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port C */
		case DIO_PORTC:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR, PUD);
				CLR_BIT(DDRC, Copy_u8PIN);
				SET_BIT(PORTC, Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTC, Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port D */
		case DIO_PORTD:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR, PUD);
				CLR_BIT(DDRD, Copy_u8PIN);
				SET_BIT(PORTD, Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTD, Copy_u8PIN);
			}
			break;
		}
	}

	else
	{
		LOC_EnumState = DIO_NOK ;
	}

	return LOC_EnumState ;


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                          IO NIBBLES                     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Breif : This Function write value on high nibbles of the Port
 * Parameters :
 	  =>Copy_u8PORT  --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8value --> to set its high bits on high nibble oh register
 * return : its status
 *
 *Hint1 : High Nibbles = Most Pins [4:7]
 *Hint2 : This Function take the first 4 bits from the value (#) => xxxx#### AND put it in high nobbles
 *
 */
DIO_ErrorStatus DIO_VoidWriteHighNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{

	DIO_ErrorStatus LOC_EnumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value = (Copy_u8value<<4) ;
		switch(Copy_u8PORT)
		{
		case DIO_PORTA :
			PORTA &= 0x0f;                   // make sure the high bits = 0000
			PORTA|=Copy_u8value;			//Set only the high nibble of the port A by the given value
			break ;
		case DIO_PORTB:
			PORTB &= 0x0f;                 //Set only the high nibble of the port B by the given value
			PORTB|= Copy_u8value;
			break ;
		case DIO_PORTC :
			PORTC &= 0x0f;                 //Set only the high nibble of the port C by the given value
			PORTC|=Copy_u8value;
			break ;
		case DIO_PORTD:
			PORTD &= 0x0f;                 //Set only the high nibble of the port D by the given value
			PORTD|=Copy_u8value;
			break ;
		default: break ;

		}
	}
	else
	{
		LOC_EnumState = DIO_NOK;
	}

	return LOC_EnumState ;

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function write value on low nibbles of the Port
 * Parameters :
 	  =>Copy_u8PORT  --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8value --> to set its low bits on high nibble oh register
 * return : its status
 *
 *Hint1 : Low Nibbles = Least Pins [0:3]
 *Hint2 : This Function also take the first 4 bits from the value (#) => xxxx#### AND put it in low nobbles
 *
 */
DIO_ErrorStatus DIO_VoidWriteLowNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{
	DIO_ErrorStatus LOC_EnumState = DIO_OK ;


	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value&=0x0f;
		switch(Copy_u8PORT)
		{
		case DIO_PORTA :
			PORTA &= 0xf0;                 //Set only the high nibble of the port A by the given value
			PORTA |= Copy_u8value;
			break ;
		case DIO_PORTB:
			PORTB &= 0xf0;                 //Set only the high nibble of the port B by the given value
			PORTB |= Copy_u8value;
			break ;
		case DIO_PORTC :
			PORTC &= 0xf0;                 //Set only the high nibble of the port C by the given value
			PORTC |= Copy_u8value;
			break ;
		case DIO_PORTD:
			PORTD &= 0xf0;                 //Set only the high nibble of the port D by the given value
			PORTD |= Copy_u8value;
			break ;
		default: break ;

		}


	}
	else
	{
		LOC_EnumState = DIO_NOK;
	}

	return LOC_EnumState ;

}



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
