#ifndef LOCK_H
#define LOCK_H

#include "input_switch.h"
#include "output_switch.h"
#include "pin.h"

class Lock {
   private:
    OutputSwitch *lock;
    InputSwitch *_state;

   public:
    Lock(OutputSwitch *_lock, InputSwitch *_state);

    // void setSwitch(Switch *lockSwitch);
    // void setStatePin(Pin *state);
    void setup(int lockPin, bool writeOffState, int statePin,
               bool readOffState);

    bool turn(bool state);

    bool turn_on();

    bool turn_off();

    bool is_on();

    bool is_off();

    int state();
};

#endif