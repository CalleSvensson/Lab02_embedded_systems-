#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>

#include "led.h"
#include "serial.h"
#include "timer.h"

void main (void) 
{
	uart_init();
	LED_init();
	timer_init();
	int i = 0;
	
	while (1) 
	{
		//if ((TIFR0 & (1 << TOV0)) == 1) // Check flag tifr0 == ocr0b
		if(TIFR0 & (1<<OCF0A))
		{
		
		i++;	
		
		if (i == 10) 
		{
			LED_toggle();
			i = 0;
		}
		//TIFR0 = (1 << TOV0); // reset flag
		TIFR0 = (1 << OCF0A); // reset flag
		}
	}
}
