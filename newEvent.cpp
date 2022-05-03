#include <newEvent.h>
#include <Hall.h>
#include <cstring>

newEvent::newEvent(){
    this->number = 0;
    this->day = 0;
    this->month = 0;
    this->year = 0;
    this->performanceName = nullptr;
}

newEvent::newEvent(const int number, const unsigned day, const unsigned month, const unsigned year, const char* performanceName){
    this->number = number;
    this->day = day;
    this->month = month;
    this->year = year;
    strcpy(this->performanceName, performanceName);
}

newEvent::newEvent(const newEvent& other){
    this->number = other.number;
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
    this->performanceName = new char[strlen(other.performanceName)];
    strcpy(this->performanceName, performanceName);
}

newEvent::~newEvent(){
    delete[] performanceName;
}

bool newEvent::isTaken(const Hall& hall) const{
    if(hall.getNumber() == this->number){
        if(hall.getEvent().day == this->day){
            if(hall.getEvent().month == this->month){
                if(hall.getEvent().year == this->year){
                    return false;
                }
            }
        }
    }
    return true;
}