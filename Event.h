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
    bool* freeSpaces;
    int spaces = hall.getRows()*hall.getSeats();
    Reservation* reservations;
    Ticket ticket;
    size_t reservationCounter = 0;
    size_t reservationCapacity= 20;
    void resize(size_t& newCapacity);

    public:
    Event();
    Event(const char* name,const Date& date, const Hall& hall);
    Event(const Event&);
    Event& operator=(const Event&);
    ~Event();
    bool operator==(const Event &other) const;
    friend std::ostream& operator<<(std::ostream&, const Event&);
    friend std::istream& operator >> (std::istream& in,  Event& event);
    const Date& getDate() const;
    const char* getName() const;
    Hall getHall() const;
    void addReservation(const Reservation& reservation);
    void removeReservation(const Reservation& reservation);
    Reservation* getReservations() const;
    bool* getFreeSpaces() const;
    private:
    void free();
    void copy(const Event&);
    Ticket& getTicket() const;
};