/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< KPD_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 15, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _HAL
 * SWC   : KPD
 */

#ifndef _HAL_6_KPD_KPD_INTERFACE_H_
#define _HAL_6_KPD_KPD_INTERFACE_H_


#define NOTPRESSED 0xff

void KPD_Init         (void          );
u8   KPD_u8GetPressed (void          );

#endif /* _HAL_6_KPD_KPD_INTERFACE_H_ */
