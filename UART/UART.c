/*
 * UART.c
 *
 * Created: 4/10/2022 2:47:54 AM
 *  Author: Omer Sakkar
 */ 
#include "UART.h"

void uart_init(){
   // baud rate
   UBRRL = 103;// baud rate 9600, F_CPU = 8Mhz
   /* Enable receiver and transmitter. Enable received data interrupter */
   UCSRB = (1<<RXEN) | (1<<TXEN) | (1<<RXCIE);
   UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<UCSZ0) ; // 8 bit data frame
   sei(); //enable global interrupter 
}

void uart_write(char data){
   /* Wait for empty transmit buffer */
   //while ( !( UCSRA & (1<<UDRE)) ); // check trans
   UDR = data;
   while(READBIT(UCSRA, TXC) == 0);
}

void uart_write_string(char *data){
	for (uint8_t i = 0; data[i] != '\0'; i++)
		uart_write(data[i]);
}

uint8_t Uart_Read(){
	while ( READBIT(UCSRA, RXC) == 0 );
	return UDR;
}