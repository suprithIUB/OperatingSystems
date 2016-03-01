/* unlock.c - unlock */


#include<conditionvar.h>
/*------------------------------------------------------------------------
 *  unlock  -  lock implmentation
 *------------------------------------------------------------------------
 */
syscall	cond_signal(
	  cond_t		*cv)		/* initial value of  the lock	*/
{
	
	resume(dequeue(cv->cv_queue));
	return OK;
}
