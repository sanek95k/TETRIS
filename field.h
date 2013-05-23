#ifndef FIELD_H
#define FIELD_H

#include "block.h"
#include <iostream>

enum Cell
{
    empty, full, border
};

class Field
{
protected:
    short l, m;
    short **p;

public:
    Field():
        l(0), m(0), p(0)
    {
    }
    Field(short, short);
    ~Field();

    bool Game();
    short MinusLine();
    short GetL() const;
    short GetM() const;
    short** GetP() const;
};

#endif
