/*
 * finalproject.c
 *
 * Created: 11/12/2021 10:35:24 PM
 * Author : megjd
 */ 

//test

#define F_CPU 16000000UL
#define PushButton (PINA & ( (1<<PA0) | (1<<PA1) | (1<<PA2) | (1<<PA3))) // push buttons 1-4
#define degree 90 //set amount of degrees you want motor to turn
#include <avr/io.h>
#include <util/delay.h>
#include "stepper_motor.h"
#include "ADC.h"
#include "USART0.h"
#include "main.h"

int main(void)
{
	io_init();
	init_ADC();
	Init_UART();
	sei();
	uint8_t n=1;
	uint8_t i = 0;
	
	uint8_t h= 2000;
	
	uint16_t value = 0;
	uint8_t locked = 1;
	
	char pass[20] = {"password"};
		
	char mode[40] = {"Configuration Enabled"};
	
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)

	ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).

	
	
	OCR1A = 250;
	OCR1B = 250;
	
	
	while(locked == 1){
		while(pass[i]){
			if(rx_buffer[i] == pass[i])
			{
				i++;
			}else{
				UART_outstring("try a different code");
			}
		}
		locked = 0;
	}
	while ((PINC & 0x01))
	{
		Stepper_Position('W',n);
	}
	Stepper_Position('F',h);
	
    while (1) 
    {
	
		switch (PushButton)
		{
			case Wave_Step:
			{
				while (PINA & Wave_Step)
				{
				Stepper_Position('W',n); //Wave rotation
				}

				break;
			}
			case Full_Step:
			{
				Stepper_Position('F',n); //Full rotation

				break;
			}

			
			case Position:
			{
				while ((PINC & 0x01))
				{
					Stepper_Position('W',n);
				}
				Stepper_Position('F',h);
				
				break;

			}
		}
		
		PORTK = 0x00; //clear output when done
		
		while (PINC & 0x02)
		{
			value = ten_bit_ADC(0);
			value = ((value*.5)+97);
			OCR1A = value;
		}
		
		while (PINC & 0x08)
		{
			value = ten_bit_ADC(0);
			value = ((value*.5)+97);
			OCR1B = value;
		}
		
		
		
		
	}
}

void io_init(void)

{

	DDRK = 0xFF; //set PORTK as output
	PORTK = 0x00; //turn off LED at initialization
	DDRA = 0x00; //set PORTA as input
	PORTA = 0xFF; //turn on pull-up resistors
	DDRC = 0x00;
	PORTC = 0xFF;
	DDRB = 0x60;   //PWM Pins as Out
}