/* unlock.c - unlock */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  unlock  -  lock implmentation
 *------------------------------------------------------------------------
 */
syscall	tas_unlock(
	  int32		*val		/* initial value of  the lock	*/
	)
{
	intmask	mask;			/* Saved interrupt */
	mask = disable();
	*val = 0;
	restore(mask);
	return;
}
