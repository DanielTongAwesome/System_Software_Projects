#include <stdio.h>
#include "car.h"

CarClass::CarClass(int input_car_number)
{
	car_number = input_car_number;
	printf("Car %d has been created \n", car_number);
}

void CarClass::Accelerate(int acceleration)
{
	car_accelerate = acceleration;
	printf("Car %d starts to accelerate ! Accelearation = %d \n", car_number, car_accelerate);	
}

void CarClass::Cruise()
{	
	car_accelerate = 0;
	printf("Car %d starts to curise control, speed = %d \n", car_number, car_speed);
}

void CarClass::Stop()
{	
	car_speed = 0;
	car_accelerate = 0;

	printf("Car %d stop ... \n", car_number);
}


CarClass::~CarClass()
{
}
