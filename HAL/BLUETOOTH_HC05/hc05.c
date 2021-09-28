/*
 * hc05.c
 *
 *  Created on: Sep 22, 2021
 *      Author: omartoson
 */
#include "hc05.h"
/// to use hc05 >> connect the module's TX with pin PD0(RX) -> input pin
/// 		   and connect the module's RX with pin PD1(TX) -> output pin
void bluetooth_init(){
	UART_init();
}

void bluetooth_send(uint8 message){
	UART_sendbyte(message);

}

uint8 bluetooth_receive(){
	return (UART_recievebyte());

}
