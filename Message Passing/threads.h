/**
 *
 * Coded by SatyaSwaroop Boddu and MohanRaj Balumuri
 */
#include "q.h"
#define STACK_LENGTH 8192
queue RunQ;

void start_thread(void (*function)(void)) {
	void* stackPtr = (int*) malloc(sizeof(char) * STACK_LENGTH);
	TCB_t *tcb = malloc(sizeof(TCB_t));
	init_TCB(tcb, function, stackPtr, STACK_LENGTH);
	AddQ(&RunQ, tcb);

}

void run()

{
	ucontext_t parent;     // get a place to store the main context, for faking
	getcontext(&parent);   // magic sauce
	if (RunQ.begin != NULL)
		swapcontext(&parent, &((RunQ.begin)->context)); // start the first thread
	else
		printf("\n\rQueue is empty\n\r");
}

void yield() // similar to run
{
	if (RunQ.begin != NULL) {
		RotateQ(&RunQ);
		swapcontext(&(RunQ.begin->prev->context), &(RunQ.begin->context));
	}
	else
		printf("\n\rQueue is empty\n\r");
}
