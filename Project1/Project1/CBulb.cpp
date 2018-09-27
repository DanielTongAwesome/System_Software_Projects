// CBulb.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include <stdio.h>
#include "CBulb.h"

// In general, ignore this file, but keep it around if you are using pre-compiled headers.


// default constructor
CBulb::CBulb() {
	state = 0;
	watts = 0;
	printf("CBulb Default Constructor being called .....  \n");
};


// default constructor 
CBulb::CBulb(int set_watts) {
	state = 0;
	watts = set_watts;
	printf("CBulb Set Power Constructor being called .....  \nSet Watts to %d. \n", watts);
};


// print the state of the bulb
void CBulb::print() {
	if (state == 0) {
		printf("State : OFF  \n");
	}
	else {
		printf("State : ON   \n");
	}
};


// set the state of the bulb
void CBulb::set_state(int target_value) {
	state = target_value;
};


// turn on the bulb
void CBulb::ON(void) {
	state = 1;
};


// turn off the bulb
void CBulb::OFF(void) {
	state = 0;
};


// get the current state of the bulb
int CBulb::getstate(void) {
	return state;
};



// set the watts of the light
void CBulb::setwatts(int set_watts) {
	watts = set_watts;
	//printf("test");
};


// get the power of the light 
int CBulb::getpower(void) {
	if (state == 0) {
		return 0;
	}
	else {
		printf("The real time power is %d. \n", watts);
		return watts;
	}
};


// deconstructor
CBulb::~CBulb() {

	printf("CBulb destructor being called ..... \n");
};