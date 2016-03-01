#ifndef MUTEX_H
#define MUTEX_H
#include<xinu.h>


typedef int32 mutex_t;


extern syscall mutex_create(volatile mutex_t*);
extern syscall mutex_lock(volatile mutex_t*);
extern syscall mutex_unlock(volatile mutex_t*);

#endif
