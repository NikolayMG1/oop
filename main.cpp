#include "System.h"
#include <iostream>

int main(){

    // Date date(1, 1, 1);
    Hall hall1(1, 10, 10);
    Hall hall2(2, 20, 20);
    Hall hall3(3, 30, 30);
    Hall hall4(4, 40, 40);
    Hall hall5(5, 50, 50);
    //std::cout << hall3;
    // Ticket ticket1("asd", date, 1, 1, "password");
    // Reservation reservation1(ticket1, "comment");
    // Reservation reservation2(ticket1, "comment1");
    // Reservation reservation3(ticket1, "comment");
    // Ticket ticket2;
    // //std::cout << ticket1;
    // Event event1("asd1", date, hall1);
    // event1.addReservation(reservation1);
    // // event1.addReservation(reservation2);
    // // event1.removeReservation(reservation2);
    // std::cout << event1;
    //std::cout << reservation1 << '\n';
    //Event event2("asd", date, hall2, reservation1, ticket1);
    // System system1;
    // system1.addEvent(event1);
    // system1.addEvent(event1);
    //std::cout << '\n';
    //std::cout << event1;
    //system1.addEvent(event2);
    // for(int i = 0; i < 1; i++){
    //     std::cout << system1.getEvent()[i] << '\n';
    // }

    // Ticket ticket;
    // std::cin >> ticket;
    // std::cout << ticket;

    // Reservation reservation;
    // std::cin >> reservation;
    // std::cout << reservation;

    // Hall hall;
    // std::cin >> hall;
    // std::cout << hall;

    // Event event;
    // std::cin >> event;
    // std::cout << event;

    System system;
    system.read();
}