/*
 * main.c
 *
 *  Created on: Jul 17, 2021
 *      Author: omar
 */
#define F_CPU 16000000UL
#include <avr/io.h>
#include "BIT_MATH.h"
#include "MCAL/DIO/DIO.h"
#include <util/delay.h>
#include "MCAL/SPI/SPI.h"
#include "MCAL/UART/uart.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/Timer/TIMER.h"
#include "HAL/SSD/SSD.h"
#include "HAL/BLUETOOTH_HC05/hc05.h"

int main(){
	Dio_init();
	/// master
/*
	bluetooth_init();
	lcd_init();
	SPI_MasterInit();
	uint8 temp=0;
	while(1){
		temp = bluetooth_receive();
		lcd_char(temp);
		SPI_Send_Byte(temp);
		_delay_ms(1000);
	}
*/
	/// slave

	bluetooth_init();
	lcd_init();
	lcd_clear();
	SPI_SlaveInit();
	uint8 count=0,command =0;
	while(1){
		command = SPI_Receive_Byte();
		lcd_char(command);
		count ++;
		
		switch (command){
		case 'a':
			CLEAR_BIT(PORTC,2);
		break;
		case 'b':
			CLEAR_BIT(PORTC,7);
		break;
		case 'c':
			CLEAR_BIT(PORTD,3);
		break;
		case 'd':
			CLEAR_BIT(PORTA,3);
		break;
		case 'A':
			SET_BIT(PORTC,2);
		break;
		case 'B':
			SET_BIT(PORTC,7);
		break;
		case 'C':
			SET_BIT(PORTD,3);
		break;
		case 'D':
			SET_BIT(PORTA,3);
		break;

			//
		}

		if (count>10){
			lcd_clear();
		}

	}
}

