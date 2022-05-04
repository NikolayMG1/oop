#pragma once
#include "Event.h"

class System{
    private:
    Event event;

    public:
    System();
    System(const Event&);
    System(const System&);
    ~System();
};