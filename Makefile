MCU = atmega328p
F_CPU = 16000000UL
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall
CC = avr-gcc

SRC = main.c
OBJ = main.o gpio/gpio.o lcd/LCD_1602.o i2c/i2c.o sht31/sht31.o

TARGET = main.elf

all: $(TARGET) gpio lcd i2c sht31 main.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

flash:
	avr-objcopy -O ihex -R .eeprom $(TARGET) main.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex

clean:
	rm *.o *.bin *.hex *.elf
