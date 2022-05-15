#include "Date.h"
#include <iostream>

Date::Date(){
    this->day = 0;
    this->month = 0;
    this->year = 0;
}
Date::Date(const unsigned day, const unsigned month, const unsigned year){
    this->day = day;
    this->month = month;
    this->year = year;
}
unsigned Date::getDay() const{
    return day;
}
unsigned Date::getMonth() const{
    return month;
}
unsigned Date::getYear() const{
    return year;
}
bool Date::operator==(const Date &other) const{
    if(this->day != other.day){
        // std::cout << this->date.getDay() << " " << other.date.getDay();
        return false;
    }
    if(this->month != other.month){
        // std::cout << this->date.getMonth() << " " << other.date.getMonth();
        return false;
    }
    if(this->year != other.year){
        // std::cout << this->date.getYear() << " " << other.date.getYear();
        return false;
    }
    return true;
}
std::istream& operator >>(std::istream& in,  Date& date){
    std::cout << "Enter the day: ";
    in >> date.day;
    std::cout << "Enter the month: ";
    in >> date.month;
    std::cout << "Enter the year: ";
    in >> date.year;    
    return in;
}
std::ostream& operator<<(std::ostream& out, const Date& date){
    out << '\n';
    out <<"Day: " << date.day << '\n';
    out <<"Month: " << date.month << '\n';
    out <<"Year: " << date.month << '\n';
    return out;
}

