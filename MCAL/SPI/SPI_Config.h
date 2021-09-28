/*
 * SPI_Config.h
 *
 *  Created on: Sep 15, 2021
 *      Author: omartoson
 */
#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

//#define spi_data_order 0   //0=> transmit MSB first

typedef enum {
	msb_first,
	lsb_first
}spi_data_order;

typedef enum {
	sample_then_setup,
	setup_then_sample
}spi_clk_phase;

typedef enum {
	lead_with_rising,
	lead_with_falling
}spi_clk_polarity;

typedef enum {
	slave,
	master
}spi_operation;

typedef enum {
sys_clk_div4,
sys_clk_div16,
sys_clk_div64,
sys_clk_div128,
sys_clk_div2,
sys_clk_div8,
sys_clk_div32,
//sys_clk_div64
}spi_clk;

typedef struct spi_clk_config{
	spi_data_order spi_data_order;
	spi_clk_phase spi_clk_phase;
	spi_clk_polarity spi_clk_polarity;
	spi_operation spi_operation;
	spi_clk    spi_clk;
}spi_clk_config;

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
