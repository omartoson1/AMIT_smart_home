/*
 * hc05.h
 *
 *  Created on: Sep 22, 2021
 *      Author: omartoson
 */

#ifndef HAL_BLUETOOTH_HC05_HC05_H_
#define HAL_BLUETOOTH_HC05_HC05_H_
#include "../../MCAL/UART/uart.h"
void bluetooth_init(void);
void bluetooth_send(uint8 message);
uint8 bluetooth_receive(void);

#endif /* HAL_BLUETOOTH_HC05_HC05_H_ */
