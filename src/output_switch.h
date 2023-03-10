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
    virtual int state(bool state);
    virtual bool turn(bool state);
    virtual bool turn_on();
    virtual bool turn_off();
};
#endif
