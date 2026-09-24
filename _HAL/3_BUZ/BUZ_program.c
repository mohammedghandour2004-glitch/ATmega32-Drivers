/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BUZ_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 1, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _HAL
 * SWC   : BUZ
 */


#include "../../_LIB/BIT_MATH.h"
#include "../../_LIB/STD_TYPES.h"

#include "../../_HAL/3_BUZ/BUZ_config.h"
#include "../../_HAL/3_BUZ/BUZ_interface.h"
#include "../../_HAL/3_BUZ/BUZ_private.h"
#include "../../_MCAL/2_DIO/DIO_interface.h"


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function initialize the pin which connected to BUZ as output pin
* Parameters :
            => struct has the BUZ porn , pin , status
* return : void
*/
void BUZ_voidInit( BUZ_Type BUZ_Configuration )
{

	DIO_EnumSetPinDirection( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_OUTPUT );

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set high on BUZ pin ( BUZ on )
* Parameters :
            => struct has the BUZ porn , pin , status
* return : void
*/
void BUZ_voidOn  ( BUZ_Type BUZ_Configuration )
{

	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){

		DIO_EnumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_HIGH );

	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){

		DIO_EnumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_LOW  );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function set low on BUZ pin ( BUZ off )
* Parameters :
             => struct has the BUZ porn , pin , status
* return : void
*/
void BUZ_voidOff ( BUZ_Type BUZ_Configuration )
{

	if( BUZ_Configuration.Active_State == ACTIVE_HIGH ){

		DIO_EnumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_LOW  );

	}else if( BUZ_Configuration.Active_State == ACTIVE_LOW ){

		DIO_EnumSetPinValue( BUZ_Configuration.Port , BUZ_Configuration.Pin , DIO_PIN_HIGH  );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function toggle BUZ pin
* Parameters :
             => struct has the BUZ porn , pin , status
* return : void
*/
void BUZ_voidToggle      ( BUZ_Type BUZ_Configuration )
{
	DIO_EnumTogglePinValue  ( BUZ_Configuration.Port , BUZ_Configuration.Pin );
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
