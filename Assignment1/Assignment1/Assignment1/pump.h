#ifndef __pump__
#define __pump__


#include <stdio.h>
#include <iostream>
#include "../rt.h"


class PumpClass : public ActiveClass {

private:

	int pump_number;			// indicate the pump number
	int pump_status = 0;;		// 0 for not using 1 for occupied
	int remain_fuel = 1000;		// the remaining fuel level
	int pump_speed = 0;         // the speed of oil pumping

public:
	PumpClass (int input_pump_number);   // pump class constructor
	void Serving(int input_pump_speed);		// call to pump the oil
	void Stop_Serving();				// Stop the serving
	~PumpClass();						// car class destructor


private:

	int DisplayPumpStatus(void *ThreadArgs) {
		for (int i = 0; i < 10; i++) {
			printf("%d Pump No.%d  Current Status: %d Current Pump Speed -- %4d  Current Remaining Oil -- %3d \n", i, pump_number, pump_status,  pump_speed, remain_fuel);
			Sleep(2000);
		}
		return 0;
	}


	// This is the main parent threaad for the class, when we create objects of this class
	// this function is run. Here is creates two child threads of it's own which are just member functions
	// of the same class and have access to the same class member variables, so they communicate with each other
	int main() {

		ClassThread<PumpClass> CarPrintThread(this, &PumpClass::DisplayPumpStatus, SUSPENDED, NULL);

		string pip_ext;
		if (pump_number == 1) {
			pip_ext = "1";
		}
		else if (pump_number == 2) {
			pip_ext = "2";
		}
		else if (pump_number == 3) {
			pip_ext = "3";
		}
		else{
			pip_ext = "4";
		}


		CPipe MyPipe("Pipe" + pip_ext);
		
		CarPrintThread.Resume();

		for (int i = 0; i < 1000; i++) {
			remain_fuel = remain_fuel - pump_speed;
			MyPipe.Write(&remain_fuel, sizeof(remain_fuel));
			Sleep(10);
		}

		CarPrintThread.WaitForThread();

		return 0;
	}

};






#endif 