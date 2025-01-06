MCU = atmega328p
F_CPU = 16000000UL
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

SRC = sht31.c
OBJ = sht31.o

all: $(OBJ)

$(OBJ): $(SRC)
	avr-gcc $(CFLAGS) -c $(SRC) -o $(OBJ)

clean: 
	rm $(OBJ)
