#ifndef BABY_BIRD_H
#define BABY_BIRD_H
#include<xinu.h>
#include<stdlib.h>
#include<mutex.h>
#include<cond.h>

extern volatile int babyBirds;
extern volatile int eat_share;
extern volatile mutex_t baby_mutex;
extern volatile mutex_t mutex;
extern volatile int worms;
extern volatile mutex_t parent_mutex;
extern volatile int parent_itr;
extern volatile int done;
extern volatile int global_worms;
extern cond_t* cond_worms;
extern cond_t* cond_empty;
extern cond_t* cond_kill;
void babyBirdProcess(int);
void parentBirdProcess();
#endif
