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
    for(int i = 0; i < size; i++){
        if(this->events[i].getDate() == event.getDate()){
            std::cout << "another event is already due to" << '\n';
            read();
        }
    } 
    if(this->size >= this->capacity){
        capacity++;
        resize(capacity);
    }
    this->events[size++] = event;
    read();
}
// void Event::addReservation(const Reservation& reservation){
//     bool isTaken = false;
//     for(int i = 0; i < reservationCapacity; i++){
//         if(this->reservations[i] == reservation){
//             std::cout << "already taken" << '\n';
//             isTaken = true;
//         }
//     } 
//     if(this->reservationCounter >= this->reservationCapacity && !isTaken){
//         reservationCapacity++;
//         resize(reservationCapacity);
//     }
//     this->reservations[reservationCounter++] = reservation;//!!!
// }

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

// void System::removeEvent(const Event& event){
//     int k = 0;
//     bool isFound = false;
//     for(int i = 0;i < this->size; i++){
//         if(events[i] == event){
//             k = i;
//             isFound = true;
//         }
//     }
//     std::cout << k;
//     if(!isFound){
//         std::cout << "Not found" << '\n';
//         read();
//     }
//     for (int i = k; i < this->size-1; i++){
//         events[i] = events[i + 1];
//     }
//     size--;
//     resize(size);
// }

// std::istream& operator >>(std::istream& in,  System& system){
//     system.free();
//     //sin >> system.events;
//     return in;
// }

void System::read(){
    std::cout << "To add an event, type addEvent " << '\n';
    //std::cout << "To remove an event, type removeEvent " << '\n';
    std::cout << "To print all events, type printEvents " << '\n';
    //std::cout << "To print all free spaces, type freeSpaces " << '\n';
    //std::cout << "To make a reservation, type reserveTicket " << '\n';
    std::cout << "To exit and print all events, type finish " << '\n';
    std::cout << '\n';
    char operation[100];
    std::cin >> operation;
    if(!strcmp(operation,"addEvent")){
        Event event;
        std::cin >> event;
        addEvent(event);
    }
    
    else if(!strcmp(operation,"printEvents")){
        if(this->size == 0){
            std::cout << "no events" << '\n';
        }
        for(int i = 0; i < this->size; i++){
        std::cout << events[i];
        std::cout << "------" << '\n';
        }
    }
    else if(!strcmp(operation,"finish")){
        for(int i = 0; i < this->size; i++){
        std::cout << events[i];
        std::cout << "------" << '\n';
        }
        return;
    }
    else{
        std::cout << "wrong operation!" << '\n';
    }
    read();
    // else if(!strcmp(operation,"removeEvent")){
    //     Event event;
    //     std::cin >> event;
    //     removeEvent(event);
    // }
    // else if(!strcmp(operation,"reserveTicket")){
    //     Reservation reservation;
    //     std::cin >> reservation;
    //     addReservation(reservation);
    // }

    // else if(!strcmp(operation,"freeSpaces")){
    //     std::cout << "Enter the event name ";
    //     std::cin >> operation;
        // for(int i = 0;i < size; i++){
        //     for(int i = 0; i < 5; i++){
        //         std::cout << halls[i];
        //     } 
        //     if(this->events[i].getName() == operation){

        //     }
        // }
        // Event event;
        // std::cin >> event;
        // for(int i = 0;i < capacity; i++){
        //     if(events[i].getDate() == event.getDate()){

        //     }
        // }
    //}
    
}