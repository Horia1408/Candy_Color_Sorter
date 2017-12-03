#ifndef SERVO_PWM_H
#define SERVO_PWM_H
#include <avr/io.h>
#include <util/delay.h>
#define _BV(n) (1<<n)

void init_PWM()
{
	DDRB |= _BV(2); // set D10 as output
	DDRB |= _BV(1); // set D9 as output
	
	TCCR1A |= _BV(7) | _BV(5) | _BV(1); //COM1 = 1010, WGM11 = 1; WGM10 = 0
	TCCR1B |= _BV(4) | _BV(3) | _BV(1) | _BV(0); //WGM13 = 1; WGM12 = 1; CS11 = 1; CS10 = 1;
	
	ICR1=0x03FF;

}

void moveToTake_PD9()
{
	OCR1A = ICR1 - 0x342;
	_delay_ms(2000);
}

void moveToScan_PD9()
{
	OCR1A = ICR1 - 0x25F;
	_delay_ms(2000);
}

void moveToDrop_PD9()
{
	OCR1A = ICR1 - 0x00F;
	_delay_ms(2000);
}

void moveToRed_PD10()
{
	OCR1B = ICR1 - 0x342;
	_delay_ms(2000);
}

void moveToGreen_PD10()
{
	OCR1B = ICR1 - 0x25F;
	_delay_ms(2000);
}

void moveToBlue_PD10()
{
	OCR1B = ICR1 - 0x00F;
	_delay_ms(2000);
}

#endif