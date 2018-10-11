#include "..\rt.h"
#include <stdio.h>
#include <iostream>

int main()
{
	CMutex Move_Cursor("Move_Cursor");


	for (int i = 0; i < 10000; i++) {
		Move_Cursor.Wait();
		MOVE_CURSOR(20, 20);	  // move cursor to cords [x,y] = 10,10
		printf("Hello from thread 2\n");
		fflush(stdout);		      	// force output to be written to screen
		Move_Cursor.Signal();
	}

	return 0;
}
