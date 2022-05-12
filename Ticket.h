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

    public:
    Ticket();
    Ticket(char* name,Date date,int row,int seat,char* password);
    Ticket(const Ticket&);
    ~Ticket();
    bool operator==(const Ticket &other) const;
    friend std::ostream& operator<<(std::ostream&, const Ticket&);
};