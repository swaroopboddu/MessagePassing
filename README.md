MessagePassing
==============
Implemented multi threading environment by having server and multiple client threads. To implement context switching, I implemented a Queue and Semaphores. Using these two as the backbone created a thread library to be used by main program. So the server program runs in one thread and rest of the clients run as separate threads. Messages are stored in individual ports of the messages data structure.  Once read are cleared from there. 
