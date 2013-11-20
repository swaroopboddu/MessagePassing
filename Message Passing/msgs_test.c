/*
 * msgs_test.c
 *
 *  Created on: Nov 17, 2013
 *      Author: sboddu1
 */

#include "msgs.h"

int sp = 0;
int rp=1;
void server()
{

	message msg;
	message ack;
	init_port(sp);
	while(1)
	{
		Receive(sp,&msg);
		printf("\n\r Server %d: Recieved message from client: %d\r\n",sp,msg.a[0]);
		int rp = msg.a[0];
		ack.a[0]=sp;
		Send(rp, ack);
	}
}

void client()
{
	message msg;
	message recp;
	msg.a[0] = rp;
	init_port(rp);
	int clp=rp;
	rp++;
	rp=rp%100;
	while(1)
	{
		Send(sp, msg);
		Receive(msg.a[0],&recp);
		printf("\n\r Client: %d Sent message to server %d and revieved ack \r \n", clp,sp);

	}

}

int main()
{
	start_thread(server);
    start_thread(client);
    start_thread(client);
    start_thread(client);
    run();
    return 0;

}



