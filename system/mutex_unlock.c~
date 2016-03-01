/* unlock.c - unlock */

#include <xinu.h>
#define mutex_t int32

/*------------------------------------------------------------------------
 *  unlock  -  lock implmentation
 *------------------------------------------------------------------------
 */
syscall	mutex_unlock(
	  volatile mutex_t		*lock		/* initial value of  the lock	*/
	)
{
	tas_unlock(lock);
	return;
}
