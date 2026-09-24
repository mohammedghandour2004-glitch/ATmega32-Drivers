/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SSD_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: August 29, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _HAL
 * SWC   : SSD
 */

#include "../../_LIB/BIT_MATH.h"
#include "../../_LIB/STD_TYPES.h"

#include "../../_HAL/4_SSD/SSD_config.h"
#include "../../_HAL/4_SSD/SSD_interface.h"
#include "../../_HAL/4_SSD/SSD_private.h"
#include "../../_MCAL/2_DIO/DIO_interface.h"

static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR ;

//====================================================================================================================================================
/*
 * Breif : This Function initialize the port which connected to 7 Seg leds as output pins ( 8 Pins or Port )
 * Parameters :
            =>Copy_u8PORT --> Port Name [ SSD_PORTA ,	SSD_PORTB , SSD_PORTC , SSD_PORTD ]
 * return : void
 */
void SSD_voidInitialDataPort  (SSD_Type Copy_structConfig )
{
	DIO_EnumSetPortDirection    ( Copy_structConfig.DataPort , 0xFF );
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function write Number on 7 seg [ 0 : 9 ]
 * Parameters : => struct has the SSD type , data port and enable(port & pin)
 * return : void
 */
void SSD_voidSendNumber( SSD_Type Copy_structConfig , u8 Copy_u8Number ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_EnumSetPortValue( Copy_structConfig.DataPort , Local_u8SSDNumbers[ Copy_u8Number ] );

	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_EnumSetPortValue( Copy_structConfig.DataPort , ~( Local_u8SSDNumbers[ Copy_u8Number ] ) );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function enable common pin
 * Parameters : => struct has the SSD type , data port and enable(port & pin)
 * return : void
 */
void SSD_voidEnable    ( SSD_Type Copy_structConfig ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_EnumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PORT_HIGH );
		DIO_EnumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PORT_LOW );

	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_EnumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PORT_HIGH );
		DIO_EnumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PORT_HIGH );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function disable common pin
 * Parameters : => struct has the SSD type , data port and enable(port & pin)
 * return : void
 */
void SSD_voidDisable   ( SSD_Type Copy_structConfig ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_EnumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PORT_HIGH );
		DIO_EnumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PORT_HIGH );

	}
	else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_EnumSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PORT_HIGH );
		DIO_EnumSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PORT_LOW );

	}

}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
