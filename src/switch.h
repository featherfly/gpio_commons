#ifndef SWITCH_H
#define SWITCH_H
#include <Arduino.h>
#include "pin.h"

class Switch
{
private:
    Pin *pin = &Pin(-1, INPUT);
    bool closeState = true;
public:
    Switch(Pin *_pin);
    Switch(Pin *_pin, bool _closeState);
    int state(bool state);
    int state();
    bool isClose();
    bool isOpen();
    bool open();
    bool close();
};
#endif
