#ifndef PIN_H
#define PIN_H

class Pin
{
private:
    int _pin;
    int _mode;
    bool _state;
public:
    Pin(int pin, int mode);

    Pin(int pin, int mode, bool state);

    int read();

    int write(bool state);

    bool state();

    int mode();

    int pin();
};

#endif