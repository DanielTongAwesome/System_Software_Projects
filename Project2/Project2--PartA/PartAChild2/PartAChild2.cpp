#include <stdio.h>
#include "..\rt.h"


int main() {
	int i = 0;

	// start to count from 0 to 200, and wait for 50ms for each count
	for (i = 0; i < 200; i++) {
		printf("Hello from child process 2.....\n");
		Sleep(50);
	}

	return 0;	//exit
}
