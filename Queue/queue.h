/*
 * queue.h
 *
 * Created: 4/10/2022 6:36:06 AM
 *  Author: Omer Sakkar
 */ 


#ifndef QUEUE_H_
#define QUEUE_H_

#define BUFFER_CAPACITY 10
#define BUFFER_ENTRY float 

typedef struct queue{
	int front;
	int rear; 
	int size ;
	BUFFER_ENTRY temp_buffer[BUFFER_CAPACITY] ;
} Queue;




/**
   @brief   initialize a queue with the appropriate initial values 
   @param   p_buffer: pointer to the queue to be initialized
   @return  none
*/
void create_buffer(Queue* p_buffer);


/**
   @brief   append an element to the queue, if the queue is full the oldest element will be overwritten
   @param   p_buffer: pointer to the queue 
   @param   element: the element that will be appended 
   @return  none
*/
void append_element(Queue* p_buffer, BUFFER_ENTRY element);


/**
   @brief   dequeue an element and return it
   @param   p_buffer: pointer to the queue 
   @return  the dequeued element
*/
BUFFER_ENTRY dequeue_element(Queue* p_buffer);

bool is_buf_empty(Queue* p_buffer);

#endif /* QUEUE_H_ */