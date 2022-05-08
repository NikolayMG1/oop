#include "System.h"
#include "Event.h"
#include <cstring>
#pragma warning(disable:4996)

System::System():event(){}

System::System(const Event& event){
    this->event = event;
}
System::System(const System& other){
    this->event = other.event;
}