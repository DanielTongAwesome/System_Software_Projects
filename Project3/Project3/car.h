#ifndef __CAR__
#define __CAR__

#include <stdio.h>
#include <iostream>
#include "../rt.h"


class CarClass: public ActiveClass {

private:

	int car_number;			// indicate the car number
	int car_speed = 0;;		// car current speed
	int car_accelerate = 0;	// car current acceleration

public:
	CarClass(int car_number);   // car class constructor
	void Accelerate(int acceleration);	// call to accelerate the car
	void Cruise();				// change to cruiser mode
	void Stop();				// stop the vehicle
	~CarClass();				// car class destructor


private:

	int DisplayCarClassData(void *ThreadArgs) {
		for (int i = 0; i < 10; i++) {
			printf("%d Car No.%2d  Current Speed -- %4d  Current Acceleration -- %3d \n", i, car_number, car_speed, car_accelerate);
			Sleep(2000);
		}
		return 0;
	}


	// This is the main parent threaad for the class, when we create objects of this class
	// this function is run. Here is creates two child threads of it's own which are just member functions
	// of the same class and have access to the same class member variables, so they communicate with each other
	int main() {
		
		ClassThread<CarClass> CarPrintThread(this, &CarClass::DisplayCarClassData, SUSPENDED, NULL);
		
		CarPrintThread.Resume();
		for (int i = 0; i < 1000; i++) {
			car_speed = car_speed + car_accelerate;
			Sleep(10);
		}

		CarPrintThread.WaitForThread();

		return 0;
	}

};
	




#endif 