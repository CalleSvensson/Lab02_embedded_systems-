#include <avr/io.h>
#include <stdbool.h>
#include "led.h"
bool ledIsOn = false;
void LED_init() 
{
    DDRB |= (1 << PB3); // set pin 11 on Arduino board to output
    DDRD |= (1 << PD6); // set pin 6 on Arduino board to output(AIN0/OC0A)
}
void LED_toggle()
{
    PORTB ^= (1 << PB3); // flip LED bit
    //PORTD ^= (1 << PD6); // flip LED bit
}
