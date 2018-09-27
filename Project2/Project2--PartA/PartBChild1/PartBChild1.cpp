#include <stdio.h>
#include "..\rt.h"


int main(int argc, char *argv[]) {
	int i = 0;

	printf("argc count = %d \n", argc);
	// start to count from 0 to 200, and wait for 50ms for each count
	for (i = 0; i < argc; i++) {
		printf(" argv[%d] = %s\n", i, argv[i]);
		Sleep(1000);
	}

	return 0;	//exit
}
