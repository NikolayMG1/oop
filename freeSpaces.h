#pragma once

class freeSpaces{
    private:
    int* spaces;

    public:
    freeSpaces();
    freeSpaces(const int* spaces);
    freeSpaces(const freeSpaces&);
    ~freeSpaces();
};