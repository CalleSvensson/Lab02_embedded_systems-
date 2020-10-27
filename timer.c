#include <avr/io.h>
#include <stdbool.h>

#include "timer.h"
bool countUp = true;
uint8_t count = 0;

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
	/*sub task 3*/
	TCCR2A |= (1 << WGM21); // timer2 in CTC mode
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // prescaler 1024
	OCR2A = 249; //16000000/ (1024)*(0,016)-1



}

uint8_t simple_ramp()
{
	if (countUp)
	{
		count++;
		if (count == 255) countUp = false;
		return count;
	}
	else
	{
		count--;
		if (count == 0) countUp = true;
		return count;
	}
	
}

