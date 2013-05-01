#include "field.h"
#include "square.h"
#include "line.h"
#include "source.h"
#include "cstdlib"
#include <iostream>

using namespace std;

int main()
{
    cout<<" Консольный тетрис (пока что недотетрис), БЕЗ защиты от глупостей\n";
    cout<<"Управление фигурой:\n'a' - влево\n'd' - вправо\n";
    cout<<"'s' - быстро вниз\n'r' - повернуть\n'x' - выход\n\n";
    cout<<" Настройки игры\n";
    cout<<"Высота  поля: \n";
    short height;
    cin>>height;
    height+=2;
    cout<<"Ширина поля: \n";
    short width;
    cin>>width;
    width+=2;
    cout<<"Скорость фигур (шагов в секунду): \n";
    int pause;
    cin>>pause;
    pause=1000/pause;
    cout<<"Начинаем игру...\n";
    nap(1000);
    srand(time(0));
    short score=0, bestScore=0;
    bool exit=false;
    Block *figure[2];
    Field matrix(height, width);
    Field *field=&matrix;
    char choice=1;
    while(field->Game()&&!exit)
    {
        Square sqr(1,width/2-1);
        Line ln(1,width/2-1);
        figure[0]=&sqr;
        figure[1]=&ln;
        short whatFig=rand()%2;
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
    }
    cout<<"\n Итоги:\n";
    cout<<"Всего "<<score<<" линий\n";
    cout<<"Наибольшее число линий за один раз "<<bestScore<<" линий\n";
    return 0;
}
