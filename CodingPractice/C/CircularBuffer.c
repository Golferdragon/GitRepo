// AUTHOR:		Bruce Wheeler
// FILE NAME:	CircularBuffer.c
// DATE:		(Date Finished)

//	A 16-byte Circular Buffer in C

// 	Behavior
//	-  cb_push() returns 0 on success and -1 if the buffer is full
//	-  cb_pop() returns 0 on success and -1 if the buffer is empty
//	-  The buffer should wrap around correctly
//	-  Avoid dynamic memory allocation

// needed header files
#include <stdio.h>
#include <stdint.h>

// defines
#define BUFFER_SIZE 16

// defining buffer struct
typedef struct {
	uint8_t data[BUFFER_SIZE];	// the storage itself
	uint8_t head;				// index of next write location
	uint8_t tail;				// index of next read location
	uint8_t count;				// number of valid bytes currently stored
} CircularBuffer;

// function declarations
void cb_init(CircularBuffer *cb);					// #1
int cb_push(CircularBuffer *cb, uint8_t value);		// #4
int cb_pop(CircularBuffer *cb, uint8_t *value);		// #5
int cb_is_empty(CircularBuffer *cb);				// #2
int cb_is_full(CircularBuffer *cb);					// #3

// main - testing and verification of function(s) done here
int main() {

	CircularBuffer test;
	cb_init(&test);

	// after cb_init(), verify initialization
	printf("\n\nVerification of cb_init(CircularBuffer *cb) function >>> STARTED <<<\n\n");
	
	for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
		printf("Data[%u] = %u\n", i , test.data[i]);
	}
	printf("Head\t= %u\n", test.head);
	printf("Tail\t= %u\n", test.tail);
	printf("Count\t= %u\n", test.count);
	
	printf("\nVerification of cb_init(CircularBuffer *cb) function >>> FINISHED <<<\n\n");
	
	// cb_is_empty() and cb_is_full() verification
	printf("\n\nVerification of cb_is_full(CircularBuffer *cp) & cb_is_empty(CircularBuffer *cb) function(s) >>> STARTED <<<\n\n");
	
	
	
	printf("\n\nVerification of cb_is_full(CircularBuffer *cp) & cb_is_empty(CircularBuffer *cb) function(s) >>> FINISHED <<<\n\n");
	return 0;
}

// function definitions
void cb_init(CircularBuffer *cb){
	if (cb == NULL) {
		return;
	}	
	
	for (uint8_t i = 0; i < BUFFER_SIZE; i++) {		// make sure all elements of data are initialized properly
		cb->data[i]	= 0;
	}
	
	cb->head	= 0;								// initialize indexes to their default values
	cb->tail	= 0;
	cb->count	= 0;								// initialize valid bytes tracker to default value
}

int cb_push(CircularBuffer *cb, uint8_t value){
	// check if buffer is full, if full return -1
	// write value to data[head]
	// advance head - watch out for the wrap around: on wrap around head == 0
	// increment count
	return -1;
}

int cb_pop(CircularBuffer *cb, uint8_t *value){
	// check if buffer is empty, if empty return -1
	// read value from data[tail]
	// advance tail - watch out for the wrap around
	// decrement count
	return -1;
}

int cb_is_empty(CircularBuffer *cb){
	if (cb == NULL) {								//
		return -1;
	}
	
	return cb->count == 0;							//
}

int cb_is_full(CircularBuffer *cb){
	if (cb == NULL) {								//
		return -1;
	}
	
	return cb->count == BUFFER_SIZE;				//
}
