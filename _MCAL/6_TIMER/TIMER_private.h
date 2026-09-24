/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< TIMER_private.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 11, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : TIMER (Timer0 / Timer1 / Timer2)
 */

#ifndef _MCAL_6_TIMER_TIMER_PRIVATE_H_
#define _MCAL_6_TIMER_TIMER_PRIVATE_H_

	/*  REG Bits */

	#define TIMSK_TOIE0		0
	#define TIMSK_OCIE0		1
	#define TIMSK_TOIE1		2
	#define TIMSK_OCIE1B	3
	#define TIMSK_OCIE1A	4
	#define TIMSK_TOIE2		6
	#define TIMSK_OCIE2		7

	#define TIFR_TOV0		0
	#define TIFR_OCF0		1
	#define TIFR_TOV1		2
	#define TIFR_OCF1B		3
	#define TIFR_OCF1A		4
	#define TIFR_TOV2		6
	#define TIFR_OCF2		7

	/*Timer0*/
	#define TCCR0_FOC0      7
	#define TCCR0_WGM00		6
	#define TCCR0_COM01		5
	#define TCCR0_COM00		4
	#define TCCR0_WGM01		3
	#define TCCR0_CS02      2
	#define TCCR0_CS01		1
	#define TCCR0_CS00		0

	/*Timer1*/
	#define TCCR1A_COM1A1		7
	#define TCCR1A_COM1A0		6
	#define TCCR1A_COM1B1		5
	#define TCCR1A_COM1B0		4
	#define TCCR1A_WGM11		1
	#define TCCR1A_WGM10		0

	#define TCCR1B_WGM13		4
	#define TCCR1B_WGM12		3

	/*Timer2*/
	#define TCCR2_WGM20		6
	#define TCCR2_COM21		5
	#define TCCR2_COM20		4
	#define TCCR2_WGM21		3

	/*Timer2 Prescaler Selection Options
	 * Note : On ATmega32 the Timer2 prescaler encodings are NOT the same as Timer0/Timer1.
	 * Timer2 : STOP, /1, /8, /32, /64, /128, /256, /1024
	 */
	#define TIMER2_NO_CLOCK_SOURCE			0
	#define TIMER2_NO_PRESCALER_FACTOR		1
	#define TIMER2_DIVISION_FACTOR_8		2
	#define TIMER2_DIVISION_FACTOR_32		3
	#define TIMER2_DIVISION_FACTOR_64		4
	#define TIMER2_DIVISION_FACTOR_128		5
	#define TIMER2_DIVISION_FACTOR_256		6
	#define TIMER2_DIVISION_FACTOR_1024		7

	#define DISABLE						                    0
	#define ENABLE						                    1

	#define TIMER_NO_CLOCK_SOURCE	 	                    0
	#define TIMER_NO_PRESCALER_FACTOR 	                    1
	#define TIMER_DIVISION_FACTOR_8	 	                    2
	#define TIMER_DIVISION_FACTOR_64	                    3
	#define TIMER_DIVISION_FACTOR_256	                    4
	#define TIMER_DIVISION_FACTOR_1024	                    5
	#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING	        6
	#define TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING	        7

	#define TIMER_PRESCALER_MASK					        0b11111000 /* This Value also could use for bit masking */

	#define TIMER_NORMAL_MODE						        0
	#define TIMER_PWM_MODE							        1
	#define TIMER_CTC_MODE							        2
	#define TIMER_FAST_PWM_MODE						        3

	#define TIMER_OC_DISCONNECTED					        0
	#define TIMER_OC_TOGGEL							        1
	#define TIMER_OC_LOW							        2
	#define TIMER_OC_HIGH							        3

	#define TIMER_CLR_ON_CTC_SET_ON_TOP				        2
	#define TIMER_SET_ON_CTC_CLR_ON_TOP				        3

	#define TIMER1_NORMAL_MODE								0
	#define TIMER1_PWM_8_BIT_MODE							1
	#define TIMER1_PWM_9_BIT_MODE							2
	#define TIMER1_PWM_10_BIT_MODE							3
	#define TIMER1_CTC_OCR1A_MODE							4
	#define TIMER1_FAST_PWM_8_BIT_MODE						5
	#define TIMER1_FAST_PWM_9_BIT_MODE 						6
	#define TIMER1_FAST_PWM_10_BIT_MODE						7
	#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE		8
	#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE	9
	#define TIMER1_PWM_PHASE_CORRECT_ICR1_MODE				10
	#define TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE				11
	#define TIMER1_CTC_ICR1_MODE							12
	#define TIMER1_FAST_PWM_ICR1_MODE						14
	#define TIMER1_FAST_PWM_OCR1A_MODE						15

#endif /* _MCAL_6_TIMER_TIMER_PRIVATE_H_ */
