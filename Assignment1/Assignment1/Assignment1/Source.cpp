#include <stdio.h>
#include <iostream>
#include "pump.h"






int main() {
	PumpClass pump1(1), pump2(2), pump3(3), pump4(4);
	
	CProcess child1("C:\\Users\\13358\\Dropbox\\CPEN333Windows\\Assignment1\\Assignment1\\Debug\\Child1.exe",
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);


	pump1.Resume();
	pump2.Resume();
	pump3.Resume();
	pump4.Resume();

	pump1.Serving(10);
	Sleep(6000);
	pump1.Stop_Serving();



	pump1.WaitForThread();
	pump1.WaitForThread();
	pump1.WaitForThread();
	pump1.WaitForThread();
	pump1.WaitForThread();
	pump1.WaitForThread();
	pump1.WaitForThread();
	pump1.WaitForThread();
	pump1.WaitForThread();
	pump1.WaitForThread();

	

	return 0;
}