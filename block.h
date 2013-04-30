#ifndef BLOCK_H
#define BLOCK_H

#include "source.h"

class Source;

class Block
{
protected:
    short a, b;
    char ***ptr;
    struct
    {
        short x, y;
    }coords;
public:

    Block(short, short);
    ~Block();
    virtual void Rotate()=0;
    virtual bool StopDown(Source *)=0;
    virtual bool StopLeft(Source *)=0;
    virtual bool StopRight(Source *)=0;
    void MoveRight();
    void MoveLeft();
    void MoveDown();
    void Enter(Source *);
    void Clear(Source *);
};

#endif


