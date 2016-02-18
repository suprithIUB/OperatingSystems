#include <xinu.h>
#include <stdio.h>
#include <stdlib.h>

shellcmd xsh_test(int32 argc, char** argv) {
	printf("Random value: %d\n", rand());

	return 0;
}
