#pragma once

class freeSpaces{
    private:
    char* spaces;

    public:
    freeSpaces();
    freeSpaces(const char* spaces);
    freeSpaces(const freeSpaces&);
    ~freeSpaces();
};