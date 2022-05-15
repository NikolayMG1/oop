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
    Reservation(const Ticket&,const char*);
    Reservation(const Reservation&);
    ~Reservation();
    void setComment(const char*);
    //bool bookedReservation(const char* name,const Date& date,const int row,const int seat,const char* password);
    Reservation& operator=(const Reservation& other);
    bool operator==(const Reservation &other) const;
    friend std::ostream& operator<<(std::ostream&, const Reservation&);
    friend std::istream& operator >> (std::istream& in, Reservation& reservation);
};