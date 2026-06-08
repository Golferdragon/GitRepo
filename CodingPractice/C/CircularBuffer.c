// AUTHOR:		Bruce Wheeler
// FILE NAME:	CircularBuffer.c
// DATE:		06/07/2026

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
#include <stdlib.h>
#include <time.h>

// defines
#define BUFFER_SIZE 16

// defining struct for CircularBuffer - organization
typedef struct {
	uint8_t data[BUFFER_SIZE];						// the storage itself
	uint8_t head;									// index of next write location
	uint8_t tail;									// index of next read location
	uint8_t count;									// number of valid bytes currently stored
} CircularBuffer;

// function declarations
// Return Values:
//	 0 	= success
//	-1 	= buffer full / buffer empty
//	-2	= invalid argument / NULL pointer
void cb_init(CircularBuffer *cb);					// #1
int cb_push(CircularBuffer *cb, uint8_t value);		// #4
int cb_pop(CircularBuffer *cb, uint8_t *value);		// #5
int cb_is_empty(CircularBuffer *cb);				// #2
int cb_is_full(CircularBuffer *cb);					// #3

// main - testing and verification of function(s) done here
int main() {
	
	srand((unsigned int)time(NULL));
	
	CircularBuffer test;
	cb_init(&test);

	// after cb_init(), verify initialization
	printf("\nVerification of cb_init(CircularBuffer *cb) function >>> STARTED <<<\n\n");
	
	for (uint8_t i = 0; i < BUFFER_SIZE; i++) {
		printf("Data[%u] = %u\n", i , test.data[i]);
	}
	printf("Head\t= %u\n", test.head);
	printf("Tail\t= %u\n", test.tail);
	printf("Count\t= %u\n", test.count);
	
	printf("\nVerification of cb_init(CircularBuffer *cb) function >>> FINISHED <<<\n");
	
	// cb_is_empty() and cb_is_full() verification
	printf("\nVerification of cb_is_empty(CircularBuffer *cp) & cb_is_full(CircularBuffer *cb) function(s) >>> STARTED <<<\n");
	
	printf("\nFirst: TESTING/VERIFICATION with an empty CircularBuffer.\n");											// scenario #1 - empty
	test.count = 0;																										// simulation of an empty CircularBuffer
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
	test.count = 16;																									// simulation of a full CircularBuffer
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
	test.count = 7;																										// simulation of a partially filled CircularBuffer
	uint8_t verifyEP = cb_is_empty(&test);	
	if (verifyEP == 0) {
		printf("cb_is_empty() \t\t>>> PASSED <<< \tbasic verification: verifyEP= %u | count = %u\n", verifyEP, test.count);
	}
	else {
		printf("cb_is_empty() \t\t>>> NOT PASSED <<< \tbasic verification: verifyEP = %u | count = %u\n", verifyEP, test.count);
	}
	uint8_t verifyFP = cb_is_full(&test);
	if (verifyFP == 0) {
		printf("cb_is_full() \t\t>>> PASSED <<< \tbasic verification: verifyFP= %u | count = %u\n", verifyFP, test.count);
	}
	else {
		printf("cb_is_full() \t\t>>> NOT PASSED <<< \tbasic verification: verifyFP = %u | count = %u\n", verifyFP, test.count);
	}
	
	test.count = 0;
	printf("\nVerification of cb_is_empty(CircularBuffer *cp) & cb_is_full(CircularBuffer *cb) function(s) >>> FINISHED <<<\n");
	
	// cb_push() testing & verification
	printf("\nVerification of cb_push(CircularBuffer *cb, uint8_t value) function(s) >>> STARTED <<<\n");
	
	uint8_t dataIn = (rand() % 256);				// random value with range: 0 to 255 to test with
	printf("\nValue used for Testing\t= %u\n", dataIn);
	
	cb_push(&test, dataIn);
	
	uint8_t last_written_index = (test.head + BUFFER_SIZE - 1) % BUFFER_SIZE;
	printf("\nOutput the CircularBuffer values to check for success.\n");
	printf("Data[%u]\t= %u\n", last_written_index, test.data[last_written_index]);
	printf("Head\t= %u\n", test.head);
	printf("Tail\t= %u\n", test.tail);
	printf("Count\t= %u\n", test.count);
	
	printf("\nVerification of cb_push(CircularBuffer *cb, uint8_t value) function(s) >>> FINISHED <<<\n");
	
	// cb_pop() testing & verification
	printf("\nVerification of cb_pop(CircularBuffer *cb, uint8_t *value) function(s) >>> STARTED <<<\n");
	
	uint8_t dataOut = 0;
	cb_pop(&test, &dataOut);
	
	printf("\nOutput the CircularBuffer values to check for success.\n");
	printf("DataOut\t= %u\n", dataOut);
	printf("Head\t= %u\n", test.head);
	printf("Tail\t= %u\n", test.tail);
	printf("Count\t= %u\n", test.count);
	
	printf("\nVerification of cb_pop(CircularBuffer *cb, uint8_t *value) function(s) >>> FINISHED <<<\n\n");
	
	/*
		Expected Conceptually from the following wraparound test(s)
		- Push 1 through 16
		- Pop 1, 2, 3, 4
		- Push 100, 101, 102, 103
		- Pop remaining values in order:
		  5, 6, 7, ..., 16, 100, 101, 102, 103
	*/
	
	printf("Wraparound Test \t\t>>> STARTED <<<\n");

	cb_init(&test);

	for (uint8_t i = 0; i < BUFFER_SIZE; i++)
	{
		cb_push(&test, i + 1);
	}

	printf("\nAfter filling:\t\thead = %u | tail = %u | count = %u\n\n", test.head, test.tail, test.count);

	uint8_t temp;

	for (uint8_t i = 0; i < 4; i++)
	{
		cb_pop(&test, &temp);
		printf("Popped: %u\n", temp);
	}

	for (uint8_t i = 0; i < 4; i++)
	{
		cb_push(&test, 100 + i);
	}

	printf("\nAfter wraparound pushes:\thead = %u | tail = %u | count = %u\n\n", test.head, test.tail, test.count);

	while (!cb_is_empty(&test))
	{
		cb_pop(&test, &temp);
		printf("Popped: %u\n", temp);
	}

	printf("\nWraparound Test \t\t>>> FINISHED <<<\n\n");
		
	// Testing & Verfication finished, Exiting
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
	if (cb == NULL) {								// safety : avoid a NULL pointer issue
		return -2;
	}
	
	if (cb_is_full(cb)) {						// avoid buffer data being overwritten - return -1 if buffer is full
		return -1;
	}
	
	// can add to CircularBuffer
	cb->data[cb->head] = value;					// write value to data[head]
	cb->head = (cb->head + 1) % BUFFER_SIZE;	// advance head - watch out for the wrap around
	cb->count++;								// increment count
	return 0;									// return 0 on succes
}

int cb_pop(CircularBuffer *cb, uint8_t *value){
	if ((cb == NULL) || (value == NULL)) {			// safety : avoid a NULL pointer issue
		return -2;
	}
	
	if (cb_is_empty(cb)) {						// check if buffer is empty, if empty return -1
		return -1;
	}
	
	// can remove from CircularBuffer
	*value = cb->data[cb->tail];				// read from data[tail] into value
	cb->tail = (cb->tail + 1) % BUFFER_SIZE;	// advance tail - watch out for the wrap around
	cb->count--;								// decrement count
	return 0;									// return 0 on success
}

int cb_is_empty(CircularBuffer *cb){
	if (cb == NULL) {								// safety : avoid NULL pointer issues
		return -2;
	}
	
	return cb->count == 0;							// returns 1 if true (EMPTY), 0 if false (NOT EMPTY)
}

int cb_is_full(CircularBuffer *cb){
	if (cb == NULL) {								// safety : avoid NULL pointer issues
		return -2;
	}
	
	return cb->count == BUFFER_SIZE;				// returns 1 if true (FULL), 0 if false (NOT FULL)
}
