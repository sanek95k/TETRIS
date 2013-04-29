#ifndef BLOCK_H
#define BLOCK_H

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

    Block(short arg, short brg):
    a(arg), b(brg), ptr(0)
    {
        coords.x=0;
        coords.y=0;
    }

    ~Block()
    {
        a=0;
        b=0;
        ptr=0;
    }

    virtual void Rotate()=0;
    virtual bool StopDown(char ***&)=0;
    virtual bool StopLeft(char ***&)=0;
    virtual bool StopRight(char ***&)=0;
    void MoveRight();
    void MoveLeft();
    void MoveDown();
    void Enter(char ***arg);
    short GetX();
    short GetY();
    short GetA();
    short GetB();

};

#endif
