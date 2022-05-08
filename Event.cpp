#include "Hall.h"
#include "Event.h"
#include <cstring>
#include "Ticket.h"
#pragma warning(disable:4996)

Event::Event():hall(),reservation(),ticket(){
    this->day = 0;
    this->month = 0;
    this->year = 0;
    this->name = nullptr;
}
Event::Event(const unsigned day, const unsigned month, const unsigned year, const char* name, const Hall& hall,const Reservation& reservation, const Ticket& ticket){
    this->day = day;
    this->month = month;
    this->year = year;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->hall = hall;
    this->reservation = reservation;
    this->ticket = ticket;
}
Event::Event(const Event& other){
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->hall = other.hall;
    this->reservation = other.reservation;
    this->ticket = other.ticket;
}
Event::~Event(){
    delete[] name;
}
