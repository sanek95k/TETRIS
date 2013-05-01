#ifndef FIELD_H
#define FIELD_H

#include "block.h"
#include <iostream>

class Field
{
    char ***p;
    short l, m;

public:
    Field():
    p(0), l(0), m(0)
    {
    }
    Field(short, short);
    ~Field();

    void Draw();
    bool Game();
    short MinusLine();
    short GetL();
    short GetM();
    char*** GetP();
};

#endif
