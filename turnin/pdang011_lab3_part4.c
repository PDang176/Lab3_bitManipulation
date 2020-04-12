/*	Author: Patrick Dang
 * 	Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *	Read in an 8-bit value from PINA
 *	- This gets changed into 2 4-bit values in Ports B and C
 *	- PB3 to PB0 corresponds to PA7 to PA4
 *	- PC7 to PC4 corresponds to PA3 to PA0
 *	
 *	Inputs: PA7 to PA0
 *	Outputs: PB3 to PB0 (PA7 to PA4), PC7 to PC4 (PA3 to PA0)
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char lower = 0x00;
	unsigned char upper = 0x00;
    /* Insert your solution below */
    while (1) {
	    lower = PINA & 0x0F;
	    lower = lower << 4;
	    upper = PINA & 0xF0;
	    upper = upper >> 4;

	    PORTB = upper;
	    PORTC = lower;
    }
    return 1;
}
