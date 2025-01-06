#include "sht31.h"

void SHT31_send_command(uint16_t command) {
    uint8_t command_bytes[2];
    command_bytes[0] = (command >> 8) & 0xFF;
    command_bytes[1] = command & 0xFF;
    TWI_start();
    TWI_transmit_address(SHT31_ADDR, WRITE); // Write mode
    TWI_write(command_bytes[0]);
    TWI_write(command_bytes[1]);
    TWI_stop();
}

void SHT31_read_data(uint16_t* temperature, uint16_t* humidity) {
    TWI_start();
    TWI_transmit_address(SHT31_ADDR, READ); // Read mode

    uint8_t temperature_bytes[2];
    TWI_read_ack(&temperature_bytes[0]); // First byte temperature
    TWI_read_ack(&temperature_bytes[1]); // Last byte temperature

    *temperature = temperature_bytes[0] << 8 | temperature_bytes[1];

    TWI_read_ack(0); // temperature crc

    uint8_t humidity_bytes[2];
    TWI_read_ack(&humidity_bytes[0]); // First byte humidity
    TWI_read_ack(&humidity_bytes[1]); // Last byte humidity

    *humidity = humidity_bytes[0] << 8 | humidity_bytes[1];

    TWI_read_nack(0); // humidity crc

    TWI_stop();
}

float SHT31_calculate_temperature(uint16_t raw_value) {
    return -45 + 175.0 * ((float)raw_value / 65535); //celsius
}

float SHT31_calculate_humidity(uint16_t raw_value) {
    return 100.0 * ((float)raw_value / 65535); //percentage
}
