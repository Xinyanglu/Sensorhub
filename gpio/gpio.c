#include <avr/io.h>
#include "gpio.h"

void set_pin_mode(int arduinoPin, unsigned char mode){
	if (arduinoPin <= 13 && arduinoPin >= 8){
		if (mode)
			DDRB = DDRB | (1 << (arduinoPin - 8));
		else
			DDRB = DDRB & ~(1 << (arduinoPin - 8));
	}
	else if (arduinoPin <= 7 && arduinoPin >= 2){
	       if (mode)
		       DDRD = DDRD | (1 << (arduinoPin));
	       else
		       DDRD = DDRD & ~(1 << (arduinoPin));
	}
	else if(arduinoPin <= A5 && arduinoPin >= A0){
		if (mode)
			DDRC = DDRC | (1 << (arduinoPin + 6));
		else
			DDRC = DDRC & ~(1 << (arduinoPin + 6));
	}
}

void set_pin(int arduinoPin, unsigned char value){
	if(arduinoPin <= 13 && arduinoPin >= 8){
		if(value)
			PORTB = PORTB | (1 << (arduinoPin - 8));
		else
			PORTB = PORTB & ~(1 << (arduinoPin - 8));
	}
	else if(arduinoPin <= 7 && arduinoPin >= 2){
		if(value)
			PORTD = PORTD | (1 << (arduinoPin));
		else
			PORTD = PORTD & ~(1 << (arduinoPin));
	}
	else if(arduinoPin <= A5 && arduinoPin >= A0){
		if (value)
			PORTC = PORTC | (1 << (arduinoPin + 6));
		else
			PORTC = PORTC & ~(1 << (arduinoPin + 6));
	}
}