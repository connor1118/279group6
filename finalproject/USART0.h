#ifndef USART0_H_
#define USART0_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//function prototypes
void UART_out(uint8_t ch);
uint8_t UART_in(void);
void Init_UART(void);

#define Baud 9600
#define myubr ((F_CPU / (Baud * 16UL)) - 1)  //define ubr based on formula

#endif /* USART0_H_ */