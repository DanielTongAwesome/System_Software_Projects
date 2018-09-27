#include "CLamp3Bulb.h"

#ifndef __CPullLamp__
#define __CPullLamp__


// inheritance
class CPullLamp : public CLamp3Bulb {
private:
	void LampOn() {};  //empty private function
	void LampOff() {}; //empty private function
public:
	CPullLamp(int w1, int w2, int w3);
	~CPullLamp();
	void toggle();
};

#endif