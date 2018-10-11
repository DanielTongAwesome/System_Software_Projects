#include "..\rt.h"
#include <stdio.h>
#include <iostream>

int main()
{
	CMutex Move_Cursor("Move_Cursor");

	CProcess Child(
		"C:\\Users\\13358\\Dropbox\\CPEN333Windows\\Project5\\Lab5-partB\\Debug\\Child1.exe",
		NORMAL_PRIORITY_CLASS,		// priority
		PARENT_WINDOW,					// process has it's own window
		ACTIVE						// process is active immediately
	);


	for (int i = 0; i < 10000; i++) {
		Move_Cursor.Wait();
		MOVE_CURSOR(10, 10);	  // move cursor to cords [x,y] = 10,10
		printf("Hello from main thread \n");
		fflush(stdout);		      	// force output to be written to screen
		Move_Cursor.Signal();
	}

	Child.WaitForProcess();
	return 0;
}
