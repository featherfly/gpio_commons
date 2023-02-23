#ifndef INPUT_SWITCH_H
#define INPUT_SWITCH_H
#include "pin.h"

class InputSwitch {
    protected:
#ifdef CLASS_PROPERTY_AUTO_INIT
    Pin *pin = &Pin(-1, INPUT);
#else
    Pin *pin;
#endif
    bool offState = true;

   public:
    InputSwitch(Pin *_pin);
    InputSwitch(Pin *_pin, bool _offState);
    virtual int state();
    virtual bool is_on();
    virtual bool is_off();
};
#endif
