#include "reserveTicket.h"
#include <cstring>

reserveTicket::reserveTicket(char* performanceName,unsigned day,unsigned month,unsigned year,int row,int place,char* password,char* comment){

    strcpy(this->performanceName, performanceName);
    this->day = day;
    this->month = month;
    this->year = year;
    this->row = row;
    this->place = place;
    strcpy(this->password, password);
    strcpy(this->comment, comment);
}