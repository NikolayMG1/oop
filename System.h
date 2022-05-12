#pragma once
#include "Event.h"
#include <iostream>
#include <ostream>

class System{
    private:
    int size = 0;
    int capacity = 20;
    Event* events;
    void resize(int& newCapacity);

    public:
    System();
    ~System();
    void addEvent(const Event&);
    Event*const getEvent() const;
    friend std::ostream& operator<<(std::ostream&, const System&);
    int getSize() const;
};