// **xsh_hello.c**

/*
Operating Systems - Assignment 2

Authors:
Suprith Chandrashekharachar(suprchan),
Dakshi Kumar(dakumar)

Description:
Program to simulate thread ring - Prints out of order.

*/

#include<process_ring_incorrect_order.h>
	
volatile int box1[NUM_PROCESSES];
volatile int rounds1 = 5;

shellcmd xsh_process_ring_incorrect_order(int nargs, char* args[]){
	
	
	if(nargs > 2){
		fprintf(stderr, "%s: too many arguments\n", args[0]);
	}
	else if(nargs <= 2){
		if(nargs == 2){
			rounds1 = atoi(args[1]);
		}
	
		// assign the counter value for the first/zeroth process
		box1[0] = rounds1 * NUM_PROCESSES;
		
		//Create processes
		int i;
		for(i=0; i < NUM_PROCESSES; i++){
			resume(create(counterDecrementerOutOfOrder, 100, 20, "process_ring_incorrect", 1 , i));
		}
		
		
		
	}

	
}

