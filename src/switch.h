#ifndef SWITCH_H
#define SWITCH_H
#include "pin.h"
#include "input_switch.h"
#include "output_switch.h"

class Switch:public InputSwitch,public OutputSwitch
{
private:
    #ifdef CLASS_PROPERTY_AUTO_INIT
    Pin *pin = &Pin(-1, INPUT);
    #else 
    Pin *pin;
    #endif
    bool offState = true;

public:
    Switch(Pin *_pin);
    Switch(Pin *_pin, bool _offState);
    int state(bool state);
    int state();
    bool turn(bool state);
    bool turn_on();
    bool turn_off();
    bool is_on();
    bool is_off();
};
#endif
