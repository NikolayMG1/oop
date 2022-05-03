#pragma once

class reserveTicket{
    private:
    char* performanceName;
    unsigned day;
    unsigned month;
    unsigned year;
    int row;
    int place;
    char* password;
    char* comment;

    public:
    reserveTicket(char*, unsigned, unsigned, unsigned, int, int, char*, char*);
};