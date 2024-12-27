#include "LCD_1602.h"

// https://www.waveshare.com/datasheet/LCD_en_PDF/LCD1602.pdf
// LCD_1602 lcd{.RS = 12, .EN = 11, .D4 = 10, .D5 = 9, .D6 = 8, .D7 = 7};

void LCD_1602_init(LCD_1602* lcd){
	set_pin_mode(lcd->RS, 1);
	set_pin_mode(lcd->EN, 1);
	set_pin_mode(lcd->D4, 1);
	set_pin_mode(lcd->D5, 1);
	set_pin_mode(lcd->D6, 1);
	set_pin_mode(lcd->D7, 1);

	_delay_ms(20);

	set_pin(lcd->RS, 0);
	//intiailize sequence
	LCD_1602_send_nibble(lcd, 0x03);
	_delay_ms(5);
	LCD_1602_send_nibble(lcd, 0x03);

	LCD_1602_send_nibble(lcd, 0x03);
	LCD_1602_send_nibble(lcd, 0x02);

	// 2 lines and 5x7 matrix
	LCD_1602_send_command(lcd, 0x28);

	// turn on display, blink off, cursor off
	LCD_1602_send_command(lcd, 0x0C);

	//clear display
	LCD_1602_send_command(lcd, 0x01);
	_delay_ms(2);

	// move cursor right
	LCD_1602_send_command(lcd, 0x06);

}

void LCD_1602_clear(LCD_1602* lcd){
	LCD_1602_send_command(lcd, 0x01);
}

void LCD_1602_write_text(LCD_1602* lcd, char* text){
	set_pin(lcd->RS, 1);
	while(*text){
		LCD_1602_send_nibble(lcd, *text >> 4);
		LCD_1602_send_nibble(lcd, *text);
		text++;
	}
}

void LCD_1602_send_command(LCD_1602* lcd, unsigned char cmd){
	set_pin(lcd->RS, 0);
	LCD_1602_send_nibble(lcd, cmd >> 4);
	LCD_1602_send_nibble(lcd, cmd);
}

void LCD_1602_send_nibble(LCD_1602* lcd, unsigned char data){
	set_pin(lcd->D4, (data >> 0) & 0x01);
    set_pin(lcd->D5, (data >> 1) & 0x01);
    set_pin(lcd->D6, (data >> 2) & 0x01);
    set_pin(lcd->D7, (data >> 3) & 0x01);

	set_pin(lcd->EN, 1);
	_delay_us(1);
	set_pin(lcd->EN, 0);
	_delay_us(50);
}