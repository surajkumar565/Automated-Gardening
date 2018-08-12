#ifndef _PWM_H_
#define _PWM_H_


void pwm_init()
{



	TCCR0=0x69;	
	DDRB|=(1<<PB3);
}



void pwm(uint8_t duty)
{
	OCR0=duty;
	
}






#endif 