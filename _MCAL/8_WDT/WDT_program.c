/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< WDT_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 11, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : WDT (Watchdog Timer)
 */

#include "../../_LIB/BIT_MATH.h"
#include "../../_LIB/STD_TYPES.h"
#include "../../_MCAL/8_WDT/WDT_config.h"
#include "../../_MCAL/8_WDT/WDT_interface.h"
#include "../../_MCAL/8_WDT/WDT_private.h" /*You have to include WDT_private.h before WDT_config.h*/

/*------------------------------------------------------------------------------------------------------------------*/
/* Hint : pre-build config, applies the required prescaler from WDT_config.h */
void WDT_voidSleep(void)
{
	/* Clear The Prescaler bits */
	WDT_WDTCR &= WDT_PS_MASKING ;
	/* Set The required prescaller */
	WDT_WDTCR |= WDT_PRESCALER ;
}

//------------------------------------------------------------------------------------------------------------------
void WDT_voidEnable(void)
{
	SET_BIT(WDT_WDTCR , WDTCR_WDE);
}

//------------------------------------------------------------------------------------------------------------------
void WDT_voidDisable(void)
{
	u8 Local_u8SREG ;

	/* Save global interrupt state and disable interrupts
	   (datasheet: interrupts must be off during the timed sequence) */
	Local_u8SREG = WDT_SREG ;
	CLR_BIT(WDT_SREG , WDT_SREG_I) ;

	/* ATmega32 timed sequence:
	   Step 1: write logic one to WDTOE (bit4) AND WDE (bit3) in the same CLK cycle.
	   Step 2: within the next 4 clock cycles, write logic zero to WDE (and WDTOE). */
	WDT_WDTCR = (1 << WDTCR_WDTOE) | (1 << WDTCR_WDE) ;
	WDT_WDTCR = 0 ;

	/* Restore previous global interrupt state */
	WDT_SREG = Local_u8SREG ;
}
