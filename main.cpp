#include "field.h"
#include "square.h"
#include "line.h"
#include "stairleft.h"
#include "stairright.h"
#include "source.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class ConField: public Field
{
public:
    ConField(short a,short b):
        Field(a,b)
    {
    }
    ~ConField()
    {
    }
    void Draw();
};

void ConField::Draw()
{
    for (short i=0; i<l; ++i)
    {
        for (short j=0; j<m; ++j)
        {
            switch(p[i][j])
            {
            case empty:
                cout<<"  ";
                break;
            case full:
                cout<<"\356\202\252 ";
                break;
            case border:
                cout<<"\342\226\222"<<"\342\226\222";
                break;
            }
        }
        cout<<endl;
    }

}


int main()
{
    /*cout<<" Консольный тетрис (пока что недотетрис), БЕЗ защиты от глупостей\n";
    cout<<"Управление фигурой:\n'a' - влево\n'd' - вправо\n";
    cout<<"'s' - быстро вниз\n'r' - повернуть\n'x' - выход\n\n";
    nap(1000);*/
    short figures=4;
    short pause=400;
    short height=22, width=16;
    srand(time(0));
    short score=0, bestScore=0;
    bool exit=false;
    Block *figure[figures];
    ConField *field=new ConField(height, width);
    char choice=1;
    while(field->Game()&&!exit)
    {
        figure[0]=new Square(1,width/2-1);
        figure[1]=new Line(1,width/2-1);
        figure[2]=new StairLeft(1,width/2-1);
        figure[3]=new StairRight(1,width/2-1);
        short whatFig=rand()%figures;
        while(!exit)
        {
            figure[whatFig]->Enter(field);
            clearScreen();
            field->Draw();
            if (figure[whatFig]->StopDown(field))
                break;
            figure[whatFig]->Clear(field);
            if(kbhit())
                choice=getch();
            switch (choice)
            {
            case 1:
                figure[whatFig]->MoveDown();
                nap(pause);
                break;
            case 'd':
                if (!figure[whatFig]->StopRight(field))
                    figure[whatFig]->MoveRight();
                choice=1;
                break;
            case 'a':
                if (!figure[whatFig]->StopLeft(field))
                    figure[whatFig]->MoveLeft();
                choice=1;
                break;
            case 's':
                nap(pause/50);
                figure[whatFig]->MoveDown();
                break;
            case 'r':
                figure[whatFig]->Rotate(field);
                choice=1;
                break;
            case 'x':
                exit=true;
                break;
            default:
                choice=1;
                break;
            }
        }
        choice=1;
        short temp=field->MinusLine();
        if (temp>bestScore)
            bestScore=temp;
        score+=temp;
        for (short i=0; i<figures; ++i)
        {
            delete  figure[i];
            figure[i]=0;
        }
        *figure=0;

    }
    /*cout<<"\n Итоги:\n";
    cout<<"Всего "<<score<<" линий\n";
    cout<<"Наибольшее число линий за один раз: "<<bestScore<<" линий\n";*/
    delete field;
    field=0;
    return 0;
}
