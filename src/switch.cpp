#include "switch.h"

#include <ArduinoLog.h>
#include <debugs.h>

Switch::Switch(Pin *out, Pin *in)
    : Switch(out, in,  true) {};

Switch::Switch(Pin *out, Pin *in,  bool offState)
    : Switch(out, offState, in, offState) {};

Switch::Switch(Pin *out, bool turnOnState, Pin *in, bool isOnState): InputSwitch(in, isOnState),OutputSwitch(out, turnOnState) {
    D(Log.infoln(F("Switch out_pin %d, outOffState %T, in_pin %d, isOnState %T"), out->pin(), turnOnState, in->pin(), isOnState));
};