/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created on: August 9, 2026
 * Author: MOHAMMED GHANDOUR
 * Layer : _MCAL
 * SWC   : DIO/GPIO
 */

#ifndef MCAL_01_DIO_DIO_INTERFACE_H_
#define MCAL_01_DIO_DIO_INTERFACE_H_

// it should be before function data type
// in darija morocco hadi khasha tkon 9bl l function data type
typedef enum
{
	DIO_NOK,
	DIO_OK
}DIO_ErrorStatus;

// PIN Directions
#define DIO_PIN_OUTPUT  1
#define DIO_PIN_INPUT   0
// PIN Value Options || KHAS B PIN
#define DIO_PIN_HIGH    1
#define DIO_PIN_LOW	    0

// PORT Directions
#define DIO_PORT_OUTPUT 0XFF
#define DIO_PORT_INPUT  0x00
// PORT Value Options || KHAS B PORT
#define DIO_PORT_HIGH   0XFF
#define DIO_PORT_LOW    0x00

// Port Defines || KHAS B PORT
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

// PIN Defines || HADO L PINS DYAL KOL PORT
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

//Pull UP
#define PUD   2


//************IO PIN***************
DIO_ErrorStatus DIO_EnumSetPinDirection (
	u8 Copy_u8PORT,
	u8 Copy_u8PIN,
	u8 Copy_u8Direction
);
DIO_ErrorStatus DIO_EnumSetPinValue     (
	u8 Copy_u8PORT,
	u8 Copy_u8PIN,
	u8 Copy_u8Value
);
DIO_ErrorStatus   DIO_EnumGetPinValue   (
		u8 Copy_u8PORT,
		u8 Copy_u8PIN,
		u8 * Copy_PtrData
);
DIO_ErrorStatus DIO_EnumTogglePinValue  (
		u8 Copy_u8PORT,
		u8 Copy_u8PIN
);



//************IO PORTS***************
DIO_ErrorStatus DIO_EnumSetPortDirection (
	u8 Copy_u8PORT,
	u8 Copy_u8Direction
);
DIO_ErrorStatus DIO_EnumSetPortValue     (
	u8 Copy_u8PORT,
	u8 Copy_u8Value
);
DIO_ErrorStatus   DIO_EnumGetPortValue   (
		u8 Copy_u8PORT,
		u8 * Copy_PtrData
);
DIO_ErrorStatus DIO_EnumTogglePortValue(
        u8 Copy_u8PORT
);

//************Internal Pull Up***************
DIO_ErrorStatus DIO_EnumConnectPullup        (u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup );

// *************** IO Nibbles ***************
DIO_ErrorStatus DIO_VoidWriteHighNibbles (u8 Copy_u8PORT,u8 value);
DIO_ErrorStatus DIO_VoidWriteLowNibbles  (u8 Copy_u8PORT,u8 value);



#endif /* MCAL_01_DIO_DIO_INTERFACE_H_ */
