
#include<process_ring_incorrect_order.h>



void counterDecrementerOutOfOrder(int processID){	
	
	volatile int j = 0;
	//Print wihtout synchronization
	while(j < rounds1){
		
		
		printf("Ring Element %d : Round %d : Value %d \n", processID, j, box1[processID]);
		
		box1[(processID+1) % NUM_PROCESSES] = --box1[processID];
		j++;
		
			
		
	}


}
