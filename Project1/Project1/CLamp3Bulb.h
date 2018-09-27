#include "CBulb.h"
#include "CSwitch.h"
#include <stdio.h>
#include <array>



#ifndef __CLamp3Bulb__
#define __CLamp3Bulb__

class CLamp3Bulb  {
    CSwitch *newSwitch;
    CBulb *bulb_array[3];

public:
    CLamp3Bulb(int w1, int w2, int w3);  // constructor declearation
    ~CLamp3Bulb();  // deconstructor declearation
    int getState(); // return the state of the switch in the Lamp
    void print();   // print the state of the switch and lambs
	void LampOn();  // Trun switch and all 3 bulbs ON
	void LampOff(); // Trun switch and all 3 bulbs OFF
	int getPower(); //return the power currently actually being consumed by the lambs
    CBulb *exchange(CBulb *newBulb, int bulb_number); // swtich the bulb
	CLamp3Bulb(const CLamp3Bulb &theCopiedCLamp); //copy constructor
};

#endif