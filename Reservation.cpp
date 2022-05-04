#include "Reservation.h"
#include <cstring>

Reservation::Reservation(){
    this->name = nullptr;
    this->day = 0;
    this->month = 0;
    this->year = 0;
    this->row = 0;
    this->seat = 0;
    this->password = nullptr;
    this->comment = nullptr;
}
Reservation::Reservation(char* name,unsigned day,unsigned month,unsigned year,int row,int seat,char* password,char* comment){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->day = day;
    this->month = month;
    this->year = year;
    this->row = row;
    this->seat = seat;
    this->password = new char[strlen(password)+1];
    strcpy(this->password, password);
    this->comment = new char[strlen(comment)+1];
    strcpy(this->comment, comment);
}
Reservation::Reservation(const Reservation& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
    this->row = other.row;
    this->seat = other.seat;
    this->password = new char[strlen(other.password)+1];
    strcpy(this->password, other.password);
    this->comment = new char[strlen(other.comment)+1];
    strcpy(this->comment, other.comment);
}
Reservation::~Reservation(){
    delete[] name;
    delete[] password;
    delete[] comment;
}