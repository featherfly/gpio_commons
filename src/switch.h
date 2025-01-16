#ifndef SWITCH_H
#define SWITCH_H
#include "input_switch.h"
#include "output_switch.h"
#include "pin.h"

class Switch : public InputSwitch, public OutputSwitch {
   public:
    Switch(Pin *_out, Pin *_in);
    Switch(Pin *_out, Pin *_in, bool _offState);
    Switch(Pin *_out, bool _outOffState, Pin *_in, bool _inOffState);
};
#endif
