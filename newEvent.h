#pragma once//the file to be included only once during a compilation

class newEvent{
    private:
    unsigned day;
    unsigned month;
    unsigned year;
    char* performanceName;

    public:
    newEvent(const unsigned day, const unsigned month, const unsigned year, const char* performanceName);
};