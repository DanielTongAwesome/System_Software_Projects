// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef __CBulb__
#define __CBulb__

// TODO: add headers that you want to pre-compile here
class CBulb {
	int state;
	int watts;

public:
	CBulb();
	CBulb(int set_watts);    // default constructor set state = 0, watts = 0
	void print(); 
	void set_state(int target_value);
	void ON(void);     // Turn ON the Light
	void OFF(void);	// Turn OFF the Light
	int getstate(void);  // return the current state
	void setwatts(int set_watts); // set the watts of the light
	int getpower(void); //get the power of the light
	~CBulb();        // deconstructor
};

#endif //CBulb
