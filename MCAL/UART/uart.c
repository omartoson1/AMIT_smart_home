/*
 * uart.c
 *
 *  Created on: Sep 22, 2021
 *      Author: omartoson
 */


#include "uart.h"
// pin d0 input pind d1 output
void UART_init()
{
	UCSRA |=0x00;//
	UCSRB |=(1<<RXEN)|(1<<TXEN);// enable
	UCSRC |=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);// 8 bit data mode
	UBRRL= 103;// baud rate, 9600 @ 16MHz , 0.2% error
}
void UART_sendbyte(uint8 data)
{
	while (!(UCSRA&(1<<UDRE)))
	{
	}

	UDR=data;
}
uint8 UART_recievebyte()
{
	while (!(UCSRA&(1<<RXC)))
	{
	}
	return UDR;
}
