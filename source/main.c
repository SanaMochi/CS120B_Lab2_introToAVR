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
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as inputs

    	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	

    /* Insert your solution below */
    while (1) {
	// Read input
        tmpA = PINA & 0x03;
        if (tmpA == 0x01) { // True if PA0 is 1
                tmpB = 0x01; // 00000001
        } else {
                tmpB = 0x00; // Sets tmpB to 00000000
        }
        PORTB = tmpB;

    }
    return 0;
}
