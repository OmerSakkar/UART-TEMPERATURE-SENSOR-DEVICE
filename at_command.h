/*
 * at_command.h
 *
 * Created: 4/10/2022 7:05:33 AM
 *  Author: Omer Sakkar
 */ 


#ifndef AT_COMMAND_H_
#define AT_COMMAND_H_


#include "Std_macros.h"
#include "UART.h"
#include "queue.h"
#include "string.h" //strcmp

#define MAX_COMMADN_SIZE 20 //can't be over 255 or you need to change the type of the counter in the UART receive interrupt


/**
   @brief   parse at commands and take the appropriate action,
   @param   command: the command to be handled 
   @return  none
*/
void at_handle_command(char* command );



#endif /* AT_COMMAND_H_ */