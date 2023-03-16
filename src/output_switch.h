#ifndef OUTPUT_SWITCH_H
#define OUTPUT_SWITCH_H
#include "pin.h"

class OutputSwitch {
   protected:
#ifdef CLASS_PROPERTY_AUTO_INIT
    Pin *pin = &Pin(-1, INPUT);
#else
    Pin *pin;
#endif
    bool offState = true;

   public:
    OutputSwitch(Pin *_pin);
    OutputSwitch(Pin *_pin, bool _offState);
    int state(bool state);
    bool turn(bool state);
    bool turn_on();
    bool turn_off();
};
#endif
