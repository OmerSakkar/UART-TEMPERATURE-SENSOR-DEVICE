/*
 * UART.h
 *
 * Created: 4/10/2022 2:47:06 AM
 *  Author: Omer Sakkar
 */ 


#ifndef UART_H_
#define UART_H_

#include "Std_macros.h"

void uart_init();
void uart_write(char data);
void uart_write_string(char* data);
uint8_t Uart_Read();

#endif /* UART_H_ */