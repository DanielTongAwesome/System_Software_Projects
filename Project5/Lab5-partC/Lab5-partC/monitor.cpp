#include "monitor.h"

// constructor
// initialize the value and build the Mutex
Monitor::Monitor()
{
	theMutex = new CMutex("MyValue");
	value = 0;
}

// destructor
// call the destructor and delete the mutex pointer
Monitor::~Monitor()
{
	delete theMutex;
}

// read the value of the Monitor
int Monitor::read()
{
	theMutex->Wait();
	return value;
	theMutex->Signal();
}

// increment the value by 1
void Monitor::increment()
{
	theMutex->Wait();
	value++;
	theMutex->Signal();
}

// write data to the value
void Monitor::write(int target_value)
{
	theMutex->Wait();
	value = target_value;
	theMutex->Signal();
}
