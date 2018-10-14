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
	CSemaphore ps2("PS2", 0, 1);  // producer semaphore and start with 0 max is 1
	CSemaphore cs2("CS2", 1, 1);  // consumer 2 semaphore

	printf("The 2nd consumer is running to consume the data .... \n");
	for (int i = 0; i < 10; i++) {
		printf("Check the newly inserted data ... \n");
		// here is the traffic control
		ps2.Wait();
		printf("The data is %d.\n\n", theDataPointer->x);
		cs2.Signal();
	}


	return 0;
}