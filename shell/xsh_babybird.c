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
volatile mutex_t baby_mutex;
volatile mutex_t parent_mutex;
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
		baby_mutex = 1;
		parent_mutex = 0;
		//mutex_create(&baby_mutex);
		//mutex_create(&parent_mutex);

		int i;
		
		pid32 pid = create(parentBirdProcess, 1024, 20, "parentbird", 0);
		printf("pid: %d", pid);
		resume(pid);
		for(i=0; i < babyBirds; i++){
			printf("Creating baby bird: %d", i);
			resume(create(babyBirdProcess, 1024, 20, "babybird", 1 , i));
		}
	
		
	}
	
}

