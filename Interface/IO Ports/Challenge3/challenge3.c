/*
 * challenge3.c
 *
 *  Created on: Feb 15, 2025
 *      Author: marwan
 */

#include <avr/io.h>
#include<util/delay.h>

void seven_Segment_Display(unsigned char value)
{
	switch(value)
	{
	case 0:
			PORTA |= (1<<1);
			PORTA |= (1<<2);
			PORTA |= (1<<3);
			PORTA |= (1<<4);
			PORTA |= (1<<5);
			PORTA |= (1<<6);
			PORTA &= ~(1<<7);
			break;
		case 1:
			PORTA &= ~(1<<1);
			PORTA |= (1<<2);
			PORTA |= (1<<3);
			PORTA &= ~(1<<4);
			PORTA &= ~(1<<5);
			PORTA &= ~(1<<6);
			PORTA &= ~(1<<7);
			break;
		case 2:
			PORTA |= (1<<1);
			PORTA |= (1<<2);
			PORTA &= ~(1<<3);
			PORTA |= (1<<4);
			PORTA |= (1<<5);
			PORTA &= ~(1<<6);
			PORTA |= (1<<7);
			break;
		case 3:
			PORTA |= (1<<1);
			PORTA |= (1<<2);
			PORTA |= (1<<3);
			PORTA |= (1<<4);
			PORTA &= ~(1<<5);
			PORTA &= ~(1<<6);
			PORTA |= (1<<7);
			break;
		case 4:
			PORTA &= ~(1<<1);
			PORTA |= (1<<2);
			PORTA |= (1<<3);
			PORTA &= ~(1<<4);
			PORTA &= ~(1<<5);
			PORTA |= (1<<6);
			PORTA |= (1<<7);
			break;
		case 5:
			PORTA |= (1<<1);
			PORTA &= ~(1<<2);
			PORTA |= (1<<3);
			PORTA |= (1<<4);
			PORTA &= ~(1<<5);
			PORTA |= (1<<6);
			PORTA |= (1<<7);
			break;
		case 6:
			PORTA |= (1<<1);
			PORTA &= ~(1<<2);
			PORTA |= (1<<3);
			PORTA |= (1<<4);
			PORTA |= (1<<5);
			PORTA |= (1<<6);
			PORTA |= (1<<7);
			break;
		case 7:
			PORTA |= (1<<1);
			PORTA |= (1<<2);
			PORTA |= (1<<3);
			PORTA &= ~(1<<4);
			PORTA &= ~(1<<5);
			PORTA &= ~(1<<6);
			PORTA &= ~(1<<7);
			break;
		case 8:
			PORTA |= (1<<1);
			PORTA |= (1<<2);
			PORTA |= (1<<3);
			PORTA |= (1<<4);
			PORTA |= (1<<5);
			PORTA |= (1<<6);
			PORTA |= (1<<7);
			break;
		case 9:
			PORTA |= (1<<1);
			PORTA |= (1<<2);
			PORTA |= (1<<3);
			PORTA &= ~(1<<4);
			PORTA &= ~(1<<5);
			PORTA |= (1<<6);
			PORTA |= (1<<7);
			break;
		}
	}

int main (void)
{
	unsigned char count = 0;
	DDRD &= ~(1<<PD2) | ~(1<<PD3);
	DDRA = 0xFE;
	PORTA = 0x00;

	DDRC  |= (1<<6);// configure pin 6 in PORTC as output pin

	// Set pin 6 in PORTC with value 1 to enable the BJT NPN transistor to connect the first 7-segment common to the ground(common cathode)
	PORTC |= (1<<6);

	while(1)
	{
		if(!(PIND & (1<<PD2)))
		{
			_delay_ms(30);
			if(!(PIND & (1<<PD2)))
			{
				if(count !=9){
					count++;
				}
				seven_Segment_Display(count);
			}

			while(!(PIND & (1<<PD2))){

			}
		}

			else if(!(PIND & (1<<PD3)))
			{
				_delay_ms(30);
				if( !(PIND & (1<<PD3)) ) //second check due to switch bouncing
				{
					if(count != 0)
					{
						// decrement 7-segment every press
						count--;
					}
						seven_Segment_Display(count); // Display the digit on the 7-segment
						}
						while( !(PIND & (1<<PD3)) ){} // wait until switch is released

			}




		}
	}

