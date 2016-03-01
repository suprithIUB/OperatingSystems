#ifndef BABY_BIRD_H
#define BABY_BIRD_H
#include<xinu.h>
#include<stdlib.h>
#include<mutex.h>

extern volatile int babyBirds;
extern volatile mutex_t baby_mutex;
extern volatile mutex_t mutex;
extern volatile int worms;
extern volatile mutex_t parent_mutex;
extern volatile int parent_itr;
void babyBirdProcess(int);
void parentBirdProcess();
#endif
