#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

#include <avr/io.h>

// Pin definitions
#define SER 0 // Serial data input 
#define OE 1 // Output enable (active low)
#define RCLK 2 // Register clock
#define SRCLK 3 // Shift register clock
#define SRCLR 4 // Shift register clear (active low)

// Clock pulse duration in microseconds
#define CLOCK_PULSE 1


void clearR();
void loadR();
void loadValue(int temp);

#endif 

