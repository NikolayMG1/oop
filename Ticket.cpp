#include "Ticket.h"
#include <cstring>
#include <iostream>

#pragma warning(disable:4996)

Ticket::Ticket():date(){
    this->name = nullptr;
    this->row = 0;
    this->seat = 0;
    this->password = nullptr;
}
Ticket::Ticket(const char* name,const Date& date,const int row,const int seat,const char* password){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->date = date;
    this->row = row;
    this->seat = seat;
    this->password = new char[strlen(password)+1];
    strcpy(this->password, password);
}
Ticket::Ticket(const Ticket& other){
    copy(other);
}
Ticket::~Ticket(){
    delete[] name;
    delete[] password;
}
bool Ticket::operator==(const Ticket &other) const{
    if(this->date == other.date){
        if(this->row == other.row){
            if(this->seat == other.seat){
                if(this->password == other.password){
                    return true;
                }
            }          
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Ticket& ticket){
    out << ticket.name << ' ' << ticket.date << " " << ticket.row << " " << ticket.seat << " " <<  ticket.password;
    return out;
}

void Ticket::free(){
    delete[] name;
    delete[] password;
}
void Ticket::copy(const Ticket& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->date = date;
    this->row = other.row;
    this->seat = other.seat;
    this->password = new char[strlen(other.password)+1];
    strcpy(this->password, other.password);
}

Ticket& Ticket::operator=(const Ticket& other){
    if(this != &other){
        free();
        copy(other);
    }
    return *this;
}