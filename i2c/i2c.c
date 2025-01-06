#include "i2c.h"

void TWI_init(void){ 
    set_pin(A5, 1);
    set_pin(A4, 1);

    TWSR = 0xF8; // prescaler = 1
    TWBR = ((F_CPU / 100000UL) - 16) / 2; // 100khz bitrate
}

uint8_t TWI_start(void) {
    TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT); // Send START
    while (!(TWCR & (1 << TWINT))); // Wait for completion
    if((TWSR & 0xF8) != 0x08){
        return 1;
    }
    return 0;
}

void TWI_stop(void) {
    TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT); // Send STOP
}

uint8_t TWI_transmit_address(uint8_t address, uint8_t read) {
    if(read){
        TWDR = (address << 1) | 0x01; // Load address
    } else{
        TWDR = (address << 1) | 0x00; // Load address
    }
    TWCR = (1 << TWEN) | (1 << TWINT); // Start transmission
    while (!(TWCR & (1 << TWINT))); // Wait for completion

    if(read) {
        if((TWSR & 0xF8) != 0x40){
            TWI_stop();
            return 1;
        }
            
    } else {
        if((TWSR & 0xF8) != 0x18){
            TWI_stop();
            return 1;
        }
    }
    return 0;
}

uint8_t TWI_write(uint8_t data) {
    TWDR = data; // Load data
    TWCR = (1 << TWEN) | (1 << TWINT); // Start transmission
    while (!(TWCR & (1 << TWINT))); // Wait for completion
    if((TWSR & 0xF8) != 0x28){
        TWI_stop();
        return 1;
    }

    return 0;
}

void TWI_read_ack(uint8_t* data) {
    TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWINT); // Read with ACK
    while (!(TWCR & (1 << TWINT))); // Wait for completion
    if(data != 0){
        *data = TWDR;
    }
}

void TWI_read_nack(uint8_t* data) {
    TWCR = (1 << TWEN) | (1 << TWINT); // Read with NACK
    while (!(TWCR & (1 << TWINT))); // Wait for completion
    if(data != 0){
        *data = TWDR;
    }
}