/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< TIMER_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 11, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : TIMER (Timer0 / Timer1 / Timer2)
 */


#ifndef _MCAL_6_TIMER_TIMER_INTERFACE_H_
#define _MCAL_6_TIMER_TIMER_INTERFACE_H_

/* Define indexes for the global array of pointers to func for ISR  */

	#define TIMER0_OVF_VECTOR_ID		0
	#define TIMER0_CTC_VECTOR_ID		1

	#define TIMER1_OVF_VECTOR_ID		2
	#define TIMER1_CTCB_VECTOR_ID		3
	#define TIMER1_CTCA_VECTOR_ID		4

	#define TIMER2_OVF_VECTOR_ID		5
	#define TIMER2_CTC_VECTOR_ID		6


	void TIMER0_voidInit                (void) ;
	void TIMER0_voidSetPreload          (u8 Copy_u8Preload) ;
	void TIMER0_voidSetCTC              (u8 Copy_u8CTC) ;
	u8   TIMER0_u8GetTimerCounterValue  (void) ;

	void TIMER1_voidInit                (void) ;
	void TIMER1_voidSetPreload          (u16 Copy_u16Preload) ;
	void TIMER1_voidSetCTCA             (u16 Copy_u16CTCA) ;
	void TIMER1_voidSetCTCB             (u16 Copy_u16CTCB) ;
	void TIMER1_voidSetICR1             (u16 Copy_u16ICR1) ;
	u16  TIMER1_u16GetTimerCounterValue (void) ;

	void TIMER2_voidInit                (void) ;
	void TIMER2_voidSetPreload          (u8 Copy_u8Preload) ;
	void TIMER2_voidSetCTC              (u8 Copy_u8CTC) ;
	u8   TIMER2_u8GetTimerCounterValue  (void) ;

	/*PWM (Timer1 Fast PWM ICR1)*/
	void TIMER_voidSetPWM               (u16 Copy_u16CompareValue);

	/* Callback: Copy_u8VectorID = TIMERx_xxx_VECTOR_ID */
	u8   TIMER_u8SetCallBack            (void (*Copy_pvCallBackFunc)(void) , u8 Copy_u8VectorID) ;

#endif /* _MCAL_6_TIMER_TIMER_INTERFACE_H_ */
