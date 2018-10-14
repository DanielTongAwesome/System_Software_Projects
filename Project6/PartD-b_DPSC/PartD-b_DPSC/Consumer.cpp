/*

This project is for part D of Lab 5
*Double Producer Single Consumer*

  ------------                             -----------                             ------------
 | Producer 1 | ----- creating data -----> | Datapool | -------consume data ----->| consumer 1 |
  ------------						       -----------			  				   ------------
  ------------									^			                                
 | Producer 2 |	----- creating data ------------|										
  ------------																		

Author: Zitian Tong
Date Created: 2018/ 10/ 13

*/

#include <stdio.h>
#include "..\rt.h"



// create a struct for datapool1
struct mydatapool1 {
	int x;
};


// create a struct for datapool2
struct mydatapool2 {
	int x;
};


// create pointer point to the struct
struct mydatapool1 *theDataPool1;
struct mydatapool2 *theDataPool2;


int main() {

	// create datapool and assign pointer to the datapool
	CDataPool dp1("MyDataPool1", sizeof(mydatapool1));
	CDataPool dp2("MyDataPool2", sizeof(mydatapool2));
	theDataPool1 = (struct mydatapool1 *)dp1.LinkDataPool();
	theDataPool2 = (struct mydatapool2 *)dp2.LinkDataPool();

	// initialize semaphore
	CSemaphore cs1("CS1", 1, 1);
	CSemaphore cs2("CS2", 1, 1);
	CSemaphore ps1("PS1", 0, 1);
	CSemaphore ps2("PS2", 0, 1);

	// create process for each producer
	string exec_path = "C:\\Users\\13358\\Dropbox\\CPEN333Windows\\Project6\\PartD-b_DPSC\\Debug\\";
	string exec_producer1 = "Producer_1.exe";
	string exec_producer2 = "Producer_2.exe";

	// process 1 for the producer 1
	CProcess p1(
		exec_path + exec_producer1,
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);

	// process 2 for the producer 2
	CProcess p2(
		exec_path + exec_producer2,
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);

	// traffic logic
	printf("Consumer is running, ready to retrieve the data from producers .... \n\n");
	while(1) {
		// check which producer is pushing the message first
		if (ps1.Read() > 0) {
			ps1.Wait();
			printf("The data sending from producer 1 is %d. \n", theDataPool1->x);
			cs1.Signal();
		}
		else if(ps2.Read() > 0) {
			ps2.Wait();
			printf("The data sending from producer 2 is %d. \n", theDataPool2->x);
			cs2.Signal();
		}
	}

	return 0;
}

