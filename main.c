#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdbool.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
//bool countUp = true;
void main (void) 
{
	uart_init();
	LED_init();
	timer_init();
	//int count = 0;
	
	while (1) 
	{
		if (TIFR2 & (1 << OCF2A))
		{
			OCR0A = simple_ramp();
			TIFR2 = (1 << OCF2A);
		}
		
		/*if (countUp)
		{
			count++; 
			if (count == 255) countUp = false;
		}
		else
		{
			count--;
			if (count == 0) countUp = true;
		}
		_delay_ms(10);*/

		/*if(TIFR0 & (1<<OCF0A)) // check CTC flag
		{
		
		i++;	
		
		if (i == 10) 
		{
			LED_toggle();
			i = 0;
		}
		TIFR0 = (1 << OCF0A); // reset flag
		}*/
	}
}
