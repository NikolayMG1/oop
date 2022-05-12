#include "Hall.h"
#include <cstring>
#include <iostream>
#include <ostream>
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
    setSpaces();

}
void Hall::setSpaces(){
    // int size = sizeof(freeSpaces)/sizeof(int);
    // this->freeSpaces = new int[size];
    // for(int i = 0; i < size; i++){
    //     this->freeSpaces[i] = freeSpaces[i];
    // }
    int size = this->seats*this->rows;
    this->freeSpaces = new int[size];
    for(int i = 0; i < size; i++){
        this->freeSpaces[i] = i+1;
    }
}
const int* Hall::getSpaces() const{
    return this->freeSpaces;
}
bool same(const int* arr1,const int* arr2){
    int size1 = sizeof(arr1)/sizeof(arr1);
    int size2 = sizeof(arr2)/sizeof(arr2);
    if(size1 != size2){
        return false;
    }
    for(int i = 0; i < size1; i++){
        if(arr1[i] != arr2[i]){
            return false;
        }
    }
    return true;
}
bool Hall::operator!=(const Hall &other)const{
    if(same(this->freeSpaces, other.freeSpaces)){
        // std::cout << this->freeSpaces << " " << other.freeSpaces;
        return false;
    }
    if(this->number == other.number){
        //std::cout << this->number << " " << other.number;
        return false;
    }
    if(this->rows == other.rows){
        //std::cout << this->rows << " " << other.rows;
        return false;
    }
    if(this->seats == other.seats){
        //std::cout << this->seats << " " << other.seats;
        return false;
    }
    return true;
}

Hall::~Hall(){
    delete[] freeSpaces;
}

std::ostream& operator<<(std::ostream& out, const Hall& hall){
    out <<"Number: " << hall.number << '\n';
    return out;
}