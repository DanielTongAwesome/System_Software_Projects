// CLamp3Bulb.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include <stdio.h>
#include <array>
#include "CSwitch.h"
#include "CBulb.h"
#include "CLamp3Bulb.h"

// In general, ignore this file, but keep it around if you are using pre-compiled headers.

// constructor set the power of the bulbs
CLamp3Bulb::CLamp3Bulb(int w1, int w2, int w3){

    /*
    newSwitch.turnoff();
    bulb_array[0].setwatts(w1);
    bulb_array[1].setwatts(w2);
    bulb_array[2].setwatts(w3);
    */

   newSwitch = new CSwitch();
   bulb_array[0] = new CBulb(w1);
   bulb_array[1] = new CBulb(w2);
   bulb_array[2] = new CBulb(w3);


    printf("CLamp3Bulb constructor being called ..... \n");
};


// deconstructor
CLamp3Bulb::~CLamp3Bulb(){
	for (int i = 0; i < 3; i++) {
		delete bulb_array[i];
	}
	delete newSwitch;

    printf("CLamp3Bulb deconstructor being called ..... \n");
};


// Trun switch and all 3 bulbs ON 
void CLamp3Bulb::LampOn(){
    newSwitch -> turnon();
    bulb_array[0] -> ON();
    bulb_array[1] -> ON();
    bulb_array[2] -> ON();
};

// Turn switch and 3 bulbs off
void CLamp3Bulb::LampOff(){
    newSwitch -> turnoff();
    bulb_array[0] -> OFF();
    bulb_array[1] -> OFF();
    bulb_array[2] -> OFF();
};


// print out the state of the switch in the Lamp
int CLamp3Bulb::getState(){
    return newSwitch -> getstate();
};

// print the state of the switch and lambs
void CLamp3Bulb::print(){
    newSwitch -> print();
    printf("The current state of the bulb 1: %d. \n", bulb_array[0] -> getstate());
    printf("The current state of the bulb 2: %d. \n", bulb_array[1] -> getstate());
    printf("The current state of the bulb 3: %d. \n", bulb_array[2] -> getstate());
};

//return the power currently actually being consumed by the lambs
int CLamp3Bulb::getPower(){
    int power = bulb_array[0]->getpower() + bulb_array[1]->getpower() + bulb_array[2]->getpower();
    return power;
}

CBulb * CLamp3Bulb::exchange(CBulb * newBulb, int bulb_number)
{
	CBulb *theOldBulb = bulb_array[bulb_number];

	if (newSwitch->getstate() == 1){
		bulb_array[bulb_number] = newBulb;
		bulb_array[bulb_number]->ON();
	}
	else {
		bulb_array[bulb_number] = newBulb;
		bulb_array[bulb_number]->OFF();
	}
	return theOldBulb;
	
};


CLamp3Bulb::CLamp3Bulb(const CLamp3Bulb & theCopiedCLamp){

	newSwitch = new CSwitch(*theCopiedCLamp.newSwitch);

	for (int i = 0; i < 3; i++) {
		bulb_array[i] = new CBulb(*theCopiedCLamp.bulb_array[i]);
	}
};







