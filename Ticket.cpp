#include "Ticket.h"
#include <cstring>
#pragma warning(disable:4996)

Ticket::Ticket(){
    this->name = nullptr;
    this->day = 0;
    this->month = 0;
    this->year = 0;
    this->row = 0;
    this->seat = 0;
    this->password = nullptr;
}
Ticket::Ticket(char* name,unsigned day,unsigned month,unsigned year,int row,int seat,char* password){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->day = day;
    this->month = month;
    this->year = year;
    this->row = row;
    this->seat = seat;
    this->password = new char[strlen(password)+1];
    strcpy(this->password, password);
}
Ticket::Ticket(const Ticket& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
    this->row = other.row;
    this->seat = other.seat;
    this->password = new char[strlen(other.password)+1];
    strcpy(this->password, other.password);
}
Ticket::~Ticket(){
    delete[] name;
    delete[] password;
}
bool Ticket::operator==(const Ticket &other) const{
    if(this->day == other.day){
        if(this->month == other.month){
            if(this->year == other.year){
                if(this->row == other.row){
                    if(this->seat == other.seat){
                        if(this->password == other.password){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}