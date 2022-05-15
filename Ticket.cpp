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
    free();
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
void Ticket::free(){
    delete[] name;
    delete[] password;
}
void Ticket::copy(const Ticket& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->date = other.date;
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
std::istream& operator >>(std::istream& in,  Ticket& ticket){
    char buffer[1024];
    ticket.free();
    std::cout << "Enter a name: ";
    in >> buffer;
    ticket.name = new char[strlen(buffer)+1];
    strcpy(ticket.name, buffer);
    in >> ticket.date;
    std::cout << "Enter a row: ";
    in >> ticket.row;
    std::cout << "Enter a seat: ";
    in >> ticket.seat;
    std::cout << "Enter a password: ";
    in >> buffer;
    ticket.password = new char[strlen(buffer)+1];
    strcpy(ticket.password, buffer);
    return in;
}
std::ostream& operator<<(std::ostream& out, const Ticket& ticket){
    out << "Performance name: " << ticket.name << '\n';
    out << ticket.date << '\n';
    out << "Row: " << ticket.row << '\n';
    out << "Seat: " << ticket.seat << '\n';
    out << "Password: " <<  ticket.password;
    return out;
}