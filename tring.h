/*
 * This file contains global resources that may be used in completing this
 * assignment, as well as an convenience function that can be used to signal the
 * main thread of execution at important milestones.
 */

#ifndef TRING_H
#define TRING_H


#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "mailbox.h"

#include "tring_thread.h"
#include "util.h"


pthread_cond_t main_signal;
pthread_mutex_t main_signal_lock;

static const int MAX_INT = 3000;
extern volatile int tracker;

mailbox* first_mb;

void tring_signal(void);

#endif
