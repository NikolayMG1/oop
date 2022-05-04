#pragma once
#include "Hall.h"

class Event{
    private:
    unsigned day;
    unsigned month;
    unsigned year;
    char* name;
    Hall hall;

    public:
    Event();
    Event(const unsigned day, const unsigned month, const unsigned year, const char* name, const Hall& hall);
    Event(const Event&);
    ~Event();
};