/*	Author: Patrick Dang
 *  	Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *	Count the number of 1's in ports A and B and output it to port C
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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char countOnes = 0x00;
    /* Insert your solution below */
    while (1) {
	unsigned char currPIN = 0x01;
	for(int i = 1; i <= 8; i++){
		if(PINA & currPIN){
			countOnes++;
		}
		if(PINB & currPIN){
			countOnes++;
		}
		currPIN = currPIN * 2;
	}
	PORTC = countOnes;
	countOnes = 0x00;
    }
    return 1;
}
