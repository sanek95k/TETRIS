#include "source.h"
#include "linplatform.h"

void construct(char ***&arg)
{
    arg=new char** [L];
    for (short i=0; i<L; ++i)
    {
        arg[i]=new char* [M];
        for (short j=0; j<M; ++j)
            if (i==0||i==L-1||j==0||j==M-1)
                arg[i][j]="\342\226\222";
            else
                arg[i][j]=" ";
    }
}

void clear(char ***&arg, Block *f)
{
    short x=f->GetX();
    short y=f->GetY();
    short a=f->GetA();
    short b=f->GetB();
    for (short i=x; i<x+a; ++i)
        for (short j=y; j<y+b; ++j)
            arg[i][j]=" ";
}

void draw (char ***&arg)
{
    for (short i=0; i<L; ++i)
    {
        for (short j=0; j<M; ++j)
        {
            std::cout<<arg[i][j];
            if (i==0||i==L-1||j==0||j==M-1)
                std::cout<<"\342\226\222";
            else
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}

bool game(char ***&arg)
{
    for (short i=1; i<M-1; ++i)
        if (arg[1][i]==blockIcon)
            return false;
    return true;
}

void line(char ***&arg)
{
    for (short i1=L-2; i1>0; --i1)
        for (short i2=1; i2<M-1; ++i2)
        {
            if (arg[i1][i2]==" ")
                break;
            if (i2==M-2)
            {
                for (short i3=1;i3<M-1;++i3)
                {
                    arg[i1][i3]=" ";
                    nap(25);
                    clearScreen();
                    draw(arg);
                }
                for (short i4=i1; i4>0; --i4)
                    for (short i5=1; i5<M-1; ++i5)
                    if (i4==1)
                        arg[1][i5]=" ";
                    else
                        arg[i4][i5]=arg[i4-1][i5];

                i1++;
            }
        }
}

void destruct(char ***&arg)
{
    for (short i=0; i<L; ++i)
        delete [] arg[i];
    delete [] arg;
}
