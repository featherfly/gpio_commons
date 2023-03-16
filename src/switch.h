#ifndef SWITCH_H
#define SWITCH_H
#include "pin.h"
#include "input_switch.h"

class Switch:public InputSwitch
{
private:
    // #ifdef CLASS_PROPERTY_AUTO_INIT
    // Pin *pin = &Pin(-1, INPUT);
    // #else 
    // Pin *pin;
    // #endif
    // bool offState = true;
    bool _state;

public:
    Switch(Pin *_pin);
    Switch(Pin *_pin, bool _offState);
    bool turn(bool state);
    bool turn_on();
    bool turn_off();
    int state(bool state);
    // int state();
    // bool is_on();
    // bool is_off();
};
#endif
