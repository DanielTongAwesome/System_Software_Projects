#ifndef __monitor__
#define __monitor__

#include "..\rt.h"
#include <stdio.h>
#include <iostream>


class Monitor {
private:
	int value;			// the data to be protected, in this example a single "int"
	CMutex *theMutex;	// a pointer to a hidden mutex protecting the "value" variable above

public:
	Monitor();
	~Monitor();
	int read();
	void write(int target_value);
	void increment();
};



#endif