#include "System.h"
#include "Event.h"
#include <cstring>
#pragma warning(disable:4996)

System::System():events(){
    this->events = new Event[capacity];
}
System::~System(){
    delete[] events;
}
Event*const System::getEvent() const{
    return events;
}
void System::resize(int& newCapacity){
    // while(size >= capacity){
    //     capacity += 1;
    // }
    Event* newEvent = new Event[newCapacity];
    for(int i = 0; i < newCapacity-1; i++){
        newEvent[i] = this->events[i];
    }
    delete[] this->events;
    this->events = newEvent;
}

void System::addEvent(const Event& event){
    if(this->size >= this->capacity){
        resize(capacity);
    }
    this->events[size++] = event;
}

std::ostream& operator<<(std::ostream& out, const System& system){
    for(int i = 0; i < system.getSize(); i++){
        out << system.getEvent()[i] << '\n';
    }
    return out;
}

int System::getSize() const{
    return size;
}