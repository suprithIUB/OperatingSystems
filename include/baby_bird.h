#ifndef BABY_BIRD_H
#define BABY_BIRD_H
#include<xinu.h>
#include<stdlib.h>
#include<conditionvar.h>
#include<mutex.h>
//#define mutex_t int32


extern cond_t* cv_worms;
extern cond_t* cv_empty;
extern volatile int babyBirds;
extern volatile mutex_t baby_mutex;
extern volatile mutex_t mutex;
extern volatile int worms;
extern volatile mutex_t parent_mutex;
extern volatile int parent_itr;
void babyBirdProcess(int);
void parentBirdProcess();
/*
syscall mutex_create(volatile mutex_t*);
syscall mutex_lock(volatile mutex_t*);
syscall mutex_unlock(volatile mutex_t*);
syscall cond_init( cond_t*);
syscall cond_wait( cond_t*,volatile mutex_t*);
syscall cond_signal( cond_t*);
*/
#endif
