/* unlock.c - unlock */

#include <mutex.h>

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
