
#include<baby_bird.h>



void babyBirdProcess(int babyId){	
	while(1){
		while(tas_lock(&baby_mutex) == 1); //do nothing, wait for the lock to be false
		//critical section
		
		worms--;
		printf("I'm a baby bird: %d, worm count: %d\n", babyId, worms);
		//sleep(1000);
		if(worms <= 0){
			tas_unlock(&parent_mutex);
		}
		else
			tas_unlock(&baby_mutex); //release lock
	}
}

