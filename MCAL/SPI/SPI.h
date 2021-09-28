/*
 * SPI.h
 *
 *  Created on: Aug 21, 2021
 *      Author: omar
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include "SPI_Config.h"
#include "../../BIT_MATH.h"
#include "../../STD_Types.h"
//void SPI_Init(void);
void SPI_Send_Byte(char data);
char SPI_Receive_Byte(void);
void SPI_Send_String(char *Str);
void SPI_Receive_String(char *Str);
void spi_set_isr_p2f(void (*CallBack_P2F)(void));


void SPI_SlaveInit(void);
void SPI_MasterInit(void);


#endif /* MCAL_SPI_SPI_H_ */
