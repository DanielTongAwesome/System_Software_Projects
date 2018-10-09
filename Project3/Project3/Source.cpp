#include <stdio.h>
#include <iostream>
#include "car.h"


int main() {
	CarClass car1(1), car2(2), car3(3), car4(4), 
		car5(5), car6(6), car7(7), car8(8), car9(9), car10(10);

	
	car1.Resume();
	car2.Resume();
	car3.Resume();
	car4.Resume();
	car5.Resume();
	car6.Resume();
	car7.Resume();
	car8.Resume();
	car9.Resume();
	car10.Resume();

	car1.Accelerate(10);
	Sleep(500);
	car1.Cruise();
	Sleep(6000);
	car1.Stop();
	car1.WaitForThread();
	car2.WaitForThread();
	car3.WaitForThread();
	car4.WaitForThread();
	car5.WaitForThread();
	car6.WaitForThread();
	car7.WaitForThread();
	car8.WaitForThread();
	car9.WaitForThread();
	car10.WaitForThread();


	return 0;
}