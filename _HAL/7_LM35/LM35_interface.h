/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LM35_interfae.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 6, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _HAL
 * SWC   : LM35
 */

#ifndef _HAL_7_LM35_LM35_INTERFACE_H_
#define _HAL_7_LM35_LM35_INTERFACE_H_

#define ADC_RESOLUTION_10_BIT 0
#define ADC_RESOLUTION_8_BIT  1



typedef struct
	{
		u8 Copy_u8LM35Channel ;
		u8 Copy_u8ADCVoltageReference ;       /* Vref = 5 , 2.56 , External  */
		u8 Copy_u8ADCResolution ;            /* ADC_RESOLUTION_10_BIT or ADC_RESOLUTION_8_BIT  */
	} LM35_CONFIG ;

	u8 LM35_u8GetTemp (LM35_CONFIG * lm35 , u8 * Copy_u8TempValue) ;


#endif /* _HAL_7_LM35_LM35_INTERFACE_H_ */
