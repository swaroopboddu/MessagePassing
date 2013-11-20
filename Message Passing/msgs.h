/*
 * msgs.h
 *
 *  Created on: Nov 17, 2013
 *      Author: satyaswaroop boddu
 */
#include "sem.h"
#ifndef MSGS_H_
#define MSGS_H_
#define N 10
typedef struct message {

	int a[10];
} message;

typedef struct port {
	int in;
	int out;
	message messages[N];
	Semaphore_t empty, full,mutex;
} port;


port setOfPorts[100];

void init_port(int p)
{
	setOfPorts[p].out = 0;
	setOfPorts[p].in = 0;
	CreateSem(&(setOfPorts[p].full),0);
	CreateSem(&(setOfPorts[p].empty),N);
	CreateSem(&(setOfPorts[p].mutex),1);
}

void Send(int p, message msg) {
	P(&(setOfPorts[p].empty));
	P(&(setOfPorts[p].mutex));
	setOfPorts[p].messages[setOfPorts[p].in] = msg;
	setOfPorts[p].in++;
	setOfPorts[p].in = (setOfPorts[p].in) % N;
	V(&(setOfPorts[p].mutex));
	V(&setOfPorts[p].full);

}

void Receive(int p, message *msg) {
	P(&(setOfPorts[p].full));
	P(&(setOfPorts[p].mutex));
	*msg = (setOfPorts[p].messages[setOfPorts[p].out]);
	setOfPorts[p].out = (setOfPorts[p].out + 1) % N;
	V(&(setOfPorts[p].mutex));
	V(&(setOfPorts[p].empty));
}

#endif /* MSGS_H_ */
