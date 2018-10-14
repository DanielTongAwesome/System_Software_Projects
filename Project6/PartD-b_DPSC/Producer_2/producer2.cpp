/*

This file is for *Double Producer Single Consumer* --- consumer part
Retrieve data from the datapool -- "MyDataPool"

Author: Zitian Tong
Date Created: 2018/ 10/ 13

*/

#include <stdio.h>
#include <ctime>
#include "..\rt.h"

// create a datapool struct
struct mydatapool2 {
	int x;
};

// create pointer point to the struct
struct mydatapool2 *theDataPool2;

int main() {

	// create datapool
	CDataPool dp2("MyDataPool2", sizeof(mydatapool2));
	theDataPool2 = (struct mydatapool2 *)dp2.LinkDataPool();

	// initialize semaphore
	CSemaphore cs2("CS2", 1, 1);
	CSemaphore ps2("PS2", 0, 1);

	// traffic logic for producer
	printf("Producer 2 is waitting to produce data ... \n");
	for (int i = 0; i < 10; i++) {
		printf("Press [ENTER] to send the data to the datapool .... \n");
		getchar();
		cs2.Wait();
		srand(time(NULL));
		int data = rand() % 40;
		theDataPool2->x = data;
		printf("Producer 2 created a data: %d. \n\n", data);
		ps2.Signal();
	}


	return 0;
}