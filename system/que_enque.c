#include<myqueue.h>

/*
struct q{
	int32 array[QUEUE_SIZE];
	int last;
	int first;
	int count;
};

*/
syscall que_enque(queue* q, pid32 pid){
	intmask	mask;			/* Saved interrupt */
	mask = disable();
	if(q == NULL){
		restore(mask);
		return SYSERR;
	}
	
	//que overflow
	if((q->first == 0 && q->last == QUEUE_SIZE-1) || (q->first == q->last+1)){
		restore(mask);
		return SYSERR;
	}
	
	if(q->first == -1){
		q->first = 0;
		q->last = 0;
	}
	
	else{
		if(q->last == QUEUE_SIZE-1)
			q->last = 0;
		else
			q->last = q->last +1;
	}

	q->array[q->last] = pid;
	
	restore(mask);
	return OK;	
}