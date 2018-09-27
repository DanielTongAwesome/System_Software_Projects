#include <stdio.h>
#include "CPullLamp.h"
#include "CLamp3Bulb.h"


CPullLamp::CPullLamp(int w1, int w2, int w3)
	:CLamp3Bulb(w1, w2, w3)   // call base class constructor with watts
{
	printf("CPullLamp constructor been called ..... \n");
};

CPullLamp::~CPullLamp(){
	printf("CPullLamp destructor been called ..... \n");
};


void CPullLamp::toggle()
{
	if (getState() == 0)	// if lamp is off, i.e. test state of base class
		CLamp3Bulb::LampOn();	// turn on CPulledLamp using base class functions
	else
		CLamp3Bulb::LampOff();
};

