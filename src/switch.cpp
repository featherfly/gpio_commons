#include <Arduino.h>
#include <ArduinoLog.h>
#include "switch.h"

Switch::Switch(Pin *_pin) : Switch(_pin, true){};

Switch::Switch(Pin *_pin, bool _offState)
{
    pin = _pin;
    offState = _offState;
    Log.notice(F("switch pin %d, offState %T," CR), pin->pin(), offState);
};
int Switch::state()
{
    return pin->state();
};
int Switch::state(bool state)
{
    return pin->write(state);
};
bool Switch::is_off()
{
    int s = state();
    return offState ? s == HIGH : s == LOW;
};
bool Switch::is_on()
{
    int s = state();
    return offState ? s == LOW : s == HIGH;
};

bool Switch::turn_on()
{
    return pin->write(!offState);
};

bool Switch::turn_off()
{
    return pin->write(offState);
};
