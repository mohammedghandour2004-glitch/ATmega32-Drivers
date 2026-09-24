/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ICU_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 11, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : ICU (Input Capture Unit on Timer1)
 */

#include "../../_LIB/BIT_MATH.h"
#include "../../_LIB/STD_TYPES.h"
#include "../../_MCAL/7_ICU/ICU_config.h"
#include "../../_MCAL/7_ICU/ICU_interface.h"
#include "../../_MCAL/7_ICU/ICU_private.h" /*You have to include ICU_private.h before ICU_config.h*/


/*Global Pointer to Function to Hold the Call Back Function Address for ICU ISR*/
static void (*ICU_pvCallBackFunc)(void) = NULL ;

/*------------------------------------------------------------------------------------------------------------------*/
/*
	Hint : This func for initial state of trigger + noise canceler + interrupt (pre-build)
	Note : Timer1 must be running before ICU_voidInit is used
*/
void ICU_voidInit(void)
{
	/* Set Noise Canceler */
	#if (ICU_NOISE_CANCELER == ICU_ENABLE)
		SET_BIT(ICU_TCCR1B , ICU_ICNC1);
	#elif (ICU_NOISE_CANCELER == ICU_DISABLE)
		CLR_BIT(ICU_TCCR1B , ICU_ICNC1);
	#else
		#error "Wrong ICU_NOISE_CANCELER Config"
	#endif

	/* Set trigger source (initial edge from pre-build config) */
	#if (ICU_INITIAL_TRIGGER_EDGE == ICU_RISING_EDGE)
		SET_BIT(ICU_TCCR1B , ICU_ICES1);
	#elif (ICU_INITIAL_TRIGGER_EDGE == ICU_FALLING_EDGE)
		CLR_BIT(ICU_TCCR1B , ICU_ICES1);
	#else
		#error "Wrong ICU_INITIAL_TRIGGER_EDGE Config"
	#endif

	/* Clear any pending Input Capture flag */
	SET_BIT(ICU_TIFR , ICU_ICF1);

	/* Enable/Disable Interrupt of ICU (default from pre-build config) */
	#if (ICU_INTERRUPT == ICU_ENABLE)
		SET_BIT(ICU_TIMSK , ICU_TICIE1);
	#elif (ICU_INTERRUPT == ICU_DISABLE)
		CLR_BIT(ICU_TIMSK , ICU_TICIE1);
	#else
		#error "Wrong ICU_INTERRUPT Config"
	#endif
}

//------------------------------------------------------------------------------------------------------------------
/*
	Hint : This func for change the trigger state (post-build)
	Options :-
	 1- ICU_RISING_EDGE
	 2- ICU_FALLING_EDGE
*/
u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorStatus = OK ;

	/* Change The trigger source as Rising edge or Falling edge */
	if (Copy_u8Edge == ICU_RISING_EDGE)
	{
		SET_BIT(ICU_TCCR1B , ICU_ICES1);
	}
	else if (Copy_u8Edge == ICU_FALLING_EDGE)
	{
		CLR_BIT(ICU_TCCR1B , ICU_ICES1);
	}
	else
	{
		Local_u8ErrorStatus = NOK ;
	}

	return Local_u8ErrorStatus;
}

//------------------------------------------------------------------------------------------------------------------
void ICU_voidEnableInterrupt(void)
{
	SET_BIT(ICU_TIMSK , ICU_TICIE1);
}

//------------------------------------------------------------------------------------------------------------------
void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(ICU_TIMSK , ICU_TICIE1);
}

//------------------------------------------------------------------------------------------------------------------
u16 ICU_u16GetICR1Value(void)
{
	return ICU_ICR1;
}

//------------------------------------------------------------------------------------------------------------------
u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK ;

	if (Copy_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc = Copy_pvCallBackFunc ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}

/*TIMER1 Input Capture (ICU) ISR*/
void __vector_6 (void)		__attribute__((signal)) ;
void __vector_6 (void)
{
	if (ICU_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc() ;
	}
}
