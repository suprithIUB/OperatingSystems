// **xsh_hello.c**

/*
Operating Systems - Assignment 3

Authors:
Suprith Chandrashekharachar(suprchan),
Dakshi Kumar(dakumar)

Description:
Program to simulate baby bird synchronization experiment.

*/

#include<baby_bird.h>
	
volatile int worms;
volatile int babyBirds;
volatile int32 baby_mutex;
volatile int32 parent_mutex;
volatile int parent_itr = 3;
shellcmd xsh_babybird(int nargs, char* args[]){
	
	
	if(nargs > 3){
		fprintf(stderr, "%s: too many arguments\n", args[0]);
	}
	else if(nargs < 3){
		fprintf(stderr, "%s: usage example\n", args[0]);
	}
	else if(nargs == 3){
		babyBirds = atoi(args[1]);
		worms = atoi(args[2]);
		baby_mutex = lockcreate(1);
		parent_mutex = lockcreate(0);
		//Create processes
		int i;
		resume(create(parentBirdProcess, 100, 20, "parentbird", 0));
		for(i=0; i < babyBirds; i++){
			printf("Creating baby bird: %d", i);
			resume(create(babyBirdProcess, 100, 20, "babybird", 1 , i));
		}
		
		
		
	}

	
}

