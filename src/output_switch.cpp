#include <ArduinoLog.h>
#include <debugs.h>

#include "output_switch.h"

OutputSwitch::OutputSwitch(Pin *_pin) : OutputSwitch(_pin, true){};

OutputSwitch::OutputSwitch(Pin *_pin, bool _offState) {
    pin = _pin;
    offState = _offState;
    D(Log.infoln(F("OutputSwitch pin %d, offState %T"), pin->pin(), offState));
};
int OutputSwitch::state(bool state) { return pin->write(state); };
bool OutputSwitch::turn(bool state) { return pin->write(state); };
bool OutputSwitch::turn_on() { return pin->write(!offState); };

bool OutputSwitch::turn_off() { return pin->write(offState); };
