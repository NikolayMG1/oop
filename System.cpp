#include "System.h"
#include <cstring>
#pragma warning(disable:4996)

System::System():events(){
    this->events = new Event[capacity];
}
System::~System(){
    delete[] events;
}
Event* System::getEvent() const{
    return events;
}
void System::resize(unsigned& newCapacity){
    Event* newEvent = new Event[newCapacity];
    for(int i = 0; i < newCapacity; i++){
        newEvent[i] = this->events[i];
    }
    delete[] this->events;
    this->events = newEvent;
}
void System::addEvent(const Event& event){
    if(this->size >= this->capacity){
        capacity++;
        resize(capacity);
    }
    this->events[size++] = event;
    read();
}
void System::removeEvent(const Event& event){
    int k = 0;
    bool isFound = false;
    for(int i = 0;i < this->size; i++){
        if(events[i] == event){
            k = i;
            isFound = true;
        }
    }
    if(!isFound){
        std::cout << "Not found" << '\n';
        read();
    }
    
    for (int i = k; i < this->size-1; i++){
        events[i] = events[i + 1];
    }
    size--;
    std::cout << size;
    resize(size);
    read();
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
void System::free(){
    delete[] events;
}
// std::istream& operator >>(std::istream& in,  System& system){
//     system.free();
//     //sin >> system.events;
//     return in;
// }

void System::read(){
    std::cout << "To add an event, type addEvent " << '\n';
    std::cout << "To remove an event, type removeEvent " << '\n';
    std::cout << "To exit, type finish ";
    std::cout << '\n';
    char operation[100];
    std::cin >> operation;
    if(!strcmp(operation,"addEvent")){
        Event event;
        std::cin >> event;
        addEvent(event);
    }
    else if(!strcmp(operation,"removeEvent")){
        Event event;
        std::cin >> event;
        removeEvent(event);
    }
    else if(!strcmp(operation,"finish")){
        for(int i = 0; i < this->size; i++){
        std::cout << events[i];
        std::cout << "------" << '\n';
        }
        return;
    }
    else{
        std::cout << "wrong operation!";
    }
    read();
}