/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ICU_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 11, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : ICU (Input Capture Unit on Timer1)
 *
 * Note : ICU is hardware-coupled to Timer1. Timer1 must be running
 *        (TIMER1_voidInit) before using ICU functions.
 *
 *        Input Capture loads ICR1 with the TCNT1 value at each edge.
 *        Therefore ICU must be used with a Timer1 mode where ICR1 is NOT
 *        the TOP register (Normal / CTC_OCR1A / PWM_8/9/10-bit /
 *        Phase-Correct OCR1A / Fast PWM 8/9/10-bit). Do NOT use ICU while
 *        Timer1 runs CTC_ICR1, Phase-Correct ICR1, Phase&Freq-Correct ICR1
 *        or Fast PWM ICR1 modes, because each captured edge would overwrite
 *        the ICR1 TOP value.
 */


#ifndef _MCAL_7_ICU_ICU_INTERFACE_H_
#define _MCAL_7_ICU_ICU_INTERFACE_H_

	#define ICU_VECTOR_ID		0

	/* Input Capture Trigger Edge Options */
	#define ICU_FALLING_EDGE		0
	#define ICU_RISING_EDGE			1

	void ICU_voidInit (void) ;
	u8   ICU_u8SetTriggerEdge (u8 Copy_u8Edge) ;
	void ICU_voidEnableInterrupt (void) ;
	void ICU_voidDisableInterrupt (void) ;
	u16  ICU_u16GetICR1Value (void) ;
	u8   ICU_u8SetCallBack (void (*Copy_pvCallBackFunc)(void)) ;

#endif /* _MCAL_7_ICU_ICU_INTERFACE_H_ */
