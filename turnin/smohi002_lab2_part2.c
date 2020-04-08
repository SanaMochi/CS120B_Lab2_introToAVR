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
   	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
//    	unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
    	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A

	unsigned char cntavail = 0x04;

    /* Insert your solution below */
    while (1) {
	// 1) Read input
        tmpA = PINA & 0x0F;

	//count how many spaces are taken	
	unsigned char cnt = 0x00;
	cnt = ((tmpA & 0x08) >> 3) + ((tmpA & 0x04) >> 2) + ((tmpA & 0x02) >> 1) + (tmpA & 0x01);

	//subtract how many are taken from total
	cntavail = 0x04 - cnt;	

//	if (cntavail == 0x00) { // True if PA0 is 0x0F
//           	cntavail = 10000000 ; // 10000000
//	}
	
	
	PORTC = cntavail;
    }
    return 0;
}
