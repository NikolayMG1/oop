#include "Hall.h"
#include <cstring>
#pragma warning(disable:4996)

Hall::Hall(){
    this->number = 0;
    this->rows = 0;
    this->seats = 0;
    this->freeSpaces = nullptr;
}
Hall::Hall(const int number, const int rows, const int seats){
    this->number = number;
    this->rows = rows;
    this->seats = seats;
}
void Hall::setSpaces(const int* freeSpaces){
    // int size = sizeof(freeSpaces)/sizeof(int);
    // this->freeSpaces = new int[size];
    // for(int i = 0; i < size; i++){
    //     this->freeSpaces[i] = freeSpaces[i];
    // }
    int size = this->number*this->rows;
    for(int i = 0; i < size; i++){
        this->freeSpaces[i] = i;
    }
}
int* Hall::getSpaces(int* freeSpaces) const{
    return this->freeSpaces;
}
