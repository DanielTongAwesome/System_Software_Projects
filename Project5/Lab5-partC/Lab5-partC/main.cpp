#include "..\rt.h"
#include <iostream>
#include <stdio.h>
#include "monitor.h"

int target_loop = 100000;
Monitor m1;


UINT __stdcall Increment_Thread(void *args) {

	for (int i = 0; i < target_loop; i++) {
		m1.increment();
	}

	return 0;
}


int main() {

	CThread t1(Increment_Thread, ACTIVE, NULL);
	m1.write(0);

	for (int i = 0; i < target_loop; i++) {
		m1.increment();
	}
	
	t1.WaitForThread();
	printf("The final result of the m1 is: %d \n", m1.read());

	system("PAUSE");
	return 0;
}