#ifndef I2C_H

#define I2C_H

#include <avr/io.h>
#include "../gpio/gpio.h"
#include "../lcd/LCD_1602.h"

#define F_CPU 16000000UL
#define WRITE 0
#define READ 1

void    TWI_init(void);
uint8_t TWI_start(void);
void    TWI_stop(void);
uint8_t TWI_transmit_address(uint8_t address, uint8_t read);
uint8_t TWI_write(uint8_t data);
void    TWI_read_ack(uint8_t* data);
void    TWI_read_nack(uint8_t* data);

#endif // I2C_H
