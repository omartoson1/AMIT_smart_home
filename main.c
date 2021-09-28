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

//uint8 x = 0;
//uint8 y =0;

		//while(1){
			//ssd_same(x);
			/*ssd_different(x,y);
			if(x>8){
				x=0;
				if(y>8){
					y=0;
				}else {
				y++;}

			}else {
				x++;
			}
			_delay_ms(50);
			lcd_init();

		}*/

	//lcd_clear();
	//lcd_str("MENNA");
	//lcd_clear();
	//lcd_str_xy(0,1,"011877");

	Dio_init();
	///////////HC05_TEST+SPI//////////
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
// A,a (1,0) -> control led0
// B,b (1,0) -> control led1
// C,c (1,0) -> control led2
// D,d (1,0) -> control buzzer

	/////////////HC05_TEST////////////
	/*
	bluetooth_init();
	lcd_init();
	while (1){
	lcd_char(bluetooth_receive());
	_delay_ms(1000);
	}
*/

	////////////SPI_TEST/////////////
/*
// master
	SPI_MasterInit();
	char str[]="way2sexy";
	int y=0;
while(1){
	_delay_ms(1000);
	SPI_Send_Byte(str[y]);
	y++;
	if(y==8){
		y=0;
	}
}

// slave
	void (*spi_p2f)(void);
	lcd_init();
	SPI_SlaveInit();
	spi_p2f = &lcd_char;
	spi_set_isr_p2f((*spi_p2f));
	//lcd_clear();
	//char data;
	int x=0;
	while(1){
		x++;
		if(x==9){
		lcd_clear();
		x=0;
		}
		//lcd_char(SPI_Receive_Byte());
	}

*/



/*



	SPI_MasterInit();
	while(1){
	SPI_MasterTransmit(0x08);
	_delay_ms(1);

	}
	*/

	//setup();
/*
	SET_BIT(DDRB,3);
	SET_BIT(DDRD,7);

	timer0_init();
	//timer2_init(div_256,fast_pwm,clear);





	timer0_init();
	while(1){
		_delay_ms(5);
		if(OCR0>255){
			OCR0=0;
		} else{
		OCR0 ++;
		}
	}

*/

	//lcd_init();


	/*
	//SET_BIT(DDRD,3);
	PORT_Dir(27,1);
	//CLEAR_BIT(DDRD,2);
	PORT_Dir(26,0);

	//SET_BIT(DDRC,2);
	//SET_BIT(DDRC,7);

	PORT_Dir(18,1);
	PORT_Dir(23,1);

	while (1){
		DIO_Write(23,1);
		DIO_Write(27,0);
		_delay_ms(200);
		DIO_Write(27,1);
		DIO_Write(23,0);
		if(DIO_Read(26)==1){
			DIO_Write(18,1);
		}else {
			DIO_Write(18,0);

		}

		_delay_ms(200);
	}
	*/
/*
	uint8_t x = 0x00;

	SET_BIT(DDRD,3);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,7);


	SET_BIT(PORTD,3);
	CLEAR_BIT(PORTC,2);
	CLEAR_BIT(PORTC,7);

	SET_BIT(PORTD,2);
	while(!x){
		TOG_BIT(PORTD,3);
		TOG_BIT(PORTC,2);
		_delay_ms(500);
		TOG_BIT(PORTC,2);
		TOG_BIT(PORTC,7);
		_delay_ms(500);
		TOG_BIT(PORTC,7);

		x=GET_BIT(PIND,2);

		TOG_BIT(PORTD,3);
		_delay_ms(500);
	} */
	//
	/*
	setup();
	ssd_config();
	CLEAR_BIT(PORTB,3);

	SET_BIT(PORTB,1);// enable ssd1
	SET_BIT(PORTB,2);// enable ssd2

	while(1){
		ssd_rw();
	}

*/
	//SET_BIT(PORTA,4);
	//SET_BIT(PORTA,5);
	//SET_BIT(PORTA,6);
	//CLEAR_BIT(PORTA,7);



	//_delay_ms(20000);

	//DDRD |=(1<<3);
	//PORTD |= (1<<3);

	//DDRC |=(1<<2);
	//PORTC|= (1<<2);

	//DDRC |= (1<<7);
	//PORTC |= (1<<7);
	//DDRD |= (1<<4)|(1<<5);
	//DDRC |= (1<<3)|(1<<4)|(1<<5)|(1<<6);

	/*while(1){

		PORTD|= (1<<4)|(1<<5);

		PORTC &=~ (1<<4);
		PORTC &=~ (1<<6);

		PORTC |= (1<<3)|(1<<5);


	}*/
}

