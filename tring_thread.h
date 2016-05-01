/*
 * This file contains the declaration for tring_thread_start.
 */

#ifndef TRING_THREAD_H
#define TRING_THREAD_H


#include <stdio.h>

#include "mailbox.h"
#include "util.h"
#include "tring.h"
void* tring_thread_start(void* arg);

#endif
