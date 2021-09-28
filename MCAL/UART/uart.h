/*
 * uart.h
 *
 *  Created on: Sep 22, 2021
 *      Author: omartoson
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_
#include "../../BIT_MATH.h"
#include "../../STD_Types.h"
#include <avr/io.h>

void UART_init(void);
void UART_sendbyte(uint8 data);
uint8 UART_recievebyte(void);



#endif /* MCAL_UART_UART_H_ */































