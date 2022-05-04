#include "Hall.h"

Hall::Hall(){
    this->number = 0;
    this->rows = 0;
    this->seats = 0;
}
Hall::Hall(const int number, const int rows, const int seats){
    this->number = number;
    this->rows = rows;
    this->seats = seats;
}