#include "74HC595.h"

void clearR() {
	// Clear the shift register
	PORTD |= (1 << SRCLR);
	PORTD &= ~(1 << SRCLR);
}

void loadR() {
	//Load SR data to R
	PORTD &= ~(1 << RCLK);
	PORTD |= (1 << RCLK);
}

void loadValue(int temp) {
	int b;
	for (int i = 0; i < 8; i++) {
		b = temp & 1;
		if (b) {
			PORTD |= (1 << SER);
		} else {
			PORTD &= ~(1 << SER);
		}
		temp = temp >> 1;
		PORTD &= ~(1 << SRCLK);
		PORTD |= (1 << SRCLK);
	}
	loadR();
}

