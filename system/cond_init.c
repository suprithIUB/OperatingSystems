#include <cond.h>


/*
struct cond{
	queue* cqueue;
	int16 var;
};
*/

syscall cond_init(cond_t* cv){
	static int newcvid = 0;	
	queue* cvque = (queue *) getmem(sizeof(queue));	
	que_init(cvque);
	cv->cqueue = cvque;
	cv->var = newcvid;
	return OK;
}
