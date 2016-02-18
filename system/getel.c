#include <xinu.h>

uint32 qlen(qid16 q) {
	uint32 els  = 0;
	pid32  curr = queuetab[queuehead(q)].qnext;

	while (curr != queuetail(q)) {
		++els;
		curr = queuetab[curr].qnext;
	}

	return els;
}

/*pid32 getel(qid16 q) {*/
/*	pid32 tail;*/

/*	if (isempty(q)) {*/
/*		return EMPTY;*/
/*	}*/

/*	tail = queuetail(q);*/
/*	return getitem(queuetab[tail].qprev);*/
/*}*/
