#include "Hall.h"
#include "Event.h"
#include <cstring>
#include "Ticket.h"
#include <iostream>
#include "Date.h"

#pragma warning(disable:4996)

Event::Event():hall(),reservation(),ticket(),date(){
    this->name = nullptr;
}
Event::Event(const char* name,const Date& date, const Hall& hall,const Reservation& reservation, const Ticket& ticket){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->date = date;
    this->hall = hall;
    this->reservation = reservation;
    this->ticket = ticket;
}
Event::Event(const Event& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->date = date;
    this->hall = other.hall;
    this->reservation = other.reservation;
    this->ticket = other.ticket;
}

Event& Event::operator=(const Event& other){
    if(this != &other){
        // free();
        // copy();
    }
    return *this;
}
Event::~Event(){
    delete[] name;
}
void Event::free(){
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
    out << event.name << '\n';
    out << event.date << '\n';
    out << event.hall << '\n';
    return out;
}

