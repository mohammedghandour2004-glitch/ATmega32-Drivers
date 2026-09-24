/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< EXTI_private.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 17, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : EXIT
 */

#ifndef _MCAL_3_EXTI_EXTI_PRIVATE_H_
#define _MCAL_3_EXTI_EXTI_PRIVATE_H_

#define MCUCR_REG   *((volatile u8 *)0x55)
#define MCUCSR_REG  *((volatile u8 *)0x54)
#define GICR_REG    *((volatile u8 *)0x5B)
#define GIFR_REG    *((volatile u8 *)0x5A)

#define NULL 0

#endif /* _MCAL_3_EXTI_EXTI_PRIVATE_H_ */
