#pragma once

class Hall{
    private:
    int number;
    int rows;
    int seats;

    public:
    Hall();// = default
    Hall(const int number, const int rows, const int seats);
};