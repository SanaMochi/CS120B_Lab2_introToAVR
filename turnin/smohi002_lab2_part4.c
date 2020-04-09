/*	Author: smohi002
 *  Partner(s) Name: 
 *	Lab Section: 25
 *	Assignment: Lab #2  Exercise #0
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
    /* Insert DDR and PORT initializations */

	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
   	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as intputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialized to 0

    	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
	unsigned char tmpD = 0x00; // Temporary variable to hold the value of D
	
	unsigned char total_weight;

    /* Insert your solution below */
    while (1) {
	// Read input
        tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
	tmpD = 0x00;
	total_weight = tmpA + tmpB;
	total_weight += tmpC;

	if (total_weight > 0x8C) { 
        	tmpD = 0x01;
	}
	if (((tmpA - tmpC) > 0x50) || ((tmpC - tmpA) > 0x50)) {
		tmpD = (tmpD & 0x01) | 0x02;
	}

	tmpD = (total_weight & 0xFC) | tmpD;
		
	PORTD = tmpD;
    }
    return 0;
}
