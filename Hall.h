#pragma once

class Hall{
    private:
    int number;
    int rows;
    int seats;
    int* freeSpaces;

    public:
    Hall();// = default
    Hall(const int number, const int rows, const int seats);
    void setSpaces(const int* freeSpaces);
    int* getSpaces(int* freeSpaces) const;
};