
#include<baby_bird.h>



void parentBirdProcess(){	
	int wormsCopy = worms;	
	while(parent_itr > 0){	
		mutex_lock(&parent_mutex);
		printf("I'm a parent bird: %d\n", worms);
		worms = wormsCopy;
		mutex_unlock(&baby_mutex);
		
		parent_itr--;
	}
}

