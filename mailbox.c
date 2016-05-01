/*
 * This file contains functions for manipulating mailboxes.  Students will
 * need to make these functions threadsafe.
 */

#include "mailbox.h"

/*
 * void mailbox_init(mailbox* mb)
 *
 * This function is used to initialize the resources used by a mailbox (mb).
 *
 * You will need to change this function to make the other two threadsafe.
 *
 */



void mailbox_init(mailbox* mb) {
	//Initialize the queue.
	pthread_mutex_lock(&mailbox_signal_lock);
	queue_init(&(mb->q));
	pthread_mutex_unlock(&mailbox_signal_lock);
}

/*
 * message* mailbox_receive(mailbox* mb)
 *
 * This function is used to retreive a message from a mailbox (mb).
 *
 * This function should be made threadsafe.
 *
 */

int mailbox_is_empty(mailbox* mb){
	return queue_is_empty(&(mb->q));
}

message* mailbox_receive(mailbox* mb) {
		
	return (message*) queue_pop(&(mb->q));
	
}

/*
 * void mailbox_send(mailbox* mb, message* msg)
 *
 * This function is use to send a message (msg) to a mailbox (mb).
 *
 * This function should be made threadsafe.
 *
 */
void mailbox_send(mailbox* mb, message* msg) {
	pthread_mutex_lock(&mailbox_signal_lock);
	queue_push(&(mb->q), msg);
	pthread_mutex_unlock(&mailbox_signal_lock);
}


