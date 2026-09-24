/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SW_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 4, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _HAL
 * SWC   : SW
 */

#include <util\delay.h>

#include "../../_LIB/BIT_MATH.h"
#include "../../_LIB/STD_TYPES.h"

#include "../../_HAL/2_SW/SW_config.h"
#include "../../_HAL/2_SW/SW_interface.h"
#include "../../_HAL/2_SW/SW_private.h"
#include "../../_MCAL/2_DIO/DIO_interface.h"


//----------------------------------------------------------------------------------------------------------------------------------------------------
/* ============================================================
 * Function: SW_voidInit
 *
 * Purpose:
 * Initialize the switch pin as INPUT and configure
 * the required Pull-Up / Pull-Down mode.
 *
 * Parameters:
 * SW_Config -> Switch configuration structure
 *
 * Return:
 * void
 * ============================================================ */
void SW_voidInit      ( SW_Type SW_Config ){
	/* Configure switch pin as INPUT */
	DIO_EnumSetPinDirection( SW_Config.Port , SW_Config.Pin , DIO_PIN_INPUT );

	/* If Sw is Internal Pull Up */
	if( SW_Config.Pull_State == SW_Int_PULL_UP ){

		DIO_EnumSetPinValue    ( SW_Config.Port , SW_Config.Pin , DIO_PIN_HIGH  );

		/* we could use DIO_EnumConnectPullup */
	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/* ============================================================
 * Function: SW_u8GetPressed
 *
 * Purpose:
 * Read the switch pin and determine whether the switch
 * is PRESSED or NOT PRESSED.
 *
 * Pull-Up logic:
 *     PIN = 0 -> PRESSED
 *     PIN = 1 -> NOT PRESSED
 *
 * Pull-Down logic:
 *     PIN = 0 -> NOT PRESSED
 *     PIN = 1 -> PRESSED
 *
 * Parameters:
 * SW_Config -> Switch configuration structure
 *
 * Return:
 * SW_PRESSED or SW_NOT_PRESSED
 * ============================================================ */

u8   SW_u8GetPressed ( SW_Type SW_Config ){

	/* Local variables:
	 * LOC_u8PinVal -> Stores the actual pin logic level
	 * LOC_u8Result -> Stores the final switch status
	 */
	u8 LOC_u8Result = SW_NOT_PRESSED ;
	u8 LOC_u8PinVal = SW_NOT_PRESSED ;

	/* =========================
	 * Pull-Up Configuration
	 * =========================
	 * Switch is active LOW:
	 * 0 -> PRESSED
	 * 1 -> NOT PRESSED
	 */
	if ( (SW_Config.Pull_State == SW_Int_PULL_UP) || (SW_Config.Pull_State == SW_Ext_PULL_UP) )
	{
		/* Read the current logic level of the switch pin */
		DIO_EnumGetPinValue( SW_Config.Port , SW_Config.Pin , &LOC_u8PinVal );

		if (LOC_u8PinVal==0)
		{
			LOC_u8Result = SW_PRESSED ;
		}
		else if (LOC_u8PinVal==1)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}

	}
	/* =========================
	 * External Pull-Down
	 * =========================
	 * Switch is active HIGH:
	 * 0 -> NOT PRESSED
	 * 1 -> PRESSED
	 */
	else if (SW_Config.Pull_State == SW_Ext_PULL_DOWN)
	{
		DIO_EnumGetPinValue( SW_Config.Port , SW_Config.Pin , &LOC_u8PinVal );

		if (LOC_u8PinVal==0)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}
		else if (LOC_u8PinVal==1)
		{
			LOC_u8Result = SW_PRESSED ;
		}
	}

	/* Return the interpreted switch status */
	return LOC_u8Result ;

}
