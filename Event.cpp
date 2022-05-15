#include "Event.h"
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)

Event::Event():hall(),ticket(),date(),reservations(){
    this->freeSpaces = new bool[spaces];
    for(int i = 0;i < spaces; i++){
        freeSpaces[i] = true;
    }
    this->name = nullptr;
    this->reservations = new Reservation[reservationCapacity];
}
Event::Event(const char* name,const Date& date, const Hall& hall){
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->date = date;
    this->hall = hall;
    this->freeSpaces = new bool[spaces];
    for(int i = 0;i < spaces; i++){
        freeSpaces[i] = true;
    }
    this->reservations = new Reservation[reservationCapacity];
}
Event::Event(const Event& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    this->date = other.date;
    this->hall = other.hall;
    this->freeSpaces = new bool[other.spaces];
    for(int i = 0;i < spaces; i++){
        freeSpaces[i] = other.freeSpaces[i];
    }
}
void Event::free(){
    delete[] freeSpaces;
    delete[] name;
    delete[] reservations;
}
Reservation* Event::getReservations() const{
    return reservations;
}
void Event::copy(const Event& other){
    this->name = new char[strlen(other.name)+1];
    strcpy(this->name, other.name);
    for(int i = 0; i < spaces;i++){
        this->freeSpaces[i] = other.freeSpaces[i];
    }
    this->date = other.date;
    this->hall = other.hall;
    this->reservations = other.reservations;
}
Event& Event::operator=(const Event& other){
    if(this != &other){
        free();
        copy(other);
    }
    return *this;
}
Event::~Event(){
    free();
}
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
const Date& Event::getDate() const{
    return this->date;
}
const char* Event::getName() const{
    return this->name;
}
Hall Event::getHall() const{
    return this->hall;
}
bool* Event::getFreeSpaces() const{
    return freeSpaces;
}
void Event::removeReservation(const Reservation& reservation){
    Reservation* tempReservation = new Reservation[reservationCounter-1];
    int k = 0;
    for(int i = 0;i < reservationCounter;i++){
        if(!(this->reservations[i] == reservation)){
            tempReservation[k++] = this->reservations[i];
        }
    }
    delete[] this->reservations;
    this->reservations = tempReservation;
}
void Event::addReservation(const Reservation& reservation){
    if(this->reservationCounter >= this->reservationCapacity){
        reservationCapacity++;
        resize(reservationCapacity);
    }
    this->reservations[reservationCounter++] = reservation;//!!!
}
void Event::resize(size_t& newCapacity){
    Reservation* newReservation = new Reservation[newCapacity];
    for(int i = 0; i < newCapacity-1; i++){
        newReservation[i] = this->reservations[i];
    }
    delete[] this->reservations;
    this->reservations = newReservation;
}
std::istream& operator >> (std::istream& in,  Event& event){
    char buffer[1024];
    event.free();
    std::cout << "Enter a name: ";
    in >> buffer;
    event.name = new char[strlen(buffer)+1];
    strcpy(event.name, buffer);
    in >> event.date;
    in >> event.hall;
    // in >> event.reservations;
    // in >> event.ticket;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Event& event){
    if (event.name == nullptr){
        std::cout << "nullptr sme" << std::endl;
    }
    out << "Performance name: " << event.name << '\n';
    out << event.date << '\n';
    out << event.hall << '\n';
    //out << event.ticket << '\n';
    return out;
}