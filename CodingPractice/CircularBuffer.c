// author:		Bruce Wheeler
// file name:	CircularBuffer.c
// date:		05/22/26 - Framework Creation
//				05/24/26 - cb_init() coded

// Section 1.3 Coding Problem 1 - Circular Buffer
// A 16-byte Circular Buffer in C

//	Behavior
//	  cb_push() returns 0 on success and -1 if the buffer is full
//	  cb_pop() returns 0 on success and -1 if the buffer is empty
//	  The buffer should wrap around correctly
//	  Avoid dynamic memory allocation

#include <stdio.h>
#include <stdint.h>

#define BUFFER_SIZE 16

typedef struct {
	uint8_t data[BUFFER_SIZE];	// the storage itself
	uint8_t head;				// index of next write location
	uint8_t tail;				// index of next read location
	uint8_t count;				// number of valid bytes currently stored
} CircularBuffer;

void cb_init(CircularBuffer *cb);					// #1
int cb_push(CircularBuffer *cb, uint8_t value);		// #4
int cb_pop(CircularBuffer *cb, uint8_t *value);		// #5
int cb_is_empty(CircularBuffer *cb);				// #2
int cb_is_full(CircularBuffer *cb);					// #3

int main() {

	CircularBuffer test;
	cb_init(&test);

	// after cb_init(), verify initialization
	printf("\n\nVerification of cb_init(CircularBuffer *cb) function >>> STARTED\n\n");
	
	for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
		printf("Data[%u] = %u\n", i , test.data[i]);
	}
	printf("Head\t= %u\n", test.head);
	printf("Tail\t= %u\n", test.tail);
	printf("Count\t= %u\n", test.count);
	
	printf("\nVerification of cb_init(CircularBuffer *cb) function >>> FINISHED\n\n");
	
	return 0;
}

void cb_init(CircularBuffer *cb){
	if (cb == NULL) {
		return;
	}	
	
	for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
		cb->data[i]	= 0;
	}
	
	cb->head	= 0;
	cb->tail	= 0;
	cb->count	= 0; 
}

int cb_push(CircularBuffer *cb, uint8_t value){
	return -1;
}

int cb_pop(CircularBuffer *cb, uint8_t *value){
	return -1;
}

int cb_is_empty(CircularBuffer *cb){
	return -1;
}

int cb_is_full(CircularBuffer *cb){
	return -1;
}
