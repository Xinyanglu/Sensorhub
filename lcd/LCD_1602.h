#include <avr/io.h>
#include <util/delay.h>
#include "../gpio/gpio.h"

typedef struct {
	unsigned char D4;
	unsigned char D5;
	unsigned char D6;
	unsigned char D7;
	unsigned char EN;
	unsigned char RS;
} LCD_1602;

void LCD_1602_init(LCD_1602* lcd);
void LCD_1602_send_nibble( LCD_1602* lcd, unsigned char data);
void LCD_1602_send_command( LCD_1602* lcd, unsigned char cmd);
void LCD_1602_write_text(LCD_1602* lcd, char* text);

void LCD_1602_clear(LCD_1602* lcd);