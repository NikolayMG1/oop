#pragma once//the file to be included only once during a compilation
#include "newEvent.h"

class Hall{//class of Hall
    private:

    unsigned number;//number of the hall
    unsigned rows;//rows in the hall
    unsigned spaces;//spaces per row in the hall
    newEvent newevent;
    public:

    Hall();//no need for default constructor
    Hall(const newEvent& newevent, const unsigned number, const unsigned rows, const unsigned spaces);//gives values to the members/fields
    unsigned getNumber() const;
    unsigned getRows() const;
    unsigned getSpaces() const;
    const newEvent& getEvent() const;
};