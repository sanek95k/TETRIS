#include "field.h"
#include "source.h"

Field::Field(short x, short y):
p(0), l(x), m(y)
{
    p=new char** [l];
    for (short i=0; i<l; ++i)
    {
        p[i]=new char* [m];
        for (short j=0; j<m; ++j)
            if (i==0||i==l-1||j==0||j==m-1)
                p[i][j]="\342\226\222";
            else
                p[i][j]=" ";
    }
}

Field::~Field()
{
    for (short i=0; i<l; ++i)
        delete [] p[i];
    delete [] p;
}

void Field::Draw()
{
    for (short i=0; i<l; ++i)
    {
        for (short j=0; j<m; ++j)
        {
            std::cout<<p[i][j];
            if (i==0||i==l-1||j==0||j==m-1)
                std::cout<<"\342\226\222";
            else
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}

bool Field::Game()
{
    for (short i=1; i<m-1; ++i)
        if (p[1][i]!=" ")
            return false;
    return true;
}

short Field::MinusLine()
{
    short score=0;
    for (short i1=l-2; i1>0; --i1)
        for (short i2=1; i2<m-1; ++i2)
        {
            if (p[i1][i2]==" ")
                break;
            if (i2==m-2)
            {
                for (short i3=1;i3<m-1;++i3)
                {
                    p[i1][i3]=" ";
                    nap(25);
                    clearScreen();
                    Draw();
                }
                for (short i4=i1; i4>0; --i4)
                    for (short i5=1; i5<m-1; ++i5)
                    if (i4==1)
                        p[1][i5]=" ";
                    else
                        p[i4][i5]=p[i4-1][i5];
                i1++;
                score++;
            }
        }
        return score;
}

short Field::GetL()
{
    return l;
}

short Field::GetM()
{
    return m;
}

char*** Field::GetP()
{
    return p;
}
