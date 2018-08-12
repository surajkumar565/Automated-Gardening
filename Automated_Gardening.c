/////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : Automated_Gardening
//
//  Target Board : atmega32
//
//  Date Created : 06-11-2017 12:56:07
// 
//  Online Resource  : www.electronicsforstudents.com
//
//  Libraries Included : 
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<avr/io.h>
#include<util/delay.h>


#include "adc.h"
#include "lcd.h"
#include "pwm.h"

int main() 
{

	adc_init();
	lcd_init();
	pwm_init();
	
	int a;
	
	while (1)
	{
	a=adc_read(0);
	
	if(a>280)	//Soil moisture value
	{
	pwm(180);
	
	write(portd,6,h);
	write(portd,7,l);
	
	write(portb,5,h);
	
	lcd_clear();
	lcd_gotoxy(0,1);
	lcd_num(a);

	lcd_gotoxy(1,0);
	lcd_string("Water_req");
    _delay_ms(500);
	
	}
	
	if(a<280)
	{
	pwm(180);
	
	write(portd,6,l);
	write(portd,7,l);
	
	write(portb,5,l);
	
	lcd_clear();
	
	lcd_gotoxy(0,1);
	lcd_num(a);
	
	lcd_gotoxy(1,0);
	lcd_string("Moist");
	
	_delay_ms(500);
	
	}

	}

}
