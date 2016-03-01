#include <cond.h>


/*
struct cond{
	queue* cqueue;
	int16 var;
};
*/

syscall cond_wait(cond_t* cv, volatile mutex_t* mutex){
	if(cv == NULL)
		return SYSERR;
	pid32 pid = getpid();
	
	que_enque(cv->cqueue, pid);
	mutex_unlock(mutex);
	suspend(pid);
	
	mutex_lock(mutex);
	return OK;
}
