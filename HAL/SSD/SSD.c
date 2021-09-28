/*
 * SSD.c
 *
 *  Created on: Aug 22, 2021
 *      Author: omar
 */
#include "SSD.h"

void ssd_same(uint8 cmd){
	SET_BIT(PORTB,1);// enable SSD1
	SET_BIT(PORTB,2);// enable SSD2
	SET_BIT(PORTB,3);// enable decimal point

	if (GET_BIT(cmd,0)){
		SET_BIT(PORTA,4);
	}else {
		CLEAR_BIT(PORTA,4);
	}

	if (GET_BIT(cmd,1)){
		SET_BIT(PORTA,5);
	}else {
		CLEAR_BIT(PORTA,5);
	}

	if (GET_BIT(cmd,2)){
		SET_BIT(PORTA,6);
	}else {
		CLEAR_BIT(PORTA,6);
	}

	if (GET_BIT(cmd,3)){
		SET_BIT(PORTA,7);
	}else {
		CLEAR_BIT(PORTA,7);
	}

}


void ssd_different(uint8 cmd1, uint8 cmd2){
	SET_BIT(PORTB,1);// enable SSD1
	CLEAR_BIT(PORTB,2);// disable SSD2
	//SET_BIT(PORTB,3);// enable decimal point

	if (GET_BIT(cmd1,0)){
		SET_BIT(PORTA,4);
	}else {
		CLEAR_BIT(PORTA,4);
	}

	if (GET_BIT(cmd1,1)){
		SET_BIT(PORTA,5);
	}else {
		CLEAR_BIT(PORTA,5);
	}

	if (GET_BIT(cmd1,2)){
		SET_BIT(PORTA,6);
	}else {
		CLEAR_BIT(PORTA,6);
	}

	if (GET_BIT(cmd1,3)){
		SET_BIT(PORTA,7);
	}else {
		CLEAR_BIT(PORTA,7);
	}
	_delay_ms(5);
	CLEAR_BIT(PORTB,1);// disable SSD1
	SET_BIT(PORTB,2);// enable SSD2

	if (GET_BIT(cmd2,0)){
		SET_BIT(PORTA,4);
	}else {
		CLEAR_BIT(PORTA,4);
	}

	if (GET_BIT(cmd2,1)){
		SET_BIT(PORTA,5);
	}else {
		CLEAR_BIT(PORTA,5);
	}

	if (GET_BIT(cmd2,2)){
		SET_BIT(PORTA,6);
	}else {
		CLEAR_BIT(PORTA,6);
	}

	if (GET_BIT(cmd2,3)){
		SET_BIT(PORTA,7);
	}else {
		CLEAR_BIT(PORTA,7);
	}
	_delay_ms(5);
}
