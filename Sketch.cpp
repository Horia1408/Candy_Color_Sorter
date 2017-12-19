#include "Servo_PWM.h"
#include "Color_Detector.h"

int main(void)
{
	//setup
	init_PWM(); //D10, D9
	init_LED(); //D6, D5, D3
	Init_ADC(); //A0
	int redValue = 0;
	int greenValue = 0;
	int blueValue = 0;
	
	//loop
	while (1)
	{
		
		moveToTake_PD9();
		
		moveToScan_PD9();
		//collect data
		redValue = Red_Value();
		greenValue = Green_Value();
		blueValue = Blue_Value();
		//calculate proper location
		if( redValue >= greenValue && redValue >= blueValue)
			moveToRed_PD10();
		else if (greenValue >= redValue && greenValue >= blueValue)
				moveToGreen_PD10();
			else
				moveToBlue_PD10();
		
		moveToDrop_PD9();
		

	}
}