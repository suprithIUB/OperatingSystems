
#include<baby_bird.h>



void babyBirdProcess(int babyId){	
	while(1){
		printf("Inside baby bird:");
		mutex_lock(&baby_mutex); //do nothing, wait for the lock to be false
		//critical section
		//printf("Inside baby bird: %d", worms);
		//while(worms <= 0)		
		//	cond_wait(cv_worms, &baby_mutex);
		worms--;
		printf("I'm a baby bird: %d, worm count: %d", babyId, worms);
		//sleep(1000);
		if(worms <= 0){
			
		//printf("I'm a baby bird: %d, worm count: %d\n", babyId, worms);
			//cond_signal(cv_empty);
			mutex_unlock(&parent_mutex);
		}
		else
			mutex_unlock(&baby_mutex); //release lock
	}
	//kill(getpid());
}
