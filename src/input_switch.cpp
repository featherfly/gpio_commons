#include "input_switch.h"

#include <ArduinoLog.h>
#include <debugs.h>

InputSwitch::InputSwitch(Pin *pin) : InputSwitch(pin, true) {}

InputSwitch::InputSwitch(Pin *pin, bool isOnState) {
    in = pin;
    _isOnState = isOnState;
    D(Log.infoln(F("InputSwitch pin %d, isOnState %T"), pin->pin(), _isOnState));
}

int InputSwitch::state() { return in->state(); }

bool InputSwitch::is_off() {
    int s = state();
    return _isOnState ? s == LOW : s == HIGH;
}

bool InputSwitch::is_on() {
    int s = state();
    return _isOnState ? s == HIGH : s == LOW;
}
