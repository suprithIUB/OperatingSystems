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
	

cond_t* cv_worms;
cond_t* cv_empty;
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
		printf("Sizeof: %d", sizeof(cond_t));
		
		//if(cv_worms != NULL)
		cv_worms = (cond_t*) getmem(sizeof(cond_t));
		cv_empty = (cond_t*) getmem(sizeof(cond_t));

		//cond_init(cv_worms);
		//cond_init(cv_empty);
		
		//qid16 q = newqueue();
		//cv_worms->cv_queue = q;
		//cv_worms->cv = 0;
		//cond_init(cv_worms);
		//printf("cv var contents: %d", cv_worms->cv_queue);
		baby_mutex = 1;
		parent_mutex = 0;
		mutex_create(&baby_mutex);
		mutex_create(&parent_mutex);

		//parent_mutex = lockcreate(0);
		
		//cond_init(&noWorms);
		//wormPresence = cond_init(1);
		//Create processes
		int i;
		//printf("q var contents: %d", cv_worms->cv_queue);
		//printf("cv var contents: %d", cv_worms->cv);
		//printf("count var contents: %d", cv_worms->cv_count);
		
		printf("here");
		pid32 pid = create(parentBirdProcess, 1024, 20, "parentbird", 0);
		printf("pid: %d", pid);
		for(i=0; i < babyBirds; i++){
			printf("Creating baby bird: %d", i);
			resume(create(babyBirdProcess, 1024, 20, "babybird", 1 , i));
		}
		
		
		
	}
	//return 0;
	
}

