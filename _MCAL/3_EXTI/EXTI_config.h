/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< EXTI_config.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 17, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : EXIT
 */

#ifndef _MCAL_3_EXTI_EXTI_CONFIG_H_
#define _MCAL_3_EXTI_EXTI_CONFIG_H_

/*
 Options :-

 	 1-EXTI_LINE0
 	 2-EXTI_LINE1
 	 3-EXTI_LINE2

 */

#define EXTI_LINE   EXTI_LINE0

/*
 Options :-

 	 1-EXTI_FALLING_EDGE
 	 2-EXTI_RISING_EDGE
 	 3-EXTI_LOW_LEVEL
 	 4-EXTI_ON_CHANGE

 */

#define EXTI_SENSE_MODE  EXTI_FALLING_EDGE

#endif /* _MCAL_3_EXTI_EXTI_CONFIG_H_ */
