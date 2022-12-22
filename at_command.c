/*
 * at_command.c
 *
 * Created: 4/10/2022 7:05:06 AM
 *  Author: Omer Sakkar
 */ 
#include "at_command.h"
#include "queue.h"

extern Queue temperature_buffer;
 
void at_handle_command(char* command )
{
	
	if ( strcmp(command, "AT+TEMP?\n") == 0 ) 
	{
		float temp[BUFFER_SIZE]; 
		unsigned char* temp_in_char;
		int buffer_length = temperature_buffer.size; 
		 
		for(uint8_t i = 0; i < buffer_length; i++)
		{
			temp [i] = dequeue_element(&temperature_buffer);
		}
		
		//reply "+TEMP:"
		uart_write_string("+TEMP:");
		
		for(uint8_t i = 0; i < buffer_length; i++)
		{
			temp_in_char = (unsigned char*) &temp[i]; //convert temp[i] from float to unsigned char
			
			/*replay with 4-byte temperatures until buffer is empty */
			uart_write(*temp_in_char++);
			uart_write(*temp_in_char++);
			uart_write(*temp_in_char++);
			uart_write(*temp_in_char);
		}
		
		uart_write('\n'); //reply '\n' 	
	}
	
	/*more commands can be added here using else if*/
	/*a Hash function could be designed to avoid continuous calling of strcmp*/
	
	else // if command is invalid
	{
		//handle invalid commands here
	}
}