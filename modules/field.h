#ifndef FIELD_H
#define FIELD_H

#include "block.h"
#include <iostream>

namespace cell
{
enum Cell
{
    empty, border, green, yellow, red, blue, white, magenta, cyan
};
}

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

    short KillLine();
    void ClearField();
    short** GetP() const;
};

#endif
