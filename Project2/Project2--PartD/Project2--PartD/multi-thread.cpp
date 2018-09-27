#include <stdio.h>
#include "..\rt.h"

UINT __stdcall ChildThread(void *args) {

	int MyThreadNumber = *(int*)(args);

	for (int i = 0; i < 100; i++) {
		printf("Child Thread %d \n", MyThreadNumber);
		Sleep(50);
	}
	return 0;
}


/*
UINT __stdcall ChildThread2(void *args) {
	for (int i = 0; i < 100; i++) {
		printf("Hello From Thread 2 \n");
		Sleep(50);
	}
	return 0;
}
*/


int main() {
	/*
	CThread t1(ChildThread1, ACTIVE, NULL);
	CThread t2(ChildThread2, ACTIVE, NULL);

	t1.WaitForThread();
	t2.WaitForThread();
	*/

	int Num[8] = { 0,1,2,3,4,5,6,7 };
	CThread *Thread[8]; // an array of 8 thread pointer

	for (int i = 0; i < 8; i++) {
		printf("Parent Thread: Creating Child Thread %d in Active State\n", i);
		Sleep(500);
		Thread[i] = new CThread(ChildThread, ACTIVE, &Num[i]);
	}


	// wait for thread to terminate, then delete the thread objects
	for (int i = 0; i < 8; i++) {
		Thread[i]->WaitForThread();
		delete Thread[i];
	}
	
	return 0;
}