#include "bonus.h"

Bonus::Bonus(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/Images/bonus0-3.png"));
}

//------------------------------------------

void Bonus::increase1()
{
    bonus1++;
    if (bonus1 == 1)
        setPixmap(QPixmap(":/Images/Images/bonus1-3.png"));
    else if (bonus1 == 2)
        setPixmap(QPixmap(":/Images/Images/bonus2-3.png"));
    else if (bonus1 == 3)
        setPixmap(QPixmap(":/Images/Images/bonus3-3.png"));
}

//------------------------------------------

void Bonus::increase2()
{
    bonus2++;
    if (bonus2 == 1)
        setPixmap(QPixmap(":/Images/Images/bonus1-3.png"));
    else if (bonus2 == 2)
        setPixmap(QPixmap(":/Images/Images/bonus2-3.png"));
    else if (bonus2 == 3)
        setPixmap(QPixmap(":/Images/Images/bonus3-3.png"));
}

//------------------------------------------

int Bonus::getBonus(int _bonus)
{
    if (_bonus == 1)
    {
        return bonus1;
    }
    else if (_bonus == 2)
    {
        return bonus2;
    }
}
