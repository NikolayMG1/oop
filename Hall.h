#pragma once
#include <ostream>

class Hall{
    private:
    int number;
    int rows;
    int seats;
    int* freeSpaces;

    public:
    Hall();// = default
    Hall(const int number, const int rows, const int seats);
    ~Hall();
    void setSpaces();
    const int* getSpaces() const;
    bool operator!=(const Hall &other)const;
    friend std::ostream& operator<<(std::ostream&, const Hall&);
};