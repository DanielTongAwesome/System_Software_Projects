/*

This file is for *Single Producer Double Consumer* --- consumer part
Retrieve data from the datapool -- "MyDataPool"

Author: Zitian Tong
Date Created: 2018/ 10/ 13

*/

#include <stdio.h>
#include "..\rt.h"

// struct the data struct
// datapool uses the following format
struct mydatapool {
	int x;
};


// pointer to datapool
struct mydatapool *theDataPointer;


int main() {

	// create a datapool and assign pointer to the datapool
	CDataPool dp1("MyDataPool", sizeof(mydatapool));           // initialize the dp1 and declear its size
	theDataPointer = (struct mydatapool *)(dp1.LinkDataPool());  // get pointer to the datapool

	// initialize semaphore
	CSemaphore ps1("PS1", 0, 1);  // producer semaphore and start with 0 max is 1
	CSemaphore cs1("CS1", 1, 1);  // consumer 1 semaphore

	printf("The 1st consumer is running to consume the data .... \n");
	for (int i = 0; i < 10; i++) {
		printf("Check the newly inserted data ... \n");
		// here is the traffic control
		ps1.Wait();
		printf("The data is %d.\n\n", theDataPointer->x);
		cs1.Signal();
	}


	return 0;
}