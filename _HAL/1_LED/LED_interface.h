/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: August 13, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _HAL
 * SWC   : LED
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

// LED's PORTS
#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3

// LED'S PINS
#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7

#define ACTIVE_HIGH 1
#define ACTIVE_LOW 0

/* New data type called LED_Type has three infos (port & pin & active state)
 * منظم أكثر Driver وهذا كيخلي  */
typedef struct
{
	u8 Port;
	u8 Pin;
	u8 Active_State;
}LED_Type;


// LED FUNCTIONS
void LED_VoidInit        ( LED_Type LED_Configuration );
void LED_VoidOn          ( LED_Type LED_Configuration );
void LED_VoidOff         ( LED_Type LED_Configuration );
void LED_VoidToggle      ( LED_Type LED_Configuration );


#endif /* HAL_LED_LED_INTERFACE_H_ */
