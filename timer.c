#include <avr/io.h>

#include "timer.h"

void timer_init() 
{	
	/* sub task 1 CTC mode
	TCCR0A = 0; // set all pin i register to 0
	TCCR0A|= (1 << WGM01);   // CTC mode in register timer0
	TCCR0B |= (1 << CS02) | (1 << CS00);  // Set CS02 and CS01 bits for 1024 prescaler
	OCR0A = 155; //16000000/ (1024)*(0,01)-1	*/
	
	/*sub task 2 fast PWM mode*/
	TCCR0A = 0;
	TCCR0A |= (1 << WGM01) | (1 << WGM00); // set to fast PWM mode with TOP 0xFF by default
	TCCR0A |= (1 << COM0A1); //non- inverting mode
	TCCR0B |= (1 << CS01) | (1<<CS00); // set 64 prescaler. PWM frequency 16000000/16384 = 976,5625
	
	



}

