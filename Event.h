#pragma once
#include "Hall.h"
#include "Reservation.h"
#include "Ticket.h"
#include "Date.h"
#include <ostream>

class Event{
    private:
    
    char* name;
    Date date;
    Hall hall;
    Reservation reservation;
    Ticket ticket;

    public:
    Event();
    Event(const char* name,const Date& date, const Hall& hall,const Reservation& reservation,const Ticket& ticket);
    Event(const Event&);
    Event& operator=(const Event&);
    ~Event();
    bool operator==(const Event &other) const;
    friend std::ostream& operator<<(std::ostream&, const Event&);

    private:
    void free();
    void copy(const Event&);
};