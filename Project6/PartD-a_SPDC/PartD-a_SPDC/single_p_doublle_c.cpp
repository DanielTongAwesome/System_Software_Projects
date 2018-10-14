/*

This project is for part D of Lab 5
*Single Producer Double Consumer* 

  ------------                             ----------                             ------------
 | Producer 1 |----- creating data -----> | Datapool | -------consume data ----->| consumer 1 |
  ------------						       ----------			  				  ------------
	    										|                                 ------------
			     							    -------------consume data -----> | consumer 2 |
																				  ------------

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
struct	mydatapool	*theDataPointer;

int main() {

	// create a datapool and assign pointer to the datapool
	CDataPool dp1("MyDataPool", sizeof(mydatapool));		   // initialize the dp1 and declear its size
	theDataPointer = (struct mydatapool *)dp1.LinkDataPool();  // get pointer to the datapool

	// initialize semaphore
	CSemaphore ps1("PS1", 0, 1);  // producer semaphore and start with 0 max is 1
	CSemaphore ps2("PS2", 0, 1);  // producer semaphore and start with 0 max is 1
	CSemaphore cs1("CS1", 1, 1);  // consumer 1 semaphore
	CSemaphore cs2("CS2", 1, 1);  // consumer 2 semaphore

	// create threads
	string exec_path = "C:\\Users\\13358\\Dropbox\\CPEN333Windows\\Project6\\PartD-a_SPDC\\Debug\\";
	string exec_Consumer1 = "Consumer_1.exe";
	string exec_Consumer2 = "Consumer_2.exe";

	// process 1 for consumer 1
	CProcess p1(
		exec_path + exec_Consumer1,
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);
		
	// process 2 for consumer 2
	CProcess p2(
		exec_path + exec_Consumer2,
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);


	printf("The producer is running to create the data .... \n");

	// create and insert data into the datapool in each loop
	for (int i = 0; i < 10; i++) {
		printf("Press [enter] to insert new data into the datapool: \n");
		getchar();
		cs1.Wait();
		cs2.Wait();
		theDataPointer->x = i;
		ps1.Signal();
		ps2.Signal();
	}

	//p1.WaitForProcess();
	//p2.WaitForProcess();
	return 0;
}