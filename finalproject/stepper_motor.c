
#include "stepper_motor.h"

//patterns fro different types of steps
uint8_t Wave[4] = {0x01,0x02,0x04,0x08};
uint8_t Iwave[4] = {0x08,0x04,0x02,0x01};
uint8_t Half[8] = {0x09,0x01,0x03,0x02,0x06,0x04,0x0C,0x08};

void Stepper_Drive(char mode, uint8_t revolutions)
{
	uint16_t steps;
	
	switch (mode)
	{
		case 'W':
			{
				
				steps = 2048*revolutions/4; // steps equal to 1 full rotation
			
				for(uint16_t i=0;i<steps;i++)
				{
					for(uint16_t j=0; j<4; j++)
					{
						PORTK = Wave[j]; //runs step pattern
						_delay_ms(6);
					}
				}
			
		break;
			}
		
		case 'F':
			{
				
				steps = 2048*revolutions/4;	// steps equal to 1 full rotation
				
				for(uint16_t i=0;i<steps;i++)
				{
					for(uint16_t j=0; j<4; j++)
					{
						PORTK = Iwave[j]; //runs step pattern
						_delay_ms(6);
					}
				}
				break;
			}
		

	}
}
void Stepper_Position(char mode, uint16_t degrees )
{
	uint16_t steps;
	
	switch (mode)
	{
		case 'W':
		{
			
			steps = degrees*6/4; //calculate number of steps for needed degrees
			
			for(uint16_t i=0;i<steps;i++)
			{
				for(uint16_t j=0; j<4; j++)
				{
					PORTK = Wave[j]; //runs step pattern
					_delay_ms(6);
				}
			}
			
			break;
		}
		
		case 'F':
		{
			
			steps = degrees*6/4; //calculate number of steps for needed degrees
			
			for(uint16_t i=0;i<steps;i++)
			{
				for(uint16_t j=0; j<4; j++)
				{
					PORTK = Iwave[j]; //runs step pattern
					_delay_ms(6);
				}
			}
			break;
		}
		
	}
}
