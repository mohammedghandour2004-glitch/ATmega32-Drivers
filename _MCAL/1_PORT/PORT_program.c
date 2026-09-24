/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PORT_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 14, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : PORT
 */


#include "../../_LIB/STD_TYPES.h"
#include "../../_MCAL/1_PORT/PORT_config.h"
#include "../../_MCAL/1_PORT/PORT_interface.h"
#include "../../_MCAL/1_PORT/PORT_private.h"


void PORT_voidInit(void)
{
	DDRA_Register = PORTA_DIR;
	DDRB_Register = PORTB_DIR;
	DDRC_Register = PORTC_DIR;
	DDRD_Register = PORTD_DIR;

	/*
		Hint : will set 1 if The pin input Pull-up
	*/
	PORTA_Register = PORTA_INITIAL_VALUE;
	PORTB_Register = PORTB_INITIAL_VALUE;
	PORTC_Register = PORTC_INITIAL_VALUE;
	PORTD_Register = PORTD_INITIAL_VALUE;
}
