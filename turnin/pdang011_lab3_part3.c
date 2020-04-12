/*	Author: Patrick Dang
 * 	Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #3  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *	A car has a fuel-level sensor for PA3 to PA0
 *	- 0 means empty and 15 means full
 *
 *	PA4 is 1 if the key is in the ignition
 *	PA5 is 1 if the driver is seated
 *	PA6 is 1 if the seatbelt is fastened
 *
 *	This corresponds to a LED light output PC5 to PC0
 *	- PC5 = level 1-2, PC4 = level 3-4, PC3 = level 5-6, PC2 = level 7-9, 
 *	  PC1 = level 10-12, PC0 = level 13-15
 *	- The previous led light stays on as the level's increase
 *
 *	PC6 is the low fuel icon which lights up if the fuel level is 4 or less
 *
 *	PC7 is the Fasten seatbelt LED if the driver needs to fasten his/her seatbelt
 *
 *	Inputs: PA3 to PA0 (fuel level 0 to 15), PA4 (key in), PA5 (driver seated), PA6 (seatbelt)
 *	Outputs: PC5 to PC0 (led indicator of level), PC6 (low fuel indicator), PA7 (need seatbelt)
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
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char fuelLevel = 0x00;
	unsigned char lowFuel = 0x00;
	unsigned char seatbelt = 0x00;
    /* Insert your solution below */
    while (1) {
	if((PINA & 0x0F) <= 0x04){
		lowFuel = 0x40;
	}
	if((PINA & 0x0F) >= 0x0D){
		fuelLevel = fuelLevel | 0x01;
	}
	if((PINA & 0x0F) >= 0x0A){
		fuelLevel = fuelLevel | 0x02;
	}
	if((PINA & 0x0F) >= 0x07){
		fuelLevel = fuelLevel | 0x04;
	}
	if((PINA & 0x0F) >= 0x05){
		fuelLevel = fuelLevel | 0x08;
	}
	if((PINA & 0x0F) >= 0x03){
		fuelLevel = fuelLevel | 0x10;
	}
	if((PINA & 0x0F) >= 0x01){
		fuelLevel = fuelLevel | 0x20;
	}

	if((PINA & 0x10) && (PINA & 0x20) && (~PINA & 0x40)){
		seatbelt = 0x80;
	}

	PORTC = fuelLevel | lowFuel | seatbelt;
	lowFuel = 0x00;
	fuelLevel = 0x00;
	seatbelt = 0x00;
    }
    return 1;
}
