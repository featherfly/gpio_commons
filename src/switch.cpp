#include "switch.h"

#include <Arduino.h>
#include <ArduinoLog.h>
#include <debugs.h>

Switch::Switch(Pin *_pin) : Switch(_pin, true){};

Switch::Switch(Pin *_pin, bool _offState)
    : InputSwitch(_pin, _offState), OutputSwitch(_pin, _offState) {
    pin = _pin;
    offState = _offState;
    D(Log.infoln(F("switch pin %d, offState %T"), pin->pin(), offState));
};
int Switch::state() { return pin->state(); };
int Switch::state(bool state) { return pin->write(state); };
bool Switch::is_off() {
    int s = state();
    return offState ? s == HIGH : s == LOW;
};
bool Switch::is_on() {
    int s = state();
    return offState ? s == LOW : s == HIGH;
};
bool Switch::turn(bool state) { return pin->write(state); };
bool Switch::turn_on() { return pin->write(!offState); };

bool Switch::turn_off() { return pin->write(offState); };
