#include <avr/io.h>

#define A0 -6
#define A1 -5
#define A2 -4
#define A3 -3
#define A4 -2
#define A5 -1

#define OUTPUT 1
#define INPUT 0

void set_pin_mode(int arduinoPin, unsigned char mode);
void set_pin(int arduinoPin, unsigned char value);
