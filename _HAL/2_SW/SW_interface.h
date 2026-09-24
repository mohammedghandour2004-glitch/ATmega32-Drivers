/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SW_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: September 4, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _HAL
 * SWC   : SW
 */
#ifndef _HAL_2_SW_SW_INTERFACE_H_
#define _HAL_2_SW_SW_INTERFACE_H_

/* Switch return status:
 * 1 -> Switch is pressed
 * 0 -> Switch is not pressed
 */
#define SW_PRESSED     1
#define SW_NOT_PRESSED 0

/* Switch connection modes:
 * - Internal Pull-Up
 * - External Pull-Up
 * - External Pull-Down
 * - Floating input
 */
#define SW_Int_PULL_UP     0
#define SW_Ext_PULL_UP     1
#define SW_Ext_PULL_DOWN   2
#define SW_FLOATING        3


/* Switch configuration:
 * Port      -> MCU port connected to the switch
 * Pin       -> MCU pin connected to the switch
 * Pull_State-> Pull-up / Pull-down configuration
 */
typedef struct{

	u8 Port;
	u8 Pin ;
	u8 Pull_State;

}SW_Type;


/* Initialize the switch according to its configuration */
void SW_voidInit       ( SW_Type SW_Config );

/* Read the switch state and return PRESSED / NOT_PRESSED */
u8   SW_u8GetPressed   ( SW_Type SW_Config );

#endif /* _HAL_2_SW_SW_INTERFACE_H_ */
