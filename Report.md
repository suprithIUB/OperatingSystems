## Assignment 3:


#Section 1
#Description:
The program works to synchronize baby and parent birds problem using conditon variables and mutexes. The program uses two mutexes, one each for parent bird and baby birds, and two condition variables to avoid busy waiting. The condition variables implmentation internally uses a FIFO circular queue to maintain a list of processes that are waiting on a condition. The queue data struture used is my own implementation and supports system calls for enqueing and dequeing. 

The program has been created using Test and Set lock wiht proper system interrupts disbaling for achieving atomic operations.


#Section 2
What is starvation?
	When two or more processes are competing for a shared resource or critical section execution, one process could get selected/prorotized for execution all the time, either due to synchronization(semaphore) semantics or OS scheduling algorithm, resulting in "starvation" for other processes. So the other processes will not get regular access to shared resources will end up NOT progressing. This could happen if competing processes are greedy and resources are made unavailable for a long time.

The given code is NOT starvation free. Because, in a scenario where two threads are racing to get the lock, one gets the lock and when the other is about to get the lock, the first one to could unlock thereby setting the busy flag to false. So there is starvation here.


What is deadlock?
	It's a situation where two or more threads while waiting for each other are blocked forever.

The given code is deadlock free.

 


