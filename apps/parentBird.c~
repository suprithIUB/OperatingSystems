
#include<baby_bird.h>



void parentBirdProcess(){	
	int wormsCopy = worms;	
	while(parent_itr > 0){	
		while(tas_lock(&parent_mutex) == 1);
		
		//critical section
		printf("I'm a parent bird: %d\n");
		worms = wormsCopy;
		tas_unlock(&baby_mutex);
		//sleep(1000);
		parent_itr--;
	}
}

