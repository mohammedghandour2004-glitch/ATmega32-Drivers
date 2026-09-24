/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ADC_private.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 6, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : ADC
 */

#ifndef _MCAL_5_ADC_ADC_PRIVATE_H_
#define _MCAL_5_ADC_ADC_PRIVATE_H_

/* Bit Masking Macros  */
#define ADC_PRE_MASK				0b11111000
#define ADC_CH_MASK                 0b11100000

#define ADMUX				*((volatile u8*)0x27)		//ADC multiplexer selection register
/* ADMUX Bits   */
#define ADMUX_REFS1         7							//Reference selection bit1
#define ADMUX_REFS0         6							//Reference selection bit0
#define ADMUX_ADLAR         5							//ADC left adjust result



#define ADCSRA				*((volatile u8*)0x26)		//ADC control and status register A
/* ADCSRA Bits   */
#define ADCSRA_ADEN			7							//ADC enable
#define ADCSRA_ADSC			6                           //Start conversion
#define ADCSRA_ADATE		    5                           //Auto trigger enable
#define ADCSRA_ADIF			4                           //Interrupt flag
#define ADCSRA_ADIE			3                           //Interrupt enable
#define ADCSRA_ADPS2		    2                           //Prescaler bit2
#define ADCSRA_ADPS1		    1                           //Prescaler bit1
#define ADCSRA_ADPS0		    0                           //Prescaler bit0


/* Data Reg  */
#define ADCH				*((volatile u8*)0x25)		//ADC high register
#define ADCL				*((volatile u8*)0x24)		//ADC Low register
#define ADC_DATA_RE 		*((volatile u16*)0x24)		//ADC Low + High


#define SFIOR  *((volatile u8 *)0x50)
/* SFIOR Bits   */
#define SFIOR_ADTS2			7                          //Trigger Source bit2
#define SFIOR_ADTS1	     	6                          //Trigger Source bit1
#define SFIOR_ADTS0		    5                          //Trigger Source bit0


/* Values of the global var (ADC_u8ISRSource)  */
#define SINGLE_CHANNEL_ASYNCH 0
#define CHAIN_CHANNEL_ASYNCH  1

#endif /* _MCAL_5_ADC_ADC_PRIVATE_H_ */
