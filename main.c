#include "lcd/LCD_1602.h"

LCD_1602 lcd = {.RS = 12, .EN = 11, .D4 = 10, .D5 = 9, .D6 = 8, .D7 = 7};

int main(void){
    LCD_1602_init(&lcd);
    LCD_1602_write_text(&lcd, "Hello, World!");
    while(1){
        _delay_ms(1000);
        LCD_1602_send_command(0x01, &lcd);
        _delay_ms(1000);
        LCD_1602_write_text(&lcd, "Hello, World!");

    }
    return 0;
}