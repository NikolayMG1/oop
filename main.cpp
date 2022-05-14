#include "System.h"
#include <iostream>

int main(){

    Date date(1, 1, 1);
    Hall hall1(5, 5, 1);
    //Hall hall2(4, 2, 1);
    Ticket ticket1("asd",date, 1, 1, "password");
    Reservation reservation1(ticket1, "comment");
    Ticket ticket2;
    Event event1("asd1", date, hall1);
    event1.addReservation(reservation1);
    //Event event2("asd", date, hall2, reservation1, ticket1);
    System system1;
    system1.addEvent(event1);
    std::cout << event1;
    //system1.addEvent(event2);
    for(int i = 0; i < 1; i++){
        //std::cout << system1.getEvent()[i] << '\n';
    }
}