/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ICU_private.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 11, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : ICU (Input Capture Unit on Timer1)
 */

#ifndef _MCAL_7_ICU_ICU_PRIVATE_H_
#define _MCAL_7_ICU_ICU_PRIVATE_H_

	/* Registers used by ICU (minimal set, ICU stays independent from TIMER driver) */
	#define ICU_TCCR1B			*((volatile u8*)0X4E)
	#define ICU_ICR1			*((volatile u16*)0X46)
	#define ICU_TIMSK			*((volatile u8*)0X59)
	#define ICU_TIFR			*((volatile u8*)0X58)

	/* TCCR1B bits */
	#define ICU_ICNC1			7
	#define ICU_ICES1			6

	/* TIMSK bits */
	#define ICU_TICIE1			5

	/* TIFR bits */
	#define ICU_ICF1			5

	#define ICU_DISABLE						0
	#define ICU_ENABLE						1

#endif /* _MCAL_7_ICU_ICU_PRIVATE_H_ */
