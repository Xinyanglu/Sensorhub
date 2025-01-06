#include <avr/io.h>
#include "../gpio/gpio.h"
#include "../i2c/i2c.h"

#define SHT31_ADDR (0x44)
#define SHT31_READ (0x2400)

void SHT31_send_command(uint16_t command);
void SHT31_read_data(uint16_t* temperature, uint16_t* humidity);
float SHT31_calculate_temperature(uint16_t raw_value);
float SHT31_calculate_humidity(uint16_t raw_value);
uint8_t SHT31_crc8(const uint8_t *data, int length);