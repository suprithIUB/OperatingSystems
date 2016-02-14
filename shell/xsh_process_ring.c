// **xsh_hello.c**

/*
Operating Systems - Assignment 2

Authors:
Suprith Chandrashekharachar(suprchan),
Dakshi Kumar(dakumar)

Description:
Program to simulate thread ring - Prints in correct order.

*/

#include<process_ring.h>
	
volatile int box[NUM_PROCESSES];
volatile int rounds = 5;

shellcmd xsh_process_ring(int nargs, char* args[]){
	
	
	if(nargs > 2){
		fprintf(stderr, "%s: too many arguments\n", args[0]);
	}
	else if(nargs <= 2){
		if(nargs == 2){
			rounds = atoi(args[1]);
		}
	
		// assign the counter value for the first/zeroth process
		box[0] = rounds * NUM_PROCESSES;
		
		//Create processes
		int i;
		for(i=0; i < NUM_PROCESSES; i++){
			resume(create(counterDecrementer, 100, 20, "process_ring", 1 , i));
		}
		
		
		
	}

	
}

