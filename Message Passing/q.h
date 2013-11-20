/**
 * Queue program using double linked list program
 *
 * Coded by SatyaSwaroop Boddu and MohanRaj Balumuri
 */
#include<stdio.h>
#include<stdlib.h>
#include "TCB.h"
typedef TCB_t qentry;

/*
 *  Queue container structure
 *
 *  This structure encapsulates a linked list of qentry items.
 */
typedef struct queue {
	 qentry *begin;
} queue;

void InitQ(queue*);
int AddQ(queue*, qentry*);
qentry* DelQ(queue*);
void RotateQ(queue*);



void InitQ(queue *q) {
	if (q || (q = malloc(sizeof(struct queue))) != NULL) {
		q->begin = NULL;
	}

}

int AddQ(queue* q, qentry* value) {
	if (!q) {
		printf("\nQueue is Empty");
		return 0;
	}

		if (q->begin!=NULL) {
			(value)->next = (q->begin);
			(value)->prev = (q->begin)->prev;
			q->begin->prev->next = value;
		(q->begin)->prev = value;

		} else {
			q->begin = value;
			value->next = q->begin;
			value->prev = q->begin;

		}

	return 1;
}

qentry* DelQ(queue* q) {
	qentry *temp;
	if(q->begin==NULL)
		{
			return NULL;
		}
	temp = q->begin;
	if((q->begin->next == q->begin->prev) && (q->begin == q->begin->prev)){

		(q->begin)=NULL;return (temp);}

	else
	{

	(q->begin)->next->prev = (q->begin)->prev;
	(q->begin)->prev->next = (q->begin)->next;
	q->begin = (q->begin)->next;
	return (temp);
	}

}

void RotateQ(queue* q) {
	q->begin = q->begin->next;

}

