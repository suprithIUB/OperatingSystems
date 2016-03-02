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

cond_t* cond_worms;
cond_t* cond_empty;
cond_t* cond_kill;	
volatile int worms;
volatile int eat_share;
volatile int babyBirds;
volatile int eat_share;
volatile int global_worms;
volatile int done = 1;
volatile mutex_t baby_mutex;
volatile mutex_t parent_mutex;
volatile mutex_t parent_itr;

shellcmd xsh_babybird(int nargs, char* args[]){
	
	
	if(nargs > 4 ){
		fprintf(stderr, "%s: too many arguments\n", args[0]);
	}
	else if(nargs < 3){
		fprintf(stderr, "%s: usage example\n", args[0]);
		fprintf(stderr, "babybird <number of baby birds> <worms in dish> <each baby's share>\n");
	}
	else if(nargs >= 3){
		babyBirds = atoi(args[1]);
		done = done << babyBirds;
		global_worms = worms = atoi(args[2]);
		eat_share = 1;
		if(nargs == 4)
			eat_share = atoi(args[3]);
		baby_mutex = 0;
		parent_mutex = 0;
		parent_itr = 3;
		
		mutex_create(&baby_mutex);
		mutex_create(&parent_mutex);
		mutex_create(&parent_itr);
		cond_worms = (cond_t *) getmem(sizeof(cond_t));
		cond_init(cond_worms);
		cond_empty = (cond_t *) getmem(sizeof(cond_t));
		cond_init(cond_empty);
		cond_kill = (cond_t *) getmem(sizeof(cond_t));
		cond_init(cond_kill);
		
		int i;
		
		pid32 pid = create(parentBirdProcess, 1024, 20, "parentbird", 0);
		resume(pid);	
		for(i=0; i < babyBirds; i++){
			resume(create(babyBirdProcess, 1024, 20, "babybird", 1 , i));
		}
		
		while(done != 1);
		kill(pid);
		printf("Number of worms left in the dish %d\n", worms);
		
		
	}
	
}

