#include <ArduinoLog.h>
#include <debugs.h>

#include "output_switch.h"

OutputSwitch::OutputSwitch(Pin *pin) : OutputSwitch(pin, true){};

OutputSwitch::OutputSwitch(Pin *pin, bool turnOnState) {
    _out = pin;
    _turnOnState = turnOnState;
    D(Log.infoln(F("OutputSwitch pin %d, turnOnState %T"), pin->pin(), turnOnState));
};

bool OutputSwitch::turn_on() { return _out->write(_turnOnState); };

bool OutputSwitch::turn_off() { return _out->write(!_turnOnState); };
