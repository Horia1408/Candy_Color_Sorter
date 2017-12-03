#include "Servo_PWM.h"
#include "Resistor_ADC.h"
#include "Led_RGB.h"

int main(void)
{
	//setup
	init_PWM(); //D10, D9
	init_LED(); //D6, D5, D3
	Init_ADC(); //A0
	
	//loop
	while (1)
	{
		if(Read_ADC(0) > 512)
		{
			Red_OFF();
			Blue_OFF();
			Green_OFF();
			Red_ON();
		}
		else{
			Red_OFF();
			Blue_ON();
			Blue_OFF();
			Green_ON();
			Green_OFF();
			Red_ON();
		}
		Red_OFF();
		
		/*
		moveToTake_PD9();
		moveToDrop_PD9();
		moveToRed_PD10();
		moveToGreen_PD10();
		moveToBlue_PD10();
		moveToGreen_PD10();
		*/
	}
}