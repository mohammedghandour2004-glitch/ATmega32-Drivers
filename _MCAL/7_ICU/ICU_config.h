/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ICU_config.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 11, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : ICU (Input Capture Unit on Timer1)
 */


#ifndef _MCAL_7_ICU_ICU_CONFIG_H_
#define _MCAL_7_ICU_ICU_CONFIG_H_

	/*Set the initial (pre-build) Input Capture Trigger Edge
	 * Choose between
	 * 1. ICU_FALLING_EDGE
	 * 2. ICU_RISING_EDGE
	 */
	#define ICU_INITIAL_TRIGGER_EDGE		ICU_RISING_EDGE

	/*Set the Input Capture Noise Canceler (needs 4 successive equal samples)
	 * Choose between
	 * 1. ICU_DISABLE
	 * 2. ICU_ENABLE
	 */
	#define ICU_NOISE_CANCELER				ICU_DISABLE

	/*Set the Input Capture Interrupt default state (applied by ICU_voidInit)
	 * Choose between
	 * 1. ICU_DISABLE
	 * 2. ICU_ENABLE
	 */
	#define ICU_INTERRUPT					ICU_ENABLE

#endif /* _MCAL_7_ICU_ICU_CONFIG_H_ */
