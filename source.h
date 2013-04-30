#ifndef SOURCE_H
#define SOURCE_H

#include "block.h"
#include <iostream>
#include <string.h>

class Source
{
    char ***p;
    short l, m;

public:
    Source():
    p(0), l(0), m(0)
    {
    }
    Source(short, short);
    ~Source();

    void Draw();
    bool Game();
    void Line();
    short GetL();
    short GetM();
    char*** GetP();
};

#endif
