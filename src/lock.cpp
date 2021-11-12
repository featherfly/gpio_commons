#include "lock.h"

Lock::Lock(int lockPin, int statePin):Lock(lockPin, statePin, false) 
{

}

Lock::Lock(int lockPin, int statePin, bool offState):Lock(lockPin, offState, statePin, offState) 
{

}
Lock::Lock(int lockPin, bool writeOffState, int statePin, bool readOffState)
{
    setup(lockPin, writeOffState, statePin, readOffState);
}

void Lock::setup(int lockPin, bool writeOffState, int statePin, bool readOffState)
{
    _lockPin = lockPin;
    _writeOffState = writeOffState;
    _statePin = statePin;
    _readOffState = readOffState;

    pinMode(_lockPin, OUTPUT);
    pinMode(_statePin, INPUT);
}

bool Lock::turn(bool state)
{
    if (_writeOffState == state) 
    {
        return turn_off();
    } else{
        return turn_on();
    }
}

bool Lock::turn_on() 
{
    digitalWrite(_lockPin, !_writeOffState);
    return !_writeOffState;
}

bool Lock::turn_off() 
{
    digitalWrite(_lockPin, _writeOffState);
    return _writeOffState;
}

bool Lock::is_off()
{
    int s = state();
    return _readOffState ? s == HIGH : s == LOW;
};
bool Lock::is_on()
{
    int s = state();
    return _readOffState ? s == LOW : s == HIGH;
};

int Lock::state()
{
    return digitalRead(_statePin);
}
