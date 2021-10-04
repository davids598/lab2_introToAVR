/*	Author: david
 *  Partner(s) Name: none
 *	Lab Section: 022
 *	Assignment: Lab #2  Exercise #2
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
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpD = 0x00; // Temporary variable to hold the value of D
	unsigned char cntavail = 0x04;
while(1) {
		// 1) Read input
		tmpA = PINA & 0x01;
		tmpB = PINA & 0x02;
		tmpC = PINA & 0x04;
		tmpD = PINA & 0x08;
		// 2) Perform computation
		// if PA0 is 1, and PA1 is 0, set PB0 to 1
		cntavail = 0x04;
		if (tmpA) {
			cntavail = cntavail - 1;
		}
		if (tmpB) {
			cntavail = cntavail - 1;
		}
		if (tmpC) {
			cntavail = cntavail - 1;
		}
		if (tmpD) {
			cntavail = cntavail - 1;
		}
		PORTC = cntavail;

	}
	return 0;
}
