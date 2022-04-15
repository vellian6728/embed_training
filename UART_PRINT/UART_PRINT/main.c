/*
 * UART_PRINT.c
 *
 * Created: 13-04-2022 14:31:32
 * Author : Guganathan J
 */ 


#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>
#include "config.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart_hal.h"

int main(void)
{
	char buffer1[20];
	char buffer2[20];
	long Lval1 = 1234567890;
	uint16_t Temp1 = 35;
	itoa(Temp1,buffer1,10);
	ltoa(Lval1,buffer2,10);

	
	
	flush_uart_buffer();
	//uart_init(1000000,1); // 1Mbps - double speed not working in putty - xxxxxxxxxxxxxxxxxxxxxxxxxx
	uart_init(500000,1); // 0.5 Mbps - double speed - working - High speed 0.5 * 2 = 1Mbps - 400 times fasster than the available low speed.
	//uart_init(2400,0); //2.4Kbps - single speed - working - Lowest speed
	//uart_init(9600,0); //9.6Kbps - single speed - working
	//uart_init(19200,1); //19.2Kbps - double speed  - working

	sei();
	uart_send_string_char("Program Start ...\n\r");
	while(1)
	{
		
	uart_send_string_char("Temperature = ");
	uart_send_string_char(buffer1);
	uart_send_string_char("\n\r");
	
	uart_send_string_char("Long value = ");
	uart_send_string_char(buffer2);	
	uart_send_string_char("\n\r");
	_delay_ms(1000);
	uart_send_string_char("\n\r");
	uart_send_string_char("\n\r");
	}
	

	flush_uart_buffer();
}