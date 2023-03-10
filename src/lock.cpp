#include "lock.h"

Lock::Lock(OutputSwitch *_lock, InputSwitch *state)
{
    lock = _lock;
    _state = state;
}

bool Lock::turn(bool state)
{
    return lock->turn(state);
}

bool Lock::turn_on() 
{
    return lock->turn_on();
}

bool Lock::turn_off() 
{
    return lock->turn_off();
}

bool Lock::is_off()
{
    return _state->is_off();
};
bool Lock::is_on()
{
    return _state->is_on();
};

int Lock::state()
{
    return _state->state();
}
