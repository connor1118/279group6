
#include <avr/io.h>
#include <avr/interrupt.h>
#include "USART0.h"
#include "main.h"

void UART_out(uint8_t ch)
{
	
	while((UCSR0A & (1<< UDRE0)) == 0)
	{	
	}
	UDR0 = ch;
}


void Init_UART(void)
{
	UCSR0A = 0x00;
	UBRR0H = 0x00;
	UBRR0L = myubr;
	UCSR0B = (1<<TXEN0)|(1<<RXEN0)|(1<<RXCIE0);  //initialize with the interrupt bit enabled
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}

//ISR(USART0_RX_vect)
//{
//	rx_char = UDR0;
//	}

ISR(USART0_RX_vect){
	uint8_t rx_char = UDR0;
	if(rx_char == 0x0D)  //if the enter button is pushed, execute code inside
	{
		rx_buffer[array_index] = '\0';  //end the line and reset index value to zero, and update boolean to 1
		array_index = 0;
		LCD_update = 1;
	}else if(rx_char == 0x0A){  //does nothing if it is the next line
		
	}else{
		rx_buffer[array_index] = rx_char;  //otherwise add the current value of the UDR0 to the rx_buffer and increment the index
		array_index++;
		
}
	}
	
	
	void UART_outstring(char ch[])
	{
		uint8_t i = 0;
		while(ch[i])
		{
			UART_out(ch[i]);
			i++;
		}
		UART_out(0x0D);
	}