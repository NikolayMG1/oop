#include "System.h"
#include "Event.h"
#include <cstring>
#include <iostream>

System::System():event(){}

System::System(const Event& event){
    this->event = event;
}
System::System(const System& other){
    this->event = other.event;
}