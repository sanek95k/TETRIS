#ifndef LINE_H
#define LINE_H

#include "block.h"

class Line: public Block
{
public:

    Line(short, short);
    ~Line();
    
    bool StopDown(Field *);
    bool StopLeft(Field *);
    bool StopRight(Field *);

    void Rotate();
    
};

#endif
