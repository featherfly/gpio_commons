#include "analog_switch.h"

#include <Arduino.h>
#include <ArduinoLog.h>
#include <debugs.h>

#include "pin.h"

AnalogSwitch::AnalogSwitch(Pin *_pin, int _scale)
    : AnalogSwitch(_pin, true, _scale){

      };

AnalogSwitch::AnalogSwitch(Pin *_pin, bool _offState, int _scale)
    : InputSwitch(_pin, _offState) {
    pin = _pin;
    offState = _offState;
    scale = _scale;
    D(Log.infoln(F("switch pin %d, offState %T, scale %d"), pin->pin(),
                 offState, scale));
};
int AnalogSwitch::state() { return pin->state(); };
bool AnalogSwitch::is_off() {
    int s = state();
    return offState ? s > scale : s < scale;
};
bool AnalogSwitch::is_on() {
    int s = state();
    return offState ? s <= scale : s >= scale;
};
