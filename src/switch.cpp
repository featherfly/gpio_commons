#include "switch.h"

#include <ArduinoLog.h>
#include <debugs.h>

Switch::Switch(Pin *_pin) : Switch(_pin, true){};

Switch::Switch(Pin *_pin, bool _offState) : InputSwitch(_pin, _offState) {
    pin = _pin;
    offState = _offState;
    D(Log.infoln(F("switch pin %d, offState %T"), pin->pin(), offState));
};
bool Switch::turn(bool state) {
    _state = state;
    return pin->write(state);
};
bool Switch::turn_on() { return turn(!offState); };

bool Switch::turn_off() { return turn(offState); };

int Switch::state(bool state) { return pin->write(state); };
// int Switch::state() { return pin->state(); };
// bool Switch::is_off() {
//     int s = state();
//     return offState ? s == HIGH : s == LOW;
// };
// bool Switch::is_on() {
//     int s = state();
//     return offState ? s == LOW : s == HIGH;
// };