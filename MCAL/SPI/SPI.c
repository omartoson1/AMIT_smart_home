/*
 * SPI.c
 *
 *  Created on: Aug 21, 2021
 *      Author: omar
 */
#include "SPI.h"

//spi_clk_config spi = {msb_first,sample_then_setup,lead_with_rising,master,sys_clk_div16};
void (*spi_byte_received)(void);
ISR(SPI_STC_vect){
	spi_byte_received();
}
void spi_set_isr_p2f(void (*CallBack_P2F)(void)){
	SPCR = (1<<SPIE);
	spi_byte_received = CallBack_P2F;
}
/*
void SPI_Init(void){

	SET_BIT(SPCR,6);

if (spi.spi_operation == master){
	SET_BIT(SPCR,4);
}else if (spi.spi_operation == slave){
	CLEAR_BIT(SPCR,4);
}

if (spi.spi_data_order == lsb_first){
	SET_BIT(SPCR,5);
}else {
	CLEAR_BIT(SPCR,5);
}

if (spi.spi_clk_polarity == lead_with_falling){
	SET_BIT(SPCR,3);
}else {
	CLEAR_BIT(SPCR,3);
}

if (spi.spi_clk_phase == setup_then_sample){
	SET_BIT(SPCR,2);
}else {
	CLEAR_BIT(SPCR,2);
}

if (spi.spi_clk == sys_clk_div4){
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	CLEAR_BIT(SPSR,0);
} else if(spi.spi_clk == sys_clk_div16){
	SET_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	CLEAR_BIT(SPSR,0);
}
else if(spi.spi_clk == sys_clk_div128){
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	CLEAR_BIT(SPSR,0);
}
else if(spi.spi_clk == sys_clk_div2){
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	SET_BIT(SPSR,0);
}
else if(spi.spi_clk == sys_clk_div8){
	SET_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	SET_BIT(SPSR,0);
}
else if(spi.spi_clk == sys_clk_div32){
	CLEAR_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	SET_BIT(SPSR,0);
}
else if(spi.spi_clk == sys_clk_div64){
	CLEAR_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	CLEAR_BIT(SPSR,0);
}
}

*/







void SPI_SlaveInit(void) {
  SPCR = (1<<SPE);
}

void SPI_MasterInit(void) {
  SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}




void SPI_Send_Byte(char data)
{
/* Start transmission */
SPDR = data;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)));
}

char SPI_Receive_Byte(void) {
while(!(SPSR & (1<<SPIF)));
return SPDR;
}

void SPI_Send_String(char *Str)
{
	uint8 count = 0;
	while(Str[count] != '\0')
	{
		SPI_Send_Byte(Str[count]);
		count++;
	}
}

void SPI_Receive_String(char *Str)
{
	uint8 count = 0;
	Str[count] = SPI_Receive_Byte();
	while(Str[count] != '#')
	{
		count++;
		Str[count] = SPI_Receive_Byte();
	}
	Str[count] = '\0';
}








