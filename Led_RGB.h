#ifndef LED_RGB_H
#define LED_RGB_H
#include <avr/io.h>
#define _BV(n) (1<<n)

void init_LED()
{
	DDRD |= _BV(6); // set D6 as output R
	DDRD |= _BV(5); // set D5 as output G
	DDRD |= _BV(3); // set D3 as output B
}

void Red_ON()
{
	PORTD |= _BV(6);
	_delay_ms(500);
}

void Red_OFF()
{
	PORTD &= ~(_BV(6));
}

void Green_ON()
{
	PORTD |= _BV(5);
	_delay_ms(500);
}

void Green_OFF()
{
	PORTD &= ~(_BV(5));
}

void Blue_ON()
{
	PORTD |= _BV(3);
	_delay_ms(500);
}

void Blue_OFF()
{
	PORTD &= ~(_BV(3));
}

#endif