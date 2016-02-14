
#include<process_ring.h>

volatile int round_num = 0;

void counterDecrementer(int processID){	
	
	volatile int j = 0;

//--------------------------------------------------
//		Correct ordered printing
//--------------------------------------------------


	while(j < rounds){
		
		//in order printing - synchronization using busy waiting (spinlock)
		if(box[processID] != -1){		
		
				printf("Ring Element %d : Round %d : Value %d \n", processID, j, box[processID]);
				
				box[(processID+1) % NUM_PROCESSES] = --box[processID];
				j++;
				//resetting value for synching		
				box[processID] = -1;
			
		}
	}
	
	// Wait for printing zero!
	if(processID == 0){
		
		while(box[processID] != 0){
			
			if(box[processID] == 0){	
				printf("ZERO!");
				break;
			}								
		}
	}



//--------------------------------------------------
//		Out of order printing
//--------------------------------------------------
/*	

	while(j < rounds){
		
		
		printf("Ring Element %d : Round %d : Value %d \n", processID, j, box[processID]);
		
		box[(processID+1) % NUM_PROCESSES] = --box[processID];
		j++;
		
			
		
	}
*/



//--------------------------------------------------
//		Infinite looping 
//--------------------------------------------------

	/*while(box[processID] > 0)
    	{
		printf("Ring Element %d : Round %d : Value %d \n", processID, round_num, box[processID]);
		box[(processID + 1) % NUM_PROCESSES] = box[processID] - 1;
		if(processID == NUM_PROCESSES - 1) round_num++;
        //sleepms(1);
    	}   */ 



//--------------------------------------------------
//	Hanging processes - Deadlock 
//--------------------------------------------------

/*
	
	while(j < rounds){
		
		//in order printing - synchronization using busy waiting (spinlock)
		if(box[processID] > 0){		
		
				printf("Ring Element %d : Round %d : Value %d \n", processID, j, box[processID]);
				
				box[(processID+1) % NUM_PROCESSES] = -1;
				j++;
				//resetting value for synching		
				box[processID] = -1;
			
		}
	}
	
	// Wait for printing zero!
	if(processID == 0){
		
		while(box[processID] != 0){
			
			if(box[processID] == 0){	
				printf("ZERO!");
				break;
			}								
		}
	}
*/
	
}

