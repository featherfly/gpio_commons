#include "analog_switch.h"

#include <ArduinoLog.h>
#include <debugs.h>

#include "pin.h"

AnalogSwitch::AnalogSwitch(Pin *pin, int scale)
    : AnalogSwitch(pin, true, scale) {}

AnalogSwitch::AnalogSwitch(Pin *pin, bool isOnState, int _scale)
    : InputSwitch(pin, isOnState) {
    scale = _scale;
    D(Log.infoln(F("AnalogSwitch pin %d, isOnState %T, scale %d"), in->pin(),
                 isOnState, scale));
}

// int AnalogSwitch::state() { return in->state(); };

bool AnalogSwitch::is_off() {
    int s = state();
    return _isOnState ? s <= scale : s >= scale;
}

bool AnalogSwitch::is_on() {
    int s = state();
    return _isOnState ? s > scale : s < scale;
}
