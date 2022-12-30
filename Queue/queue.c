/*
 * queue.c
 *
 * Created: 4/10/2022 6:15:56 AM
 *  Author: Omer Sakkar
 */

 
#include "queue.h"

void create_buffer(Queue* p_buffer)
{
	p_buffer->front= 0;
	p_buffer->rear = -1;
	p_buffer->size = 0;
}


void append_element(Queue* p_buffer, BUFFER_ENTRY element)
{
	p_buffer->rear = (p_buffer->rear + 1) % BUFFER_CAPACITY; 
	
	if (p_buffer->size == BUFFER_CAPACITY )
	{
		p_buffer->front = (p_buffer->front + 1) % BUFFER_CAPACITY;
	}
	else 
	{
		p_buffer->size++;
	}
	p_buffer->temp_buffer[p_buffer->rear] = element; 
}


float dequeue_element(Queue* p_buffer) {
	
	if (p_buffer->size == 0) 
	{
		return -1;
	}
	BUFFER_ENTRY temp;
	temp = p_buffer->temp_buffer[p_buffer->front];
	p_buffer->front = (p_buffer->front + 1) % BUFFER_CAPACITY; 
	return temp;
}

bool is_buf_empty(Queue* p_buffer){
   return !(p_buufer->size);
}

bool is_buf_full(Queue* p_buffer){
   return p_buffer->size == BUFFER_CAPACITY;
}