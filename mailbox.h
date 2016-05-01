/*
 * This file contains functions declarations for manipulating mailboxes.
 */

#ifndef MAILBOX_H
#define MAILBOX_H

#include <pthread.h>

#include "queue.h"

#define NEW_MSG	malloc(sizeof(message));

typedef struct mailbox_s {
	queue q;
} mailbox;

enum mtypes {
	ID,
	MAILBOX,
	SETUP,
	TURN,
	PING,
	PRINT,
	SHUTDOWN
};

typedef struct {
	int integer;
	mailbox* mb;
} msg_data;

typedef struct {
	enum mtypes type;
	msg_data payload;
} message;

pthread_cond_t mailbox_signal;
pthread_mutex_t mailbox_signal_lock;

int mailbox_is_empty(mailbox* mb);
void mailbox_init(mailbox* mb);
message* mailbox_receive(mailbox* mb);
void mailbox_send(mailbox* mb, message* msg);

#endif
