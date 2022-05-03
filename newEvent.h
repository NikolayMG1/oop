#pragma once//the file to be included only once during a compilation
#include "Hall.h"

class newEvent{
    private:
    int number;
    unsigned day;
    unsigned month;
    unsigned year;
    char* performanceName;

    public:
    newEvent();//no need for default
    newEvent(const int number, const unsigned day, const unsigned month, const unsigned year, const char* performanceName);
    ~newEvent();
    newEvent(const newEvent&);//const immutable, & same object
    bool isTaken(const Hall& ) const;
};