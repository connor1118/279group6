/*
 * finalproject.c
 *
 * Created: 11/12/2021 10:35:24 PM
 * Author : megjd
 */ 

#define F_CPU 16000000UL
#define PushButton (PINA & ( (1<<PA0) | (1<<PA1) | (1<<PA2) | (1<<PA3))) // push buttons 1-4
#define degree 90 //set amount of degrees you want motor to turn
#include <avr/io.h>
#include <util/delay.h>
#include "stepper_motor.h"

int main(void)
{
	io_init();
	
	uint8_t n=1;

	
	while ((PINC & 0x01))
	{
		Stepper_Position('W',n);
	}
	
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

			}
		}
		PORTK = 0x00; //clear output when done
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

}