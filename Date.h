#pragma once
#include <ostream>

class Date
{
private:
    unsigned day;
    unsigned month;
    unsigned year;
public:
    Date();
    Date(const unsigned day, const unsigned month, const unsigned year);
    unsigned getDay() const;
    unsigned getMonth() const;
    unsigned getYear() const;
    bool operator==(const Date &other) const;
    friend std::ostream& operator<<(std::ostream&, const Date&);

};
