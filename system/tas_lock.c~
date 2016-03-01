/* unlock.c - unlock */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  unlock  -  lock implmentation
 *------------------------------------------------------------------------
 */
syscall	tas_lock(
	  int32		*flag		/* initial value of  the lock	*/
	)
{
	intmask	mask;			/* Saved interrupt */
	mask = disable();
	int32 old = *flag;
	*flag = 1;
	restore(mask);
	return old;
}
