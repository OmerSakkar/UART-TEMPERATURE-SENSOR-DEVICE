#include "timer.h"

void timer0_initializeCTC(void)
{
	
	OCR0 = 82; //approximately 10ms per tick in 8Mhz frequency with 1024 prescaler
	
	/* set timer mode to compare match */
	SETBIT(TCCR0, WGM01);
	CLRBIT(TCCR0, WGM00);
	
	
	/* set prescaler to 1024 */
	SETBIT(TCCR0, CS00);
	CLRBIT(TCCR0, CS01);
	SETBIT(TCCR0, CS02);
	
	sei();
	
	SETBIT(TIMSK, OCIE0); //enable timer0 interrupter
}

void timer0_stop(void)
{
	//disable the clock
	CLRBIT(TCCR0, CS00);
	CLRBIT(TCCR0, CS01);
	CLRBIT(TCCR0, CS02);
}


