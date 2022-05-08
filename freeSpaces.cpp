#include "freeSpaces.h"
#pragma warning(disable:4996)

freeSpaces::freeSpaces(){
    this->spaces;
}
freeSpaces::freeSpaces(const int* spaces){
    int size = sizeof(spaces)/ sizeof(int);
    this->spaces = new int[size];
    for(int i = 0; i < size; i++){
        this->spaces[i] = spaces[i];
    }
}
freeSpaces::freeSpaces(const freeSpaces& other){
    int size = sizeof(other.spaces)/ sizeof(int);
    this->spaces = new int[size];
    for(int i = 0; i < size; i++){
        this->spaces[i] = other.spaces[i];
    }
}
freeSpaces::~freeSpaces(){
    delete[] spaces;
}