#pragma once
#include "Event.h"
#include <iostream>
#include <ostream>

class System{
    private:
    unsigned size = 0;
    unsigned capacity = 20;
    Event* events;
    Hall* halls;
    void resize(unsigned& newCapacity);
    void free();

    public:
    System();
    ~System();
    void addEvent(const Event&);
    //void removeEvent(const Event& event);
    Event* getEvent() const;
    //void System::addReservation(const Reservation& reservation);
    friend std::ostream& operator<<(std::ostream&, const System&);
    friend std::istream& operator >> (std::istream& in,  System& system);
    int getSize() const;
    void read();
};