#include <cond.h>


/*
struct cond{
	queue* cqueue;
	int16 var;
};
*/

syscall cond_signal(cond_t* cv){
	if(cv == NULL)
		return SYSERR;
	pid32 pid = que_deque(cv->cqueue);
	if(pid != NULL || pid >=0){
		resume(pid);
	}
	return OK;
}
