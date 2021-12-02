/*
	Operations: This is the header for file for the stepper_motor.c file.
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_
#define F_CPU 16000000UL


#include <avr/io.h>
#include <util/delay.h>

void Stepper_Drive(char mode, uint8_t revolutions);

void Stepper_init(void);

void Stepper_Position(char mode,uint16_t degrees);

//macros for button inputs
#define Wave_Step	0x01
#define Full_Step	0x02
#define Half_Step	0x04
#define Position	0x08

#define stepper_output	(PORTK)

//external variables
extern uint8_t Wave[4];
extern uint8_t Full[4];
extern uint8_t Half[8];




#endif /* STEPPER_MOTOR_H_ */