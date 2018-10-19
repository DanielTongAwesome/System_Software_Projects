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
	CMutex *theMutex;

public:
	PumpClass (int input_pump_number);   // pump class constructor
	void Serving(int input_pump_speed);		// call to pump the oil
	void Stop_Serving();				// Stop the serving
	~PumpClass();						// car class destructor


private:

	int DisplayPumpStatus(void *ThreadArgs);
	int main();

};






#endif 