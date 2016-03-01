
#include<baby_bird.h>



void parentBirdProcess(){	
	int wormsCopy = worms;	
	while(parent_itr > 0){	
		printf("I'm a parent bird: %d\n", worms);
		mutex_lock(&parent_mutex);
		//while(worms > 0)		
		//cond_wait(cv_empty, &parent_mutex);
		//critical section
		printf("I'm a parent bird: %d\n", worms);
		worms = wormsCopy;
		//cond_signal(cv_worms);
		mutex_unlock(&baby_mutex);
		//mutex_unlock(&parent_mutex);
		//sleep(1000);
		parent_itr--;
	}
	//kill(getpid());
}

