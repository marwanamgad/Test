/*
 * ex1.c
 *
 *  Created on: Feb 14, 2025
 *      Author: marwan
 */

// Control Led using push button

#include<avr/io.h>

int main(void)
{
	DDRD &= ~(1<<PD2);//Configure pin2 in PORTD as input pin.
	DDRC |= (1<<PC1); //Configure pin1 in PORTC as output pin.
	PORTC &= ~(1<<PC1); //Set pin1 in PORTC with value 0 at the beginning (LED OFF)

	while(1)
	{
		if(!(PIND & (1<<PD2)))//Check if button is pressed or not
		{
			PORTC |= (1<<PC1); // Set pin1 in PORTC with vaue 1 (LED ON)
		}
		else
		{
			PORTC &= ~(1<<PC1); //Set pin1 in PORTC with value 0 (LED OFF)
		}

	}
}
