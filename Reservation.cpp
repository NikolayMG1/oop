#include "Reservation.h"
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)

Reservation::Reservation():ticket(){
    this->comment = nullptr;
}
Reservation::Reservation(const Ticket& ticket,const char* comment){
    // this->name = new char[strlen(name)+1];
    // strcpy(this->name, name);
    // this->date = date;
    // this->row = row;
    // this->seat = seat;
    // this->password = new char[strlen(password)+1];
    // strcpy(this->password, password);
    // this->comment = new char[strlen(comment)+1];
    this->ticket = ticket;
    setComment(comment);
    // this->comment = new char[strlen(comment)+1];
    // strcpy(this->comment, comment);
    //std::cout << this->comment;
    // std::cout << '\n';
}
Reservation::Reservation(const Reservation& other){
    // this->name = new char[strlen(other.name)+1];
    // strcpy(this->name, other.name);
    // this->date = other.date;
    // this->row = other.row;
    // this->seat = other.seat;
    // this->password = new char[strlen(other.password)+1];
    // strcpy(this->password, other.password);
    // this->comment = new char[strlen(other.comment)+1];
    this->ticket = other.ticket;
    setComment(other.comment);
    // this->comment = new char[strlen(other.comment)+1];
    // strcpy(this->comment, other.comment);
}
Reservation::~Reservation(){
    free();
}
Reservation& Reservation::operator=(const Reservation& other){
    if(this != &other){
        free();
        copy(other);
    }
    return *this;
}
void Reservation::setComment(const char* comment){
    this->comment = new char[strlen(comment)+1];
    strcpy(this->comment, comment);
}
void Reservation::free(){
    delete[] comment;
}
void Reservation::copy(const Reservation& other){
    this->comment = new char[strlen(other.comment)+1];
    strcpy(this->comment, other.comment);
    this->ticket = other.ticket;
}
// bool Reservation::bookedReservation(const char* name,const Date& date,const int row,const int seat,const char* password){
//     if(this->name == name){
//         if(this->date == date){
//             if(this->row == row){
//                 if(this->seat == seat){
//                     if(this->password == password){
//                         return true;
//                     }
//                 }
//             }
//         }
//     }
// }        
bool Reservation::operator==(const Reservation &other) const{
    if(this->ticket == other.ticket){
        if(this->comment == other.comment){
            return true;
        }
    }
    return false;
}
std::ostream& operator<<(std::ostream& out, const Reservation& reservation){
    out <<"Ticket: " << reservation.ticket << '\n';
    out <<"Comment: " << reservation.comment;
    return out;
}
std::istream& operator >> (std::istream& in, Reservation& reservation){
    char buffer[1024];
    in >> reservation.ticket;
    reservation.free();
    std::cout << "Enter a comment: ";
    in >> buffer;
    reservation.setComment(buffer);
    std::cout << '\n';
    return in;
}
