MCU = atmega328p
F_CPU = 16000000UL
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall
CC = avr-gcc

SRC = main.c
OBJ = main.o gpio/gpio.o lcd/LCD_1602.o

TARGET = main.elf

all: $(TARGET) gpio lcd main.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

gpio:
	$(MAKE) -C gpio CC=all"

lcd:
	$(MAKE) -C lcd CC=all"

flash:
	avr-objcopy -O ihex -R .eeprom $(TARGET) main.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex

clean:
	$(MAKE) -C gpio clean
	$(MAKE) -C lcd clean
	rm *.o *.bin *.hex *.elf
