#include <Arduino.h>
#include <ArduinoLog.h>
#include <debugs.h>
#include "pin.h"

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
    D(Log.infoln(F("pin %d, mode %d, state %d"), _pin, _mode, _state));
}

int Pin::read()
{
    if (_mode == INPUT || _mode == INPUT_PULLUP)
    {
        _state = digitalRead(_pin);
        D(Log.traceln(F("Pin[%d].read = %d, mode %d"), _pin, _state, _mode));
        return _state;
    }
    else
    {
        D(Log.traceln(F("Pin[%d].read = %d, mode %d"), _pin, _state, _mode));
        return _state;
    }
}

int Pin::write(bool state)
{
    D(Log.traceln(F("Pin[%d].write(%d), mode %d"), _pin, _state, _mode));
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
    if (_mode == INPUT || _mode == INPUT_PULLUP || _mode == ANALOG)
    {
        return read();
    }    
    return _state;
};
int Pin::mode()
{
    return _mode;
};