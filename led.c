#include <avr/io.h>
#include <stdbool.h>
#include "led.h"
bool ledIsOn = false;
void LED_init() 
{
    DDRB |= (1 << PB3); // set pin 11 on Arduino board to output
    //DDRB |= (1 << PB2); // set pin 10 on Arduino board to output
    //DDRB |= (1 << PB1); // set pin 9 on Arduino board to output
}
void LED_toggle()
{
    ledIsOn = !ledIsOn;
    if(ledIsOn == false)
    {
        PORTB |= (1 << PB3);
    }
    else
    {
        PORTB &= ~(1 << PB3);
    }
}
