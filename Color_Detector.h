#ifndef COLOR_DETECTOR_H
#define COLOR_DETECTOR_H
#include <avr/io.h>
#include "Resistor_ADC.h"
#include "Led_RGB.h"
#define _BV(n) (1<<n)

int Red_Value(){
	int value;
	Blue_OFF();
	Green_OFF();
	Red_ON();
	value = Read_ADC(0);
	//_delay_ms(250);
	Red_OFF();
	return value;
}

int Blue_Value(){
	int value;
	Blue_ON();
	Green_OFF();
	Red_OFF();
	value = Read_ADC(0);
	//_delay_ms(250);
	Blue_OFF();
	return value;
}

int Green_Value(){
	int value;
	Blue_OFF();
	Green_ON();
	Red_OFF();
	value = Read_ADC(0);
	//_delay_ms(250);
	Green_OFF();
	return value;
}

#endif