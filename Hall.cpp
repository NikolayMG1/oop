#include "Hall.h"//including Hall.h so we can access the class Hall

Hall::Hall():newevent(){
    this->number = 0;
    this->rows = 0;
    this->spaces = 0;
}
Hall::Hall(const newEvent& newevent, const unsigned number, const unsigned rows, const unsigned spaces){
    this->newevent = newevent;
    this->number = number;
    this->rows = rows;
    this->spaces = spaces;
}
unsigned Hall::getNumber() const{
    return this->number;
}
unsigned Hall::getRows() const{
    return this->rows;
}
unsigned Hall::getSpaces() const{
    return this->spaces;
}
const newEvent& Hall::getEvent() const{
    return this->newevent;
}