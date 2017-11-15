#include "Servo_PWM.h"

int main(void) {
	
	DDRB |= _BV(2); // set PD10 as output
	DDRB |= _BV(1); // set PD9 as output
	init_PWM();
	
	while (1)
	{
		moveToTake_PD9();
		_delay_ms(2000);
		moveToDrop_PD9();
		_delay_ms(2000);
		moveToRed_PD10();
		_delay_ms(2000);
		moveToGreen_PD10();
		_delay_ms(2000);
		moveToBlue_PD10();
		_delay_ms(2000);
		moveToGreen_PD10();
		_delay_ms(2000);
	}
}