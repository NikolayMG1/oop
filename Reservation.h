#pragma once
#include "Date.h"
#include "Ticket.h"
#include <ostream>

class Reservation{
    private:
    Ticket ticket;
    char* comment;
    void copy(const Reservation& other);
    void free();
    public:
    Reservation();
    Reservation(const Ticket& ticket,const char* comment);
    Reservation(const Reservation&);
    ~Reservation();
    //bool bookedReservation(const char* name,const Date& date,const int row,const int seat,const char* password);
    Reservation& operator=(const Reservation& other);
    bool operator==(const Reservation &other) const;
    friend std::ostream& operator<<(std::ostream&, const Reservation&);
};