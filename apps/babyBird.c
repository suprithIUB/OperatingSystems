
#include<baby_bird.h>



void babyBirdProcess(int babyId){	
	while(1){
		printf("Inside baby bird:");
		mutex_lock(&baby_mutex); //do nothing, wait for the lock to be false
		
		worms--;
		printf("I'm a baby bird: %d, worm count: %d\n", babyId, worms);
		
		if(worms <= 0){
			
		
			mutex_unlock(&parent_mutex);
		}
		else
			mutex_unlock(&baby_mutex); //release lock
	}
	
}

