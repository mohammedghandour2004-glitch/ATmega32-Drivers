# ATmega32 Drivers

A collection of **MCAL and HAL drivers** developed for the **ATmega32 microcontroller** using Embedded C.

## 📁 Project Structure

```text
ATmega32-Drivers/
│
├── _LIB/       → Common libraries
│   ├──BIT_MATH.h
│   └──STD_TYPES.h
│ 
├── _MCAL/      → Microcontroller Abstraction Layer
│   ├── PORT
│   ├── DIO
│   ├── EXTI
│   ├── GIE
│   ├── ADC
│   ├── TIMER
│   ├── ICU
│   ├── WDT
│   ├── USART
│   ├── SPI
│   └── TWI
│
└── _HAL/       → Hardware Abstraction Layer
    ├── LED
    ├── SW
    ├── BUZ
    ├── SSD
    ├── CLCD
    ├── KPD
    └── LM35
```

## ⚙️ Technologies

- **Microcontroller:** ATmega32
- **Language:** Embedded C
- **Compiler:** avr-gcc
- **IDE:** Eclipse
- **Architecture:** MCAL / HAL

## 🎯 Purpose

This repository contains drivers developed as part of my learning and practice in **Embedded Systems**, with a focus on reusable and modular firmware development.

## 📌 Status

The driver library is being developed and improved as I continue learning Embedded Systems and AVR programming.

## 👨‍💻 Author

**Mohammed Ghandour**

GitHub: `mohammedghandour2004-glitch`
