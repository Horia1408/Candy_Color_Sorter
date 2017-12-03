#ifndef RESISTOR_ADC_H
#define RESISTOR_ADC_H
#include <avr/io.h>
#define _BV(n) (1<<n)

void Init_ADC()
{
	DDRC &= ~(_BV(0)); //set A0 as input
	
	ADMUX |= _BV(REFS0); // Select Vref=AVcc
	ADCSRA |= _BV(ADPS2) | _BV(ADPS1)| _BV(ADPS0)| _BV(ADEN); //set prescaller to 128 and enable ADC
}

uint16_t Read_ADC(uint8_t ADCchannel)
{
	//select ADC channel with safety mask
	ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);
	//single conversion mode
	ADCSRA |= _BV(ADSC);
	// wait until ADC conversion is complete
	while( ADCSRA & _BV(ADSC) );
	return ADC;
}

#endif