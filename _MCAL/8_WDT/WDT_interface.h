/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< WDT_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 11, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : WDT (Watchdog Timer)
 */


#ifndef _MCAL_8_WDT_WDT_INTERFACE_H_
#define _MCAL_8_WDT_WDT_INTERFACE_H_

	/* Applies the pre-build prescaler (WDT_PRESCALER) to the WDT */
	void WDT_voidSleep (void) ;

	/* Enables the Watchdog Timer (WDE = 1) */
	void WDT_voidEnable (void) ;

	/* Disables the Watchdog Timer (using the timed sequence) */
	void WDT_voidDisable (void) ;

#endif /* _MCAL_8_WDT_WDT_INTERFACE_H_ */
