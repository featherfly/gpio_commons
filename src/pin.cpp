#include "pin.h"
#include <Arduino.h>
#include <ArduinoLog.h>

Pin::Pin(int pin, int mode) : Pin(pin, mode, false) {}

Pin::Pin(int pin, int mode, bool state)
{
    _pin = pin;
    _mode = mode,
    _state = state;

    pinMode(_pin, _mode);

    if (mode == OUTPUT) 
    {
        write(_state);
    }
    Log.notice(F("pin %d, mode %d, state %d," CR), _pin, _mode, _state);
}

int Pin::read()
{
    if (_mode == INPUT || _mode == INPUT_PULLUP)
    {
        _state = digitalRead(_pin);
        return _state;
    }
    else
    {
        return _state;
    }
}

int Pin::write(bool state)
{
    if (_mode == OUTPUT)
    {
        digitalWrite(_pin, state);
        _state = state;
    }
    return _state;
}
int Pin::pin()
{
    return _pin;
};
bool Pin::state()
{
    return _state;
};
int Pin::mode()
{
    return _mode;
};