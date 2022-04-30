#include <newEvent.h>
#include <cstring>

newEvent::newEvent(const unsigned day, const unsigned month, const unsigned year, const char* performanceName){
    this->day = day;
    this->month = month;
    this->year = year;
    strcpy(this->performanceName, performanceName);
}