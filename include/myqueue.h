#ifndef MYQUEUE_H
#define QUEUE_H

#include<xinu.h>

#define QUEUE_SIZE 100

struct q{
	int32 array[QUEUE_SIZE];
	int last;
	int first;
};

typedef struct q queue;
extern syscall que_init(queue* );
extern syscall que_enque(queue* , pid32 );
extern syscall que_deque(queue* );




#endif
