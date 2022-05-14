#include "Event.h"
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)

Event::Event():hall(),ticket(),date(){
    this->name = nullptr;
    this->reservations = new Reservation[reservationCapacity];
}
Event::Event(const char* name,const Date& date, const Hall& hall){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->date = date;
    this->hall = hall;
    // this->reservations = new Reservation[reservationCounter];
    // for(int i = 0; i < reservationCounter; i++){
    //     this->reservations[i] = reservation[i];
    // }
    // this->ticket = ticket;
}
// void Event::addReservation(const Reservation& reservation){
//     if(this->reservationCounter >= this->reservationCapacity){
//         resize(reservationCapacity);
//     }
//     this->reservations[reservationCounter++] = reservation;
// }

Event::Event(const Event& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->date = other.date;
    this->hall = other.hall;
    // this->reservations = other.reservations;
    // this->ticket = other.ticket;
}
void Event::free(){
    delete[] name;
}
void Event::copy(const Event& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->date = other.date;
    this->hall = other.hall;
    // this->reservations = other.reservations;
    // this->ticket = other.ticket;
}
Event& Event::operator=(const Event& other){
    if(this != &other){
        free();
        copy(other);
    }
    return *this;
}
Event::~Event(){
    delete[] name;
}
// void Event::copy(const Event& other){
//     this->day = other.day;
//     this->month = other.month;
//     this->year = other.year;
// }

bool Event::operator==(const Event &other) const{
    if(this->date.getDay() != other.date.getDay()){
        // std::cout << this->date.getDay() << " " << other.date.getDay();
        return false;
    }
    if(this->date.getMonth() != other.date.getMonth()){
        // std::cout << this->date.getMonth() << " " << other.date.getMonth();
        return false;
    }
    if(this->date.getYear() != other.date.getYear()){
        // std::cout << this->date.getYear() << " " << other.date.getYear();
        return false;
    }
    if(strcmp(this->name, other.name)){
        // std::cout << this->name << " " << other.name;
        return false;
    }
    if(this->hall != other.hall){
        // std::cout << this->hall.getSpaces() << " " << other.hall.getSpaces();
        return false; 
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const Event& event){
    // std::cout << "alo";
    if (event.name == nullptr)
    {
        std::cout << "nullptr sme" << std::endl;
    }
    out << event.name << '\n';
    out << event.date << '\n';
    out << event.hall << '\n';
    //out << event.ticket << '\n';
    return out;
}

const Date& Event::getDate() const{
    return this->date;
}

const char* Event::getName() const{
    return this->name;
}

Hall Event::getHall() const{
    return this->hall;
}

Ticket Event::getTicket() const{
    return this->ticket;
}

// void Event::removeReservation(const Reservation& reservation){
    
// }
void Event::addReservation(const Reservation& reservation){
    if(this->reservationCounter >= this->reservationCapacity){
        reservationCapacity++;
        resize(reservationCapacity);
    }
    this->reservations[reservationCounter++] = reservation;
}

void Event::resize(size_t& newCapacity){
    Reservation* newReservation = new Reservation[newCapacity];
    for(int i = 0; i < newCapacity-1; i++){
        newReservation[i] = this->reservations[i];
    }
    delete[] this->reservations;
    this->reservations = newReservation;
}