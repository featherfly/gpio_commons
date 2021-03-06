#ifndef SWITCH_H
#define SWITCH_H
#include <Arduino.h>
#include "pin.h"

class Switch
{
private:
    Pin *pin = &Pin(-1, INPUT);
    bool offState = true;
public:
    Switch(Pin *_pin);
    Switch(Pin *_pin, bool _offState);
    int state(bool state);
    int state();
    bool turn_on();
    bool turn_off();
    bool is_on();
    bool is_off();
};
#endif
