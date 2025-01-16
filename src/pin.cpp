#include "pin.h"

#include <Arduino.h>
#include <ArduinoLog.h>
#include <debugs.h>

Pin::Pin(int pin, int mode) : Pin(pin, mode, false) {}

Pin::Pin(int pin, int mode, bool state) {
    _pin = pin;
    _mode = mode, _state = state;

    pinMode(_pin, _mode);

    if (mode == OUTPUT
#ifdef OUTPUT_OPEN_DRAIN
        || _mode == OUTPUT_OPEN_DRAIN
#endif
        ) {
        write(_state);
    }

    D(Log.infoln(F("pin %d, mode %d, state %d"), _pin, _mode, _state));
}

int Pin::read() {
    switch (_mode){
    case INPUT:
// INPUT_FLOATING == INPUT
// #ifdef INPUT_FLOATING
//     case INPUT_FLOATING:
// #endif
#ifdef INPUT_PULLDOWN
    case INPUT_PULLDOWN:
#endif
    case INPUT_PULLUP:
        _state = digitalRead(_pin);
        D(Log.traceln(F("Pin[%d].read = %d, mode %d"), _pin, _state, _mode));
        return _state;
#ifdef ANALOG
    case ANALOG:
        _state = analogRead(_pin);
        D(Log.traceln(F("Pin[%d].read = %d, mode %d[ANALOG]"), _pin, _state, _mode));
        return _state;    
#endif // ANALOG
#ifdef INPUT_ANALOG
    case INPUT_ANALOG:
        _state = analogRead(_pin);
        D(Log.traceln(F("Pin[%d].read = %d, mode %d[ANALOG]"), _pin, _state, _mode));
        return _state;    
#endif // INPUT_ANALOG
    default:
        D(Log.traceln(F("Pin[%d].read = %d, mode %d"), _pin, _state, _mode));
        return _state;
    }
}

int Pin::write(bool state) {
    D(Log.traceln(F("Pin[%d].write(%d), mode %d"), _pin, _state, _mode));
    if (_mode == OUTPUT
#ifdef OUTPUT_OPEN_DRAIN
        || _mode == OUTPUT_OPEN_DRAIN
#endif
    ) {
        digitalWrite(_pin, state);
        _state = state;
    }
    return _state;
}
int Pin::pin() { return _pin; };
bool Pin::state() {
    if (_mode == INPUT || _mode == INPUT_PULLUP
#if defined(ANALOG)
        || _mode == ANALOG
#elif defined(INPUT_ANALOG)
        || _mode == INPUT_ANALOG
#endif
    ) {
        return read();
    }
    return _state;
};
int Pin::mode() { return _mode; };