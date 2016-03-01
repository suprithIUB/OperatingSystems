#ifndef CONDITIONVAR_H
#define CONDITIONVAR_H
#include<xinu.h>
#include<mutex.h>

typedef struct{
	int32 cv;
	//int32 cv_count;
	qid16 cv_queue;
}cond_t;


extern syscall cond_signal(cond_t*);
extern syscall cond_wait(cond_t*, volatile mutex_t*);
extern syscall cond_signal(cond_t*);

#endif
