#ifndef __CSwitch__
#define __CSwitch__

class CSwitch {
    int state;

public:
    CSwitch();   // default constructor initialise and switch to off
    void turnon();
    void turnoff();
    void print();
    int getstate();
    ~CSwitch();
};



#endif //CSwitch
