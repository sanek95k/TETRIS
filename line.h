#ifndef LINE_H
#define LINE_H

#include "block.h"

class Line: public Block
{
public:
    Line(short, short);
    ~Line();

    void Rotate(Field *);
    bool StopDown(Field *);
    bool StopLeft(Field *);
    bool StopRight(Field *);
};

#endif
