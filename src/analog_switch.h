#ifndef ANALOG_SWITCH_H
#define ANALOG_SWITCH_H
#include <Arduino.h>
#include "pin.h"
#include "input_switch.h"

class AnalogSwitch : public InputSwitch
{
    private:
    int scale = 0;
public:
    AnalogSwitch(Pin *_pin, int _scale);
    AnalogSwitch(Pin *_pin, bool _offState, int _scale);
    int state();
    bool is_on();
    bool is_off();
};
#endif


