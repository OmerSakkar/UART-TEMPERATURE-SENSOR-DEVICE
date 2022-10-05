/*
 * UART_THERMISTOR_PROJECT.c
 *
 * Created: 4/9/2022 12:04:25 AM
 * Author : Omer Sakkar
 */ 
#include "Std_macros.h"
#include "ADC.h"
#include "timer.h"
#include "math.h" //log
#include "NTC_temprature.h"
#include "UART.h"
#include "queue.h"
#include "at_command.h"


volatile uint8_t interrupt_flag_100ms = 0; //will be set to one every 100ms by timer0 indicating that we should read a sample from ADC
volatile uint8_t complete_command_received = 0; // set to 1 when a complete command has been received by UART master

char received_command[MAX_COMMADN_SIZE]; //store command received by master
Queue temperature_buffer; //define circular buffer for temperature


int main(void)
{
    /*initialization*/
	timer0_initializeCTC();
	adc_init();
	
	uint16_t adc_result = 0;
	float raw_temp = 0.0;
    float filtered_temp = 0.0;
    
	/*create temperature circular queue buffer and initialize it*/
	create_buffer(&temperature_buffer); //initialize the temperature buffer
	
	while (1) 
    {
		if (interrupt_flag_100ms ) // note that since we're working on 8 bit mcu, operations on 8-bit variables are done atomically, NO RACE CONDITION
		{
			adc_result = get_adc_result();
			raw_temp = calculate_temperature(adc_result);
			filtered_temp = filter_temperature(raw_temp);
			append_element(&temperature_buffer, filtered_temp); // QUEUE filtered temp to the buffer
			interrupt_flag_100ms = 0 ;
		}
		
		if (complete_command_received)
		{
			
			at_handle_command(received_command);
			complete_command_received = 0;
		}
	
	}
	
}


/*	get executed once every 100ms to ensure a10HZ sampling rate of ADC */
ISR(TIMER0_COMP_vect)
{
	interrupt_flag_100ms = 1; //set the flag indicating that 100ms have passed
}


/*get executed when there is a data received by UART*/
ISR(USART_RXC_vect)
{
	static uint8_t character_counter = 0;
	received_command[character_counter] = UDR; //save adc result to the array
	
	if(received_command[character_counter] == '\n') // if the end of the command was encountered
	{
		complete_command_received = 1;
		character_counter = 0 ;
	}
	else
	{
		character_counter++;
	}
}


