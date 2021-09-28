# AMIT_smart_home
Smart Home Project Report

Prepared by: Omar Mohamed Omar Toson 
Date: 22/9/2021

The project aim is two create a working prototype for a smart home system

Wireless communication: 
The project uses an HC05 bluetooth module to allow wireless communication between the a mobile phone and the hardware

Tethered communication:
The project makes use of both SPI and UART protocol. The SPI is used to communicate between the Master and all the other slave(s). the UART is necessary to communicate betweent the Master and the Bluetooth module. 

Master µc: [ATMEGA32]
In theroy, the master microcontroller is the only point of contact between the user and the entire smart home system. The master microcontroller is responsible for passing the commands received by the bluetooth module to the slave(s) microcontrollers to apply these commands.


Slave(s) µc: [ATMEGA32]

The slave(s) microcontrollers are responsible for taking the commands from the master (through the SPI protocol). Commands that can be performed by slave(s) include, printing data on an LCD dispaly [string, char, int in different spaces on the LCD display], controlling a 2-digits Seven Segment dispaly, conttolling lights and motors through the PMW timer mode.... 


************ Important Note ************

the code contains both the slave and master µc codes, thus, 
1- the DIO_Config.c file needs to be manually changed to adjust the pin direction for the SPI pins to choose the slave or master codes 
2- same needs to be done in the main

************ A Video showing the prototype ************

Google Drive :  https://drive.google.com/drive/folders/1iHzdWWelUCMZuMYpL3mNmT8Hl8zCGnj6?usp=sharing











