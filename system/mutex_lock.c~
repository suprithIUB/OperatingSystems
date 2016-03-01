/* unlock.c - unlock */
#include <xinu.h>
#define mutex_t int32


/*------------------------------------------------------------------------
 *  unlock  -  lock implmentation
 *------------------------------------------------------------------------
 */
syscall	mutex_lock(
	  volatile mutex_t*		lock		/* initial value of  the lock	*/
	)
{
	while(tas_lock(lock) == 1);
	return;
}
