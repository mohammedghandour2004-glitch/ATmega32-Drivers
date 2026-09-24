/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: August 13, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _HAL
 * SWC   : LED
 */
// include two LIBs
#include "../../_LIB/BIT_MATH.h"
#include "../../_LIB/STD_TYPES.h"

#include "../../_HAL/1_LED/LED_config.h"
#include "../../_HAL/1_LED/LED_interface.h"
#include "../../_HAL/1_LED/LED_private.h"
#include "../../_MCAL/2_DIO/DIO_interface.h"




// Initialize the LED by configuring its GPIO pin as an OUTPUT
void LED_VoidInit        ( LED_Type LED_Configuration )
{
	//pin OUTPUT دير ليا هاد الـ DIO خويا || hna led driver kay9olha l dio driver
	DIO_EnumSetPinDirection (LED_Configuration.Port, LED_Configuration.Pin, DIO_PIN_OUTPUT);
}


/*
 * LED ON Function
 * Turn ON the LED depending on its Active State:
 * ACTIVE_HIGH -> GPIO HIGH
 * ACTIVE_LOW  -> GPIO LOW
 */
void LED_VoidOn          ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH )
	{

		DIO_EnumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin, DIO_PIN_HIGH);

	}
	else if( LED_Configuration.Active_State == ACTIVE_LOW )
	{

		DIO_EnumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW  );

	}
}


/*
 * LED OFF Function
 * Turn OFF the LED depending on its Active State:
 * ACTIVE_HIGH -> GPIO LOW
 * ACTIVE_LOW  -> GPIO HIGH
 */
void LED_VoidOff         ( LED_Type LED_Configuration )
{
	if( LED_Configuration.Active_State == ACTIVE_HIGH )
	{

		DIO_EnumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin , DIO_PIN_LOW  );

	}
	else if( LED_Configuration.Active_State == ACTIVE_LOW )
	{

		DIO_EnumSetPinValue( LED_Configuration.Port , LED_Configuration.Pin, DIO_PIN_HIGH );

	}

}


/*
 * LED Toggle Function
 * Invert the current LED state:
 * ON  -> OFF
 * OFF -> ON
 */
void LED_VoidToggle      ( LED_Type LED_Configuration )
{
	DIO_EnumTogglePinValue  ( LED_Configuration.Port , LED_Configuration.Pin );
}

