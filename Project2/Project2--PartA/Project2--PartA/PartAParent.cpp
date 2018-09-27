#include <stdio.h>
#include "..\rt.h"

int main() {
	printf("Creating the child processes ..... \n");

	// Path list child 1 & 2 & 3
	string path_list_child1 = "C:\\Users\\13358\\Dropbox\\CPEN333Windows\\Project2\\Project2--PartA\\Debug\\PartAChild1.exe";
	string path_list_child2 = "C:\\Users\\13358\\Dropbox\\CPEN333Windows\\Project2\\Project2--PartA\\Debug\\PartAChild2.exe";
	string path_list_child3 = "C:\\Users\\13358\\Dropbox\\CPEN333Windows\\Project2\\Project2--PartA\\Debug\\PartAChild3.exe";
	string path_list_partb_child1 = "C:\\Users\\13358\\Dropbox\\CPEN333Windows\\Project2\\Project2--PartA\\Debug\\PartBChild1.exe";


	//	Create process objects p1,p2 and p3. Arguments are as follows
	//	1)	Pathlist to the child process executable i.e. the runnable child program
	//	2)	The process priority. Allowable values are
	//		HIGH_PRIORITY_CLASS	
	//		IDLE_PRIORITY_CLASS
	//		NORMAL_PRIORITY_CLASS	(this is the default if you do not specify). 
	//		REALTIME_PRIORITY_CLASS 	(use with extreme caution)
	//	3)	Whether the child process uses its own window or uses that of the parent. Values are
	//		OWN_WINDOW or PARENT_WINDOW. Default is PARENT_WINDOW	 if not specified
	//	4)	The initial processing state of the process, Allowable values are
	//		ACTIVE or SUSPENDED. Default is ACTIVE if not specifie


	// CProcess p1
	string argc_argv = " a b c d e f g h i j";
	CProcess p1(path_list_child1,
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);

	CProcess p2(path_list_child2,
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);

	CProcess p3(path_list_child3,
		NORMAL_PRIORITY_CLASS, 
		OWN_WINDOW,
		ACTIVE
	);

	

	CProcess PB1(path_list_partb_child1+argc_argv,
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE
	);


	printf("Child Process Activated ...... \n");
	printf("Wait for Child process 1 to terminate ..... \n");
	p1.WaitForProcess();		// wait for child process to end

	printf("Wait for Child process 2 to terminate ..... \n");
	p2.WaitForProcess();		// wait for child process to end

	printf("Wait for Child process 3 to terminate ..... \n");
	p3.WaitForProcess();		// wait for child process to end
	

	printf("Testing the PartB Child 1 ...... \n");
	printf("Testing the Suspend ....... \n");
	PB1.Suspend();
	Sleep(3000);
	printf("Testing the Resume .......  \n");
	PB1.Resume();
	PB1.WaitForProcess();

	system("PAUSE");
	return 0;
}