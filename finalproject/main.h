#ifndef MAIN_H_
#define MAIN_H_
#include "LCD.h"
#include <avr/interrupt.h>
//volatile global variables
volatile char rx_buffer[25];  //stores the string to be displayed on the LCD
volatile uint8_t rx_char;    //stores value of UDR0
volatile uint8_t LCD_update; //boolean to differentiate functions
volatile uint8_t array_index;  //keeps track of place in rx_buffer



#endif /* MAIN_H_ */