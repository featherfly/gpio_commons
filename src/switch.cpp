#include <Arduino.h>
#include <ArduinoLog.h>
#include "switch.h"

Switch::Switch(Pin *_pin) : Switch(_pin, true){};

Switch::Switch(Pin *_pin, bool _closeState)
{
    pin = _pin;
    closeState = _closeState;
    Log.notice(F("switch pin %d, closeState %T," CR), pin, closeState);
};
int Switch::state()
{
    return pin->state();
};
bool Switch::isClose()
{
    int s = state();
    return closeState ? s == HIGH : s == LOW;
};
bool Switch::isOpen()
{
    int s = state();
    return closeState ? s == LOW : s == HIGH;
};

bool Switch::open()
{
    return pin->write(!closeState);
};

bool Switch::close()
{
    return pin->write(closeState);
};
