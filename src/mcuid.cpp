#include "mcuid.h"

#include <Arduino.h>
#include <EEPROM.h>

Mcuid::Mcuid(int seed) : Mcuid(seed, 255) {};
Mcuid::Mcuid(int seed, int defaultValue)
{
    _defaultValue = defaultValue;
    if (EEPROM.read(START_ADDRESS) == START_CHAR && EEPROM.read(END_ADDRESS) == END_CHAR)
    {
        _init = true;
    }

    if (!_init)
    {
        randomSeed(seed);

        EEPROM.write(START_ADDRESS, START_CHAR);
        for (int address = 1; address < END_ADDRESS; address++)
        {
            _id[address - 1] = random_chars[random(0, 36)];
            EEPROM.write(address, _id[address - 1]);
        }
        EEPROM.write(END_ADDRESS, END_CHAR);
    }
}

char* Mcuid::id()
{
    return _id;
}

int Mcuid::len()
{
    return _len;
}

void Mcuid::clear()
{
    for (int address = 0; address < END_ADDRESS + 1; address++)
    {
        EEPROM.write(address, _defaultValue);
    }
}