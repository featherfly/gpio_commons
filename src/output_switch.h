#ifndef OUTPUT_SWITCH_H
#define OUTPUT_SWITCH_H
#include "pin.h"

class OutputSwitch {
   protected:
#ifdef CLASS_PROPERTY_AUTO_INIT
    Pin *_out = &Pin(-1, INPUT);
#else
    Pin *_out;
#endif
    bool _turnOnState = true;

   public:
    OutputSwitch(Pin *pin);
    OutputSwitch(Pin *pin, bool turnOnState);
    bool turn(bool state);
    bool turn_on();
    bool turn_off();
};
#endif
