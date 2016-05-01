/*
 * This file contains the main function for the Extra Credit assignment.
 * Students will need to make some modifications to this file.  Places where
 * changes WILL need to be made are labeled with FIXME.  Other changes may be
 * made to meet the assignment requirements.
 */

#include "tring.h"

volatile int tracker = 0;
/*
 * static inline void tring_wait(void)
 *
 * This is a convenience function for waiting on the threads.  This is
 * accomplished by waiting on a condition variable.
 *
 */
static inline void tring_wait(void) {
	pthread_mutex_lock(&main_signal_lock);
	pthread_cond_wait(&main_signal, &main_signal_lock);
	pthread_mutex_unlock(&main_signal_lock);
}


/*
 * void tring_protocol_start(mailbox* mb)
 *
 * Code that will cause the threads to
 * start passing whatever messages they need to to meet the assignment goals.
 *
 */
void tring_protocol_start(mailbox* mb) {
	
	printf("Initiating the ordering procedure...\n");
	message* msg = NEW_MSG;
	msg->type = SETUP;
	msg->payload.mb = first_mb;
	msg->payload.integer = MAX_INT;
	mailbox_send(first_mb, msg);
	//Wait for the threads to finish up their business.
	tring_wait();
	free(msg);
	
}



/*
 * inline void tring_signal(void)
 *
 * This is a convenience function for other threads to signal the main thread
 * of execution when important milestones are reached.
 *
 */
void tring_signal(void) {
	pthread_mutex_lock(&main_signal_lock);
	pthread_cond_signal(&main_signal);
	pthread_mutex_unlock(&main_signal_lock);
}

/*
 * mailbox* spawn_thread(mailbox* previous_mb)
 *
 * This function is responsible for starting new threads.  It returns a pointer
 * to the mailbox of the newly created thread.  If a mailbox is given as an
 * argument, this mailbox is given to the new thread as the value for its
 * 'next_mb' variable.
 *
 *
 */
mailbox* spawn_thread(mailbox* previous_mb, pthread_t* thread) {
	//pthread_t thread;
	int ret;
	mailbox* current_mb;
	message* msg;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	//Initialize the new thread's mailbox.
	current_mb = malloc(sizeof(mailbox));
	mailbox_init(current_mb);

	ret = pthread_create(thread, &attr, tring_thread_start, (void*) current_mb);
	pthread_attr_destroy(&attr);
	if(ret != 0){
		printf("Exit due to error in thread creation");
		exit(0);
	}
	
	//thread_array[i++] = thread;
	//Make a new ID message for the new thread.
	msg = NEW_MSG;
	msg->type = ID;
	msg->payload.integer = ids_next();
	
	//Send the message.
	mailbox_send(current_mb, msg);
	tring_wait();
	free(msg);
	if (previous_mb != NULL) {
		//Make a new MAIBLOX message.
		msg = NEW_MSG;
		msg->type = MAILBOX;
		msg->payload.mb = previous_mb; 
		//Send the mssage.
		mailbox_send(current_mb, msg);
		tring_wait();
		free(msg);
	}
	
	return current_mb;
}


/*
 * int main(int argc, char** argv)
 *
 * The main thread of execution for Programming Assignment 2.  It creates the
 * threads, starts the threads to work, asseses the correctness of the solution,
 * and causes them to print out a graph of their connections, then causes them
 * to shutdown.
 *
 *
 */


int main(int argc, char** argv) {
	int num_threads, iter;
	
	mailbox* previous_mb;
	message* msg;

	if (argc == 2) {
		num_threads = atoi(argv[1]);
	} else {
		printf("Usage: ./tring <N>\n\t N: Number of threads to spawn.\n");
		exit(0);
	}

	/********** Initialization Code **********/
	
	tracker = num_threads;
	pthread_t thread_array[num_threads];
	//Initialize the main_signal mutex and CV.
	pthread_mutex_init(&main_signal_lock, NULL);
	pthread_cond_init(&main_signal, NULL);

	pthread_mutex_init(&mailbox_signal_lock, NULL);
	pthread_cond_init(&mailbox_signal, NULL);
	
	

	//Initialize the utility functions.
	ids_init(num_threads);
	tring_print_init();
	pong_init();
	
	/*********** Thread Spawning Code **********/
	
	//Create the first thread.
	first_mb = previous_mb = spawn_thread(NULL, &thread_array[0]);
	//Create the rest of the threads.
	for (iter = 1; iter < num_threads; ++iter) {
		previous_mb = spawn_thread(previous_mb, &thread_array[iter]);
	}
	
	//Give the first thread the mailbox of the last one created.
	msg = NEW_MSG;
	msg->type = MAILBOX;
	msg->payload.mb = previous_mb;
	mailbox_send(first_mb, msg);

	/********** Protocol Start Code **********/

	tring_wait();
	if(msg != NULL)
		free(msg);
	//Run the start code.
	tring_protocol_start(first_mb);
	
	
	printf("Enter Finalization\n");
	/********** Finalization Code **********/
	//Have the threads report in.
	msg = NEW_MSG;
	msg->type = PING;
	mailbox_send(first_mb, msg);
	tring_wait();
	if(msg != NULL)
		free(msg);

	//Have the threads print themselves out.
	msg = NEW_MSG;
	msg->type = PRINT;
	msg->payload.integer = -2;
	mailbox_send(first_mb, msg);
	
	//Wait for the threads to finish ponging and printing.
	tring_wait();
	if(msg != NULL)
		free(msg);

	//Check to see if we have a correct solution.
	if (pong_count() == num_threads) {
		printf("All threads reachable.\n");

		if (pong_check()) {
			printf("All threads in order.\n\nSolution is correct!\n");
		} else {
			printf("One or more threads are out of order.\nIncorrect solution.\n\n");
		}
	} else {
		printf("Only %d of %d threads reachable.\n\nIncorrect solution.\n", pong_count(), num_threads);
	}

	//Finalize the graph and clean up the ids.
	tring_print_finalize();
	ids_cleanup();
	
	/*********** Thread Shutdown Code **********/
	msg = NEW_MSG;
	msg->type = SHUTDOWN;
	msg->payload.mb = NULL;
	mailbox_send(first_mb, msg);
	
	if(msg != NULL)	
		free(msg);
	
	return 0;
}
