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
	p_buffer->rear = (p_buffer->rear + 1) % BUFFER_SIZE; //increment rear in a circular manner 
	
	if (p_buffer->size >= BUFFER_SIZE )//if the buffer is full (at this point rear will be the same as front )
	{
		p_buffer->front = (p_buffer->front + 1) % BUFFER_SIZE; // update front to the next element because the oldest one will be overwritten
	}
	else // increment the size only if the queue is not full, if it's full oldest element will be overwritten and it will stay full
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
	p_buffer->front = (p_buffer->front + 1) % BUFFER_SIZE; //update front in a circular way
	return temp;
}