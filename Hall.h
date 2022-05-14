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
    const bool* getSpaces() const;
    Hall& operator=(const Hall& other);
    bool operator!=(const Hall &other)const;
    friend std::ostream& operator<<(std::ostream&, const Hall&);
    Hall(const Hall& other);
};