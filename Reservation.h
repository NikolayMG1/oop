#pragma once

class Reservation{
    private:
    char* name;
    unsigned day;
    unsigned month;
    unsigned year;
    int row;
    int seat;
    char* password;
    char* comment;

    public:
    Reservation();
    Reservation(char* name,unsigned day,unsigned month,unsigned year,int row,int seat,char* password,char* comment;);
    Reservation(const Reservation&);
    ~Reservation();
};