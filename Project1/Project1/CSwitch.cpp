// CSwitch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include <stdio.h>
#include "CSwitch.h"


// In general, ignore this file, but keep it around if you are using pre-compiled headers.

// default constructor
CSwitch::CSwitch(){
    state = 0;   // initialize and set the state to 0/off
    printf("CSwitch constructor being called ..... \n");
};


// turn on the switch
void CSwitch::turnon(){
    state = 1;   
};


// turn off the swith
void CSwitch::turnoff(){
    state = 0;
};


// print the current state
void CSwitch::print(){
    if (state == 0) {
		printf("switch state : OFF  \n");
	}
	else {
		printf("switch state : ON   \n");
	}
};


int CSwitch::getstate(){
    return state;
};

// deconstructor
CSwitch::~CSwitch(){
    printf("CSwitch destructor being called ..... \n");
};
