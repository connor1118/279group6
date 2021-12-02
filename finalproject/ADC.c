/*
 * ADC.c
 * Gabriel Johnson
 */ 

#include <avr/io.h>
#include "ADC.h"


void init_ADC(void)
{
	DDRF = 0x00; //set PORTF as input
	PORTF = 0xFE; //turn on pull-up resistors
	ADCSRA = (1<< ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADIE); //enable ADC and set prescaler
	ADMUX |= (1<< REFS0); //set to VCC
	ADCSRA |= (1<< ADSC); //begin conversion
}

ISR(ADC_vect)
{
	adc_value = ADCL; //store value and freexe ADCH registor
	adc_value |= (ADCH<<8); //store value
	ADCSRA |= (1<<ADSC); //start conversion
}