/*
 * lab3.c
 *
 * Created: 11/4/2022 10:44:57 PM
 * Author : rafik
 */ 
#define F_CPU	8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(ADDRESS,BIT)	ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS,BIT)	ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT)	ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT)	((ADDRESS & (1<<BIT))>>BIT)

int main(void)
{
	//set int0 any logical change
	SET_BIT(MCUCR,0);
	RESET_BIT(MCUCR,1);
	//set int1 as rising edge
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	//set int2 as falling edge
	RESET_BIT(MCUCR,6);
	//enable interrupts
	SET_BIT(GICR,5);
	SET_BIT(GICR,6);
	SET_BIT(GICR,7);
	
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
	
	sei();
    /* Replace with your application code */
    while (1) 
    {
		RESET_BIT(PORTD,5);
		RESET_BIT(PORTD,6);
		RESET_BIT(PORTD,7);
    }
}
ISR(INT0_vect)
{
	SET_BIT(PORTD,5);
	_delay_ms(100);
}
ISR(INT1_vect)
{
	SET_BIT(PORTD,6);
	_delay_ms(100);
}
ISR(INT2_vect)
{
	SET_BIT(PORTD,7);
	_delay_ms(100);
}