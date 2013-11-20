/**
 *
 * Coded by SatyaSwaroop Boddu and MohanRaj Balumuri
 */

#include<stdio.h>
#include<stdlib.h>
#include "threads.h"

typedef struct Semaphore_t
{
	int counter;
	queue SemQ;

}Semaphore_t;

Semaphore_t* CreateSem(Semaphore_t *sem, int value){
	sem->counter = value;
	InitQ(&(sem->SemQ));
	return sem;
}

void P(Semaphore_t * sem) {
	sem->counter--;
	if(sem->counter < 0){

		AddQ(&(sem->SemQ), DelQ(&RunQ));

		if (sem->SemQ.begin != NULL) {
			swapcontext(&(sem->SemQ.begin->prev->context), &(RunQ.begin->context));
		}
		else
			printf("Queue is empty\n");
	}
}

void V(Semaphore_t * sem){
	sem->counter++;
	if(sem->counter <= 0) {
		//wake up one thread
		TCB_t *t = DelQ(&(sem->SemQ));
		AddQ(&RunQ, t);
	}
	yield();
}
