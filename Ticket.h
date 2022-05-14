#pragma once
#include "Date.h"
#include <ostream>

class Ticket{
    private:
    char* name;
    Date date;
    int row;
    int seat;
    char* password;
    void free();  
    void copy(const Ticket&);

    public:
    Ticket();
    Ticket(const char* name,const Date& date,const int row,const int seat,const char* password);
    Ticket(const Ticket&);
    ~Ticket();
    bool operator==(const Ticket &other) const;
    friend std::ostream& operator<<(std::ostream&, const Ticket&);
    void buyTicket();
    Ticket& operator=(const Ticket& other);
};