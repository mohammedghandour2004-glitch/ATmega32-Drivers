/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< TIMER_register.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 11, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : TIMER (Timer0 / Timer1 / Timer2)
 *
 * Note: TIMER_register.h is kept in the TIMER driver ONLY.
 *       ICU and WDT define their own minimal registers in their private.h.
 */

#ifndef _MCAL_6_TIMER_TIMER_REGISTER_H_
#define _MCAL_6_TIMER_TIMER_REGISTER_H_

    #define SREG            *((volatile u8 *)0x5F)
	#define TIMSK			*((volatile u8*)0X59)
	#define TIFR			*((volatile u8*)0X58)

	/*Timer0*/
	#define TCCR0			*((volatile u8*)0X53)
	#define TCNT0			*((volatile u8*)0X52)
	#define OCR0			*((volatile u8*)0X5C)

	/*Timer1*/
	#define TCCR1A			*((volatile u8*)0X4F)
	#define TCCR1B			*((volatile u8*)0X4E)
	#define TCNT1H          *((volatile u8 *)(0x4D))
	#define TCNT1L          *((volatile u8 *)(0x4C))
	#define TCNT1			*((volatile u16*)0X4C)    /* u16 for HIGH & LOW */
	#define OCR1AL          *((volatile u8 *)(0x4A))
	#define OCR1AH          *((volatile u8 *)(0x4B))
	#define OCR1A			*((volatile u16*)0X4A)
	#define OCR1BL          *((volatile u8 *)(0x48))
	#define OCR1BH          *((volatile u8 *)(0x49))
	#define OCR1B			*((volatile u16*)0X48)
	#define ICR1H           *((volatile u8 *)(0x47))
	#define ICR1L           *((volatile u8 *)(0x46))
	#define ICR1			*((volatile u16*)0X46)

	/*Timer2*/
	#define TCCR2			*((volatile u8*)0X45)
	#define TCNT2			*((volatile u8*)0X44)
	#define OCR2			*((volatile u8*)0X43)

#endif /* _MCAL_6_TIMER_TIMER_REGISTER_H_ */
