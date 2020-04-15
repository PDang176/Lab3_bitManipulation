/*	Author: Patrick Dang
 * 	Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise #5
 *	Exercise Description: [optional - include for your own benefit]
 *	A car's passenger-seat weight sensor outputs a 9-bit value
 *	- This corresponds to PD7 to PD0 + PB0 on the microcontroller
 *	- PD7 to PD0 are the leftmost 8 bits and PB0 is the rightmost bit on the sensor
 *
 *	If the weight is greater than or equal to 70 the airbag should be enabled
 *	- This is done by setting PB1 to 1
 *
 *	If the weight is above 5 but below 70 the airbag should be disabled
 *	- This is done by setting PB2 to 1
 *
 *	If the weight is below 5 then neither PB1 or PB2 is set
 *
 *	Inputs: PD7 to PD0PB0 (9-bit weight sensor)
 *	Outputs: PB1 (airbag enabled), PB2 (airbag disabled)
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
	DDRB = 0xFE; PORTB = 0x01;
	DDRD = 0x00; PORTD = 0xFF;

	unsigned char airbagEnabled = 0x00;
	unsigned char airbagDisabled = 0x00;
    /* Insert your solution below */
    while (1) {
	    if(PIND >= 0x23){
		airbagEnabled = 0x02;
	    }
	    else if(PIND > 0x02){
		airbagDisabled = 0x04;
	    }

	    PORTB = airbagEnabled | airbagDisabled;
	    airbagEnabled = 0x00;
	    airbagDisabled = 0x00;
    }
    return 1;
}
