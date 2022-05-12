#include "System.h"
#include <iostream>

int main(){
    Date date(1, 1, 1);
    Hall hall1(1, 1, 1);
    Hall hall2(1, 2, 1);
    Reservation reservation1;
    Reservation reservation2;
    Ticket ticket1;
    Ticket ticket2;
    Event event1("asd1", date, hall1, reservation1, ticket1);
    Event event2("asd", date, hall2, reservation1, ticket1);
    System system1;
    system1.addEvent(event1);
    system1.addEvent(event2);
    // bool isTrue = (event1 == event2);
    // std::cout << isTrue;
    for(int i = 0; i < 2; i++){
        std::cout << system1.getEvent()[i] << '\n';
    }
    // std::cout << std::boolalpha << !() << std::endl;
}