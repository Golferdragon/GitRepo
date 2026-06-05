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
#include <stddef.h>
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
	printf("\nVerification of cb_is_empty(CircularBuffer *cp) & cb_is_full(CircularBuffer *cb) function(s) >>> STARTED <<<\n");
	
	printf("\nFirst: TESTING/VERIFICATION with an empty CircularBuffer.\n");											// scenario #1 - empty
	uint8_t verifyEE = cb_is_empty(&test);	
	if (verifyEE == 1) {
		printf("cb_is_empty() \t\t>>> PASSED <<< \tbasic verification: verifyEE = %u | count = %u\n", verifyEE, test.count);
	}
	else {
		printf("cb_is_empty() \t\t>>> NOT PASSED <<< \tbasic verification: verifyEE = %u | count = %u\n", verifyEE, test.count);
	}
	uint8_t verifyFE = cb_is_full(&test);
	if (verifyFE == 0) {
		printf("cb_is_full() \t\t>>> PASSED <<< \tbasic verification: verifyFE = %u | count = %u\n", verifyFE, test.count);
	}
	else {
		printf("cb_is_full() \t\t>>> NOT PASSED <<< \tbasic verification: verifyFE = %u | count = %u\n", verifyFE, test.count);
	}
	
	printf("\nSecond: TESTING/VERIFICATION with a full CircularBuffer.\n");												// scenario #2 - full
	test.count = 16;
	uint8_t verifyEF = cb_is_empty(&test);	
	if (verifyEF == 0) {
		printf("cb_is_empty() \t\t>>> PASSED <<< \tbasic verification: verifyEF = %u | count = %u\n", verifyEF, test.count);
	}
	else {
		printf("cb_is_empty() \t\t>>> NOT PASSED <<< \tbasic verification: verifyEF = %u | count = %u\n", verifyEF, test.count);
	}
	uint8_t verifyFF = cb_is_full(&test);
	if (verifyFF == 1) {
		printf("cb_is_full() \t\t>>> PASSED <<< \tbasic verification: verifyFF = %u | count = %u\n", verifyFF, test.count);
	}
	else {
		printf("cb_is_full() \t\t>>> NOT PASSED <<< \tbasic verification: verifyFF = %u | count = %u\n", verifyFF, test.count);
	}
	
	printf("\nThird: TESTING/VERIFICATION with a partially filled CircularBuffer - neither full nor empty.\n");			// scenario #3 - partially filled
	test.count = 7;
	uint8_t verifyEP = cb_is_empty(&test);	
	if (verifyEP == 0) {
		printf("cb_is_empty() \t\t>>> PASSED <<< \tbasic verification: verifyEP = %u | count = %u\n", verifyEP, test.count);
	}
	else {
		printf("cb_is_empty() \t\t>>> NOT PASSED <<< \tbasic verification: verifyEP = %u | count = %u\n", verifyEP, test.count);
	}
	uint8_t verifyFP = cb_is_full(&test);
	if (verifyFP == 0) {
		printf("cb_is_full() \t\t>>> PASSED <<< \tbasic verification: verifyFP = %u | count = %u\n", verifyFP, test.count);
	}
	else {
		printf("cb_is_full() \t\t>>> NOT PASSED <<< \tbasic verification: verifyFP = %u | count = %u\n", verifyFP, test.count);
	}	
	
	printf("\nVerification of cb_is_empty(CircularBuffer *cp) & cb_is_full(CircularBuffer *cb) function(s) >>> FINISHED <<<\n\n");
	
	// cb_push() testing & verification
	
	
	// cb_pop() testing & verification
	
	
	return 0;
}

// function definitions
void cb_init(CircularBuffer *cb){
	if (cb == NULL) {								// avoid a NULL pointer issue
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
	//if (cb == NULL) {								// safety : avoid a NULL pointer issue
	//	return -2;
	//}
	//elif (cb_is_full(cb)) {						// avoid buffer overflow - program requirement for return value
	//	return -1;
	//}
	//else {										// can add to CircularBuffer
	//	write value to data[head]
	//	advance head - watch out for the wrap around: on wrap around head == 0
	//	increment count
	//	return 0;
	//}
	return 0;
}

int cb_pop(CircularBuffer *cb, uint8_t *value){
	// check if buffer is empty, if empty return -1
	// read value from data[tail]
	// advance tail - watch out for the wrap around
	// decrement count
	return 0;
}

int cb_is_empty(CircularBuffer *cb){
	if (cb == NULL) {								// safety : avoid NULL pointer issues
		return -1;
	}
	
	return cb->count == 0;							// returns 1 if true (EMPTY), 0 if false (NOT EMPTY)
}

int cb_is_full(CircularBuffer *cb){
	if (cb == NULL) {								// safety : avoid NULL pointer issues
		return -1;
	}
	
	return cb->count == BUFFER_SIZE;				// returns 1 if true (FULL), 0 if false (NOT FULL)
}
