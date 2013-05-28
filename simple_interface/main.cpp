#include "field.h"

#include "square.h"
#include "line.h"
#include "stairleft.h"
#include "stairright.h"
#include "pedestal.h"
#include "cornerleft.h"
#include "cornerright.h"
#include "testfigure.h"

#include "source.h"
#include <cstdlib>
#include <iostream>

using namespace cell;
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
            if (p[i][j]==empty)
                cout<<"  ";
            else if (p[i][j]==border)
                cout<<"\342\226\222"<<"\342\226\222";
            else
                cout<<"\356\202\252 ";
        }
        cout<<endl;
    }

}


int main()
{
    cout<<" Консольный тетрис\n";
    cout<<"Управление фигурой:\n'a' - влево\n'd' - вправо\n";
    cout<<"'s' - быстро вниз\n'r' - повернуть\n'x' - выход\n\n";
    cout<<"Выберите уровень сложности (1-10):\n";

    short pause=0;
    cin>>pause;
    if (!(pause>0&&pause<11))
        pause=3;
    pause=800*1/pause;

    //short figures=8;
    short figures=7;
    short height=22, width=14;
    short centerX=1, centerY=width/2-1;
    short score=0, bestScore=0;
    bool exit=false;

    ConField *field=new ConField(height, width);

    Block *figure[figures];
    figure[0]=new Square(centerX, centerY);
    figure[1]=new Line(centerX, centerY);
    figure[2]=new StairLeft(centerX, centerY);
    figure[3]=new StairRight(centerX, centerY);
    figure[4]=new Pedestal (centerX, centerY);
    figure[5]=new CornerLeft (centerX, centerY);
    figure[6]=new CornerRight (centerX, centerY);
    //figure[7]=new TestFigure (centerX, centerY);

    char choice=1;
    srand(time(0));

    while(!exit)
    {
        short whatFig=rand()%figures;
        while(!exit)
        {
            if (!figure[whatFig]->Enter(field))
            {
                exit=true;
                continue;
            }
            clearScreen();
            field->Draw();

            if (figure[whatFig]->StopDown(field))
                break;
            figure[whatFig]->Clear(field);

            if(myKbhit())
                choice=myGetch();
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
                if (!figure[whatFig]->StopRotate(field))
                    figure[whatFig]->Rotate();
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

        short temp=field->KillLine();
        if (temp>bestScore)
            bestScore=temp;
        score+=temp;

        figure[whatFig]->ToDefault(centerX, centerY);

    }

    for (short i=0; i<figures; ++i)
    {
        delete  figure[i];
        figure[i]=0;
    }
    *figure=0;
    delete field;
    field=0;

    cout<<"\n Итоги:\n";
    cout<<"Всего "<<score<<" линий\n";
    cout<<"Наибольшее число линий за один раз: "<<bestScore<<" линий\n";

    return 0;
}
