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
struct mydatapool1 {
	int x;
};

// create pointer point to the struct
struct mydatapool1 *theDataPool1;

int main() {

	// create datapool
	CDataPool dp1("MyDataPool1", sizeof(mydatapool1));
	theDataPool1 = (struct mydatapool1 *)dp1.LinkDataPool();

	// initialize semaphore
	CSemaphore cs1("CS1", 1, 1);
	CSemaphore ps1("PS1", 0, 1);

	// traffic logic for producer
	printf("Producer 1 is waitting to produce data ... \n");
	for (int i = 0; i < 10; i++) {
		printf("Press [ENTER] to send the data to the datapool .... \n");
		getchar();
		cs1.Wait();
		srand(time(NULL));
		int data = rand() % 40;
		theDataPool1->x = data;
		printf("Producer 1 created a data: %d. \n\n", data);
		ps1.Signal();
	}


	return 0;
}