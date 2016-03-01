/* lock.c - lock */

#include <mutex.h>
/*------------------------------------------------------------------------
 *  lock  -  lock implmentation
 *------------------------------------------------------------------------
 */
syscall	mutex_create(
	 volatile mutex_t*		val		/* initial value of  the lock	*/
	)
{
	intmask	mask;			/* Saved interrupt */
	mask = disable();
	if(*val != 1 || *val != 0){
		restore(mask);
		return -1;
	}
		 
	restore(mask);	
	return;
}
