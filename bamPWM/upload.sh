#!/bin/bash

SOURCE_FILES="74HC595.c bamPWM.c"
OUTPUT_ELF="bamPWM.elf"
OUT_HEX="bamPWM.hex"
MCU="atmega328p"
F_CPU="16000000UL"
PORT="/dev/ACMUSB0"
BAUD="115200"

avr-gcc -mmcu=$MCU -DF_CPU=$F_CPU -Os -o $OUTPUT_ELF $SOURCE_FILES
avr-objcopy -O ihex -R .eeprom $OUTPUT_ELF $OUTPUT_HEX
avrdude -v -p$MCU -carduino -P$PORT -b$BAUD -D -Uflash:w:$OUTPUT_HEX:i

