#!/bin/bash

avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o bamPWM.elf 74HC595.c bamPWM.c 
avr-objcopy -O ihex -R .eeprom bamPWM.elf bamPWM.hex
avrdude -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:bamPWM.hex:i



