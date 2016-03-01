#include<myqueue.h>

/*
struct q{
	int32 array[QUEUE_SIZE];
	int last;
	int first;
	int count;
};

*/

syscall que_init(queue* q){
	q->first = q->last = -1;
	return OK;
}
