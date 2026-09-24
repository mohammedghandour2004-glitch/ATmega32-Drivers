/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< WDT_private.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 11, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : WDT (Watchdog Timer)
 */

#ifndef _MCAL_8_WDT_WDT_PRIVATE_H_
#define _MCAL_8_WDT_WDT_PRIVATE_H_

	/* Registers used by WDT (minimal set, WDT stays independent from TIMER driver) */
	#define WDT_WDTCR			*((volatile u8*)0X41)
	#define WDT_SREG			*((volatile u8*)0X5F)

	/* WDTCR Bits */
	#define WDTCR_WDTOE			4
	#define WDTCR_WDE			3
	#define WDTCR_WDP2			2
	#define WDTCR_WDP1			1
	#define WDTCR_WDP0			0

	/* SREG Bits */
	#define WDT_SREG_I			7

	/* WDT Prescaler select */
	#define WDT_PS_MASKING		0b11111000
	#define WDT_PS_16_3_MS		0
	#define WDT_PS_32_5_MS		1
	#define WDT_PS_65_MS		2
	#define WDT_PS_0_13_S		3
	#define WDT_PS_0_26_S		4
	#define WDT_PS_0_52_S		5
	#define WDT_PS_1_0_S		6
	#define WDT_PS_2_1_S		7

#endif /* _MCAL_8_WDT_WDT_PRIVATE_H_ */
