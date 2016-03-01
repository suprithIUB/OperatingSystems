/* lock.c - lock */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  lock  -  lock implmentation
 *------------------------------------------------------------------------
 */
syscall	lockcreate(
	  int32		val		/* initial value of  the lock	*/
	)
{
	intmask	mask;			/* Saved interrupt */
	mask = disable();
	if(val != 1 || val != 0){
		restore(mask);
		return -1;
	}
		 
	restore(mask);	
	return val;
}
