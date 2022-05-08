#pragma once

class Ticket{
    private:
    char* name;
    unsigned day;
    unsigned month;
    unsigned year;
    int row;
    int seat;
    char* password;

    public:
    Ticket();
    Ticket(char* name,unsigned day,unsigned month,unsigned year,int row,int seat,char* password);
    Ticket(const Ticket&);
    ~Ticket();
    bool Ticket::operator==(const Ticket &other) const;
};