
#include<baby_bird.h>



void parentBirdProcess(){	
	int wormsCopy = worms;	
	while(parent_itr > 0){	
		mutex_lock(&parent_mutex);
		//wait here for the signal
		if(worms > 0)
			cond_wait(cond_empty, &parent_mutex);
		
		worms = wormsCopy;
		printf("Parent bird filled the dish with %d worms\n", worms);
		cond_signal(cond_worms);
		mutex_unlock(&parent_mutex);
		
		parent_itr--;
	}
}

