#include "pump.h"
#include <string>
CRendezvous     r1("MyRendezvous", 4);		// Attempt to create a rendezvous object involving 4 threads


PumpClass::PumpClass(int pump_id)
{
	pump_number = pump_id;
	theMutex = new CMutex("Pump_Pipe_Mutex_" + std::to_string(pump_number));

}

void PumpClass::Serving(int input_pump_speed)
{
	pump_status = 1;
	pump_speed = input_pump_speed;
}

void PumpClass::Stop_Serving()
{
	pump_status = 0;
	pump_speed = 0;
}

PumpClass::~PumpClass()
{
}

// This is the child thread of the main thread
	// this function is to display the pump status
int PumpClass::DisplayPumpStatus(void * ThreadArgs)
{
	int count_loop = 0;

	while (true)
	{
		count_loop++;
		printf("%d Pump No.%d  Current Status: %d Current Pump Speed -- %4d  Current Remaining Oil -- %3d \n", count_loop, pump_number, pump_status, pump_speed, remain_fuel);
		Sleep(2000);
	}
	return 0;
}


// This is the main parent threaad for the class, when we create objects of this class
	// this function is run. Here is creates two child threads of it's own which are just member functions
	// of the same class and have access to the same class member variables, so they communicate with each other
int PumpClass::main()
{
	printf("Creating Pump No.%d ...... \n", pump_number);
	r1.Wait();
	ClassThread<PumpClass> CarPrintThread(this, &PumpClass::DisplayPumpStatus, SUSPENDED, NULL);

	CPipe MyPipe("Pipe" + std::to_string(pump_number));

	CarPrintThread.Resume();

	while (true) {
		remain_fuel = remain_fuel - pump_speed;

		if (remain_fuel < 0) {
			remain_fuel = 0;
		}

		theMutex->Wait();
		MyPipe.Write(&remain_fuel, sizeof(remain_fuel));
		theMutex->Signal();
		Sleep(500);
	}

	CarPrintThread.WaitForThread();

	return 0;
}

