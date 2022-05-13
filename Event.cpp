#include "Event.h"
#include <cstring>
#include <iostream>
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
void Event::free(){
    delete[] name;
}
void Event::copy(const Event& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->date = other.date;
    this->hall = other.hall;
    this->reservation = other.reservation;
    this->ticket = other.ticket;
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