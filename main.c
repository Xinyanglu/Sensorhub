#include "lcd/LCD_1602.h"
#include "i2c/i2c.h"
#include "sht31/sht31.h"
#include <stdio.h>

int main(void){
    uint16_t raw_temp, raw_hum;
    float temperature, humidity;
    LCD_1602 lcd = {.RS = 12, .EN = 11, .D4 = 10, .D5 = 9, .D6 = 8, .D7 = 7};
    LCD_1602_init(&lcd);
    TWI_init();

    while(1){
        SHT31_send_command(SHT31_READ);
        _delay_ms(20); 
        SHT31_read_data(&raw_temp, &raw_hum);

        temperature = SHT31_calculate_temperature(raw_temp);
        humidity = SHT31_calculate_humidity(raw_hum);

        char lcd_val[50];
        snprintf(lcd_val, sizeof(lcd_val), 
                "%d.%dC  %d.%d%%", 
                (int)(temperature), (int)(temperature*100 - (int)temperature * 100), 
                (int)humidity, (int)(humidity*100 - (int)humidity * 100));
        _delay_ms(100);
        LCD_1602_write_text(&lcd, lcd_val);
        _delay_ms(1000);
        LCD_1602_clear(&lcd);
    }
    return 0;
}