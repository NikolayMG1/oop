#pragma once
#include "Hall.h"
#include "Reservation.h"
#include "Ticket.h"

class Event{
    private:
    unsigned day;
    unsigned month;
    unsigned year;
    char* name;
    Hall hall;
    Reservation reservation;
    Ticket ticket;

    public:
    Event();
    Event(const unsigned day, const unsigned month, const unsigned year, const char* name, const Hall& hall,const Reservation& reservation,const Ticket& ticket);
    Event(const Event&);
    ~Event();
};