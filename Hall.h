#pragma once
#include <ostream>

class Hall{
    private:
    int number;
    int rows;
    int seats;
    bool* freeSpaces;
    void copy(const Hall& other);

    public:
    Hall();// = default
    Hall(const int number, const int rows, const int seats);
    ~Hall();
    void setSpaces();
    bool* getSpaces() const;
    int getRows() const;
    int getSeats() const;
    Hall& operator=(const Hall& other);
    bool operator!=(const Hall &other)const;
    friend std::ostream& operator<<(std::ostream&, const Hall&);
    friend std::istream& operator >> (std::istream& in, Hall& hall);
    Hall(const Hall& other);
};