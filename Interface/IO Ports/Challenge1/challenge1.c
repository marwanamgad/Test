/*
 * challenge1.c
 *
 *  Created on: Feb 15, 2025
 *      Author: marwan
 */

//Controlling 3 Leds (Roll Action)

#include<avr/io.h>
#include<util/delay.h>

int main (void)
{
	DDRC |= 0x07;  //Configure PIN0,PIN1,PIN2 as output pins.
	PORTC &= 0xF8; // Set PIN0,PIN1,PIN2 with value 0 at the beginning (3 LEDS are OFF)

	while(1)
	{

		PORTC = 0x01;  // Turn on the first led only (PC0=1,PC1=0,PC2=0)
		_delay_ms(500);// delay for 0.5 sec

		PORTC = 0x02 ; // Turn on the second led only (PC0=0,PC1=1,PC2=0)
		_delay_ms(500);

		PORTC = 0x04; // Turn on the third led only (PC0=0,PC1=0,PC2=1)
		_delay_ms(500);
	}
}
