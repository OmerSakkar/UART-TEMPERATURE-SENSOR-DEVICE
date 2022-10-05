/*
 * ADC.c
 *
 * Created: 4/9/2022 12:20:21 AM
 *  Author: Omer Sakkar
 */ 

#include "Std_macros.h"

void adc_init(void)
{
	/*configure VREF to AVCC with external capacitor at AREF pin. This project assumes Verf = 3.3V*/
	SETBIT(ADMUX,REFS0);
	CLRBIT(ADMUX,REFS1);
	/*************************************/
	SETBIT(ADCSRA,ADEN); // ENable ADC
	
	/* adjust ADC clock by select the division factor----->64*/
	/*for max accuracy the frequency should be less than 200khz*/
	SETBIT(ADCSRA,ADPS2);
	SETBIT(ADCSRA,ADPS1);
	/***********************************/
}
uint16_t get_adc_result(void)
{
	
	ADMUX = ADMUX & 0b11100000; // Set ADC channel to A0
	SETBIT(ADCSRA,ADSC); // start conversion
	while( !READBIT(ADCSRA,ADIF) );// wait until conversion is completed
	SETBIT(ADCSRA,ADIF); // clear ADIF
	return ADC ; // return the converted value
}