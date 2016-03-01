#include<myqueue.h>

/*
struct q{
	int32 array[QUEUE_SIZE];
	int last;
	int first;
	int count;
};

*/
syscall que_deque(queue* q){
	intmask	mask;			/* Saved interrupt */
	mask = disable();
	if(q == NULL){
		restore(mask);
		return SYSERR;
	}
	
	//que overflow
	if(q->first ==-1){
		restore(mask);
		return SYSERR;
	}
	
	int32 item = q->array[q->first];
	if(q->first == q->last){
		q->first = -1;
		q->last = -1;
	}
	
	else{
		if(q->first == QUEUE_SIZE-1)
			q->first = 0;
		else
			q->first = q->first +1;
	}
	
	restore(mask);
	return item;	
}
