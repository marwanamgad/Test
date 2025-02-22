/*
 * ex5.c
 *
 *  Created on: Feb 14, 2025
 *      Author: marwan
 */


#include<avr/io.h>

int main(void)
{
	DDRD &= ~(1<<PD3); //configure pin3 in PORTD as input pin
	DDRC |= (1<<PC5); //configure pin5 in PORTC as output pin
	PORTC &= ~(1<<PC5); //Set pin5 in PORTC with value 0 at the beginning(Buzzer OFF)

	while(1){

		if(!(PIND & (1<<PD3))) //check if button is pressed or not
		{
			PORTC |= (1<<PC5); // Buzzer On
		}
		else
		{
			PORTC &= ~(1<<PC5); //Buzzer OFF
		}
	}
}
