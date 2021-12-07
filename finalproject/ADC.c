/*
 * ADC.c
 * Gabriel Johnson
 */ 

#include <avr/io.h>
#include "ADC.h"


void init_ADC(void)
{
	DDRF = 0x00; //set PORTF as input
	PORTF = 0xFC; //turn on pull-up resistors
	ADCSRA = (1<< ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //enable ADC and set prescaler
}

uint16_t ten_bit_ADC(uint8_t channel)
{
	uint16_t result; //store ADC value
	
	ADMUX = (ADMUX & 0xE0) | channel; // clear ADMUX and select channel
	ADMUX |= (1<< REFS0) | (1<<ADLAR); //set to VCC
	ADCSRA |= (1<< ADSC); //begin conversion
	
	while((ADCSRA & (1<<ADIF))==0) //wait for conversion to end
	{
		
	}
	
	result = ADCH; //store value and freeze ADCH register
	//result |= (ADCH<<8); //store value
	ADCSRA |= (1<<ADIF); //clear interrupt flag
	
	return result; // return result
}