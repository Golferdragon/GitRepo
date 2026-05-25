// author:		Bruce Wheeler
// file name:	CircularBuffer.c
// date:		05/22/26 - Framework Creation

// Section 1.3 Coding Problem 1 - Circular Buffer
// A 16-byte Circular Buffer in C

//		Behavior
//		 cb_push() returns 0 on success and -1 if the buffer is full
//		 cb_pop() returns 0 on success and -1 if the buffer is empty
//		 The buffer should wrap around correctly
//		 Avoid dynamic memory allocation

#include <stdint.h>
#include <stdio.h>

#define BUFFER_SIZE 16

typedef struct {
	uint8_t data[BUFFER_SIZE];
	uint8_t head;
	uint8_t tail;
	uint8_t count;
} CircularBuffer;

void cb_init(CircularBuffer *cb);
int cb_push(CircularBuffer *cb, uint8_t value);
int cb_pop(CircularBuffer *cb, uint8_t *value);
int cb_is_empty(CircularBuffer *cb);
int cb_is_full(CircularBuffer *cb);

int main() {


	
	return 0;
}

void cb_init(CircularBuffer *cb){

}

int cb_push(CircularBuffer *cb, uint8_t value){

}

int cb_pop(CircularBuffer *cb, uint8_t *value){

}

int cb_is_empty(CircularBuffer *cb){

}

int cb_is_full(CircularBuffer *cb){

}
