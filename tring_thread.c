/*
 * This file contains the code for a extra credit assignment worker thread.
 * The main thread of execution will start a thread by using tring_thread_start.
 * Most of a student's work will go into this file.
 *
 */

#include "tring_thread.h"



// Function to set the id of the thread. Input from main thread via a mailbox message

void setID(volatile int *id, message* mail){
	
	*id = mail->payload.integer;
	//printf("Got my new id from main %d\n", *id);	
	
}


/*
 * void* tring_thread_start(void* arg)
 *
 * This function is used in the creating of worker threads for this assignment.
 * Its parameter 'arg' is a pointer to a thread's designated mailbox.  The
 * thread should exit with a NULL pointer.
 *
 */

void* tring_thread_start(void* arg) {
	volatile int id = -2;
	mailbox* mb, * next_mb = NULL;
	int turn = 0;
	volatile int processed = 0;
	mailbox* copy_next = NULL;
	mb = (mailbox *) arg;
	
	while(mb != NULL){
		
		if(!mailbox_is_empty(mb))
		{
			
			message* incoming_mail = mailbox_receive(mb);
			
			if(incoming_mail != NULL)
			{
			
			int MAIL_TYPE = incoming_mail->type;
			
			switch (MAIL_TYPE){
				case 0:	if(id == -2){
						
						setID(&id, incoming_mail);
						tring_signal();
					}
					
					break;
					
				case 1: if(processed == 0){
						if(next_mb == NULL){
							//Set next mailbox the first time
							next_mb = incoming_mail->payload.mb;
							tring_signal();
						}
						else{ // if next_mb is set
							if(turn == 1){ 
								//we have completed one circle, reset next. But keep a copy of old links until all the ordering is done
								copy_next = next_mb;
								next_mb = incoming_mail->payload.mb;
								// Set next mb with smallest node
								processed = 1;
								--tracker;
								if(tracker == 0){
									printf("***Ordering completed***\n");
									next_mb = NULL;
									tring_signal();
								}
								else{
									incoming_mail->type = TURN;
									mailbox_send(next_mb, incoming_mail);
								}
							}
							else if(incoming_mail->payload.integer > id) // set current id as payload integer if it's lesser than payload int and forward
							{
								incoming_mail->payload.integer = id;
								incoming_mail->payload.mb = mb;
								mailbox_send(next_mb, incoming_mail);
							
							}
							
							else{
								mailbox_send(next_mb, incoming_mail);
							}
							
						}
					
					}else{
						//Once a node is processed, it just acts as a forwarder using old links stored in copy_next
						if(tracker == 0){
							printf("***Ordering completed***\n");
							tring_signal();
						}	
						else						
							mailbox_send(copy_next, incoming_mail);
					}
							
					break;
				
				case 2: if(incoming_mail->payload.integer > id)
					{
						incoming_mail->payload.integer = id;
						incoming_mail->payload.mb = mb;
						mailbox_send(next_mb, incoming_mail);
					}
					else if(next_mb == first_mb){ // we have reached the end of the chain and we have the smallest in assigned set, reset first_mb. It's the first step in ordering
						first_mb = incoming_mail->payload.mb;
						incoming_mail->type = TURN;
						
						mailbox_send(first_mb, incoming_mail);
					}
					else
						mailbox_send(next_mb, incoming_mail);	
					break;
				
				case 3: turn = 1; // Find next smallest for a given node
					incoming_mail->type = MAILBOX;
					incoming_mail->payload.integer = MAX_INT;
					printf("Finding next smallest node for thread with id: %d\n", id);
					mailbox_send(next_mb, incoming_mail);
					break;	
				case 4:	// Pong code
					pong(id);
					
					if(next_mb == NULL)
						tring_signal();
					else
						mailbox_send(next_mb, incoming_mail);
					break;
				case 5: { // Print in a linear manner	
						int payload = incoming_mail->payload.integer;
						
						if(payload == -2){
							incoming_mail->payload.integer = id;
							mailbox_send(next_mb, incoming_mail);
						}
						else{
							tring_print(payload, id);
							if(next_mb != NULL){
								incoming_mail->payload.integer = id;
								mailbox_send(next_mb, incoming_mail);
							}
							else{
								
								tring_signal();
							}
						}
					}			
					break;
				case 6: //Shutdown code, free self mailbox and free the next
					free(mb);
					copy_next = NULL;
					mailbox_send(next_mb, incoming_mail);
					break;
				
				}
			}
			}
		}
	
	
	return NULL;
}
