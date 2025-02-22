/*
 * ex3.c
 *
 *  Created on: Feb 15, 2025
 *      Author: marwan
 */


#include<avr/io.h>
#include<util/delay.h>

int main(void)
{
	DDRB &= ~(1<<PB0) | ~(1<<PB1); //Configure pin 0 and pin 1  in PORTB as input pins.
	DDRC |= (1<<PC0) | (1<<PC1);   //Configure pin 0 and pin 1  in PORTC as output pins.
	PORTC |= (1<<PC0)|(1<<PC1);  //Set pin 0 and pin 1  in PORTC with value 1 at the beginning (LEDS OFF).

	while(1)
	{
		if(PINB & (1<<PB0)) //check if button 1 is pressed or not
		{
			PORTC &= ~(1<<PC0); //Led On
		}
		else{
			PORTC |= (1<<PC0);//Led Off
		}
		if(PINB & (1<<PB1))//check if button 2 is pressed or not
		{
			PORTC &= ~(1<<PC1);//Led On
		}
		else
		{
			PORTC |= (1<<PC1);//Led Off
		}


	}


}
