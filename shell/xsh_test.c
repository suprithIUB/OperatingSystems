#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>

volatile int32 counter;

void test_helper(int32 id) {
	while (counter != 0) {
		kprintf("TID: %d Val: %d\n", id, counter--);
		resched();
	}
}

shellcmd xsh_test(int32 argc, char** argv) {
/*	printf("Random value: %d\n", rand());*/

	counter = 20;

	for (uint16 i = 0; i < 10; ++i) {
		resume(create(test_helper, 1024, 20, "test_helper", 1, i));
	}

	return 0;
}
