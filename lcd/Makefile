MCU = atmega328p
F_CPU = 16000000UL
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

SRC = LCD_1602.c
OBJ = LCD_1602.o

all: $(OBJ)

$(OBJ): $(SRC)
	avr-gcc $(CFLAGS) -c $(SRC) -o $(OBJ)

clean: 
	rm $(OBJ)
