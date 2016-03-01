
#include<baby_bird.h>



void babyBirdProcess(int babyId){	
	while(1){
		
		mutex_lock(&baby_mutex); //do nothing, wait for the lock to be false
		
		//wait here if worms are less than or equal to zero
		if(worms <= 0)
			cond_wait(cond_worms, &baby_mutex);
		worms--;
		printf("Baby bird %d ate a worm, worm count: %d\n", babyId, worms);
		
		if(worms <= 0){
			
			cond_signal(cond_empty);
			
		}
		
		mutex_unlock(&baby_mutex); //release lock
	}
	
	
}

