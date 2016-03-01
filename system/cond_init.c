/* lock.c - lock */

#include <conditionvar.h>


/*------------------------------------------------------------------------
 *  lock  -  lock implmentation
 *------------------------------------------------------------------------
 */
syscall	cond_init(
	   cond_t*		cv
	)			/* initial value of  the lock	*/
{
	//intmask	mask;			/* Saved interrupt */
	//mask = disable();
	//static int incr = 0;
	qid16 q = newqueue();
	//kprintf("qid: %d", q);
	
	//cv->cv = 0;
	//cv->cv_count = 0;
	
	cv->cv_queue = q;
	//kprintf("qid: %d", cv->cv_queue);
	//restore(mask);	
	return OK;
}
