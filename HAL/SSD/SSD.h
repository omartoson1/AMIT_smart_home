/*
 * SSD.h
 *
 *  Created on: Aug 22, 2021
 *      Author: omar
 */

#ifndef HAL_SSD_SSD_H_
#define HAL_SSD_SSD_H_
#include <avr/io.h>
#include <util/delay.h>
#include "../../BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"

void ssd_same(uint8 cmd);
void ssd_different(uint8 cmd1, uint8 cmd2);
#endif /* HAL_SSD_SSD_H_ */
