/*	Author: david
 *  Partner(s) Name: none
 *	Lab Section: 022
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s
	unsigned char passB = 0x00; // Temporary variable to hold the value of B
	unsigned char passA = 0x00; // Temporary variable to hold the value of A
	unsigned char passC = 0x00; // Temporary variable to hold the value of C
	//unsigned char tmpD = 0x00; // Temporary variable to hold the value of D
	unsigned short total_weight = 0x00;
	signed short weight_diff = 0x00;
	unsigned char merge_val = 0x00;
while(1) {
		// 1) Read input
		passA = PINA;
		passB = PINB;
		passC = PINC;
		// 2) Perform computation
		total_weight = passA + passB + passC;
		weight_diff = passA - passC;
		merge_val = total_weight >> 2;
		// if PA0 is 1, and PA1 is 0, set PB0 to 1
		PORTD = merge_val & 0xFC;
		if (total_weight > 141) {
			PORTD = PORTD | 0x01;
		}
		if (weight_diff > 80 || weight_diff < -80) {
			PORTD = PORTD | 0x02;
		}

	}
	return 0;
}
