#include <ArduinoLog.h>
#include <debugs.h>

#include "input_switch.h"

InputSwitch::InputSwitch(Pin *_pin) : InputSwitch(_pin, true){};

InputSwitch::InputSwitch(Pin *_pin, bool _offState) {
    pin = _pin;
    offState = _offState;
    D(Log.infoln(F("switch pin %d, offState %T"), pin->pin(), offState));
};

int InputSwitch::state() { return pin->state(); };

bool InputSwitch::is_off() {
    int s = state();
    return offState ? s == HIGH : s == LOW;
};

bool InputSwitch::is_on() {
    int s = state();
    return offState ? s == LOW : s == HIGH;
};
