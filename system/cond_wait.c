/* unlock.c - unlock */


#include<conditionvar.h>

//#define mutex_t int32
//typedef int32 mutex_t;
/*------------------------------------------------------------------------
 *  unlock  -  lock implmentation
 *------------------------------------------------------------------------
 */
syscall	cond_wait(
	   cond_t		*cv		/* initial value of  the lock	*/
	, volatile mutex_t *lock)
{	
	
	enqueue(currpid, cv->cv_queue);
	//cv->cv_count++;
	
	tas_unlock(lock);
	
	suspend(currpid);
	
	while(tas_lock(lock) == 1);
	
	return OK;
}