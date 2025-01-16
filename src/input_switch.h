#ifndef INPUT_SWITCH_H
#define INPUT_SWITCH_H
#include "pin.h"

class InputSwitch {
    protected:
#ifdef CLASS_PROPERTY_AUTO_INIT
    Pin *in = &Pin(-1, INPUT);
#else
    Pin *in;
#endif
    bool _isOnState = true;

   public:
    InputSwitch(Pin *pin);
    InputSwitch(Pin *pin, bool isOnState);
    int state();
    bool is_on();
    bool is_off();
};
#endif
