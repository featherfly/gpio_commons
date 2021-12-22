#ifndef LOCK_H
#define LOCK_H

#include <switch.h>
#include <pin.h>

class Lock
{
private:
    int _lockPin;
    int _statePin;
    bool _writeOffState = false;
    bool _readOffState = false;

public:
    Lock(int lockPin, int statePin);
    Lock(int lockPin, int statePin, bool offState);
    Lock(int lockPin, bool writeOffState, int statePin, bool readOffState);
    // void setSwitch(Switch *lockSwitch);
    // void setStatePin(Pin *state);
    void setup(int lockPin, bool writeOffState, int statePin, bool readOffState);

    bool turn(bool state);

    bool turn_on();

    bool turn_off();

    bool is_on();

    bool is_off();

    int state();
};

#endif