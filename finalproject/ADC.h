/*
 * ADC.h
 * Gabriel Johnson
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/interrupt.h>
#include <avr/io.h>
void init_ADC(void);
volatile uint16_t adc_value;


#endif /* ADC_H_ */