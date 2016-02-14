#ifndef PROCESS_RING_H
#define PROCESS_RING_H
#include<xinu.h>
#include<stdlib.h>

#define NUM_PROCESSES 4

extern volatile int box[NUM_PROCESSES];
extern volatile int rounds;
void counterDecrementer(int);
#endif
