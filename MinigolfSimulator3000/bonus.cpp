#include "bonus.h"

Bonus::Bonus(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    bonus1 = 0;
    bonus2 = 0;
    setPixmap(QPixmap(":/Images/Images/bonus1.png"));
}

void Bonus::increase(int _bonus)
{
    if (_bonus == 1)
    {
        bonus1++;
        //new pixmap for more bonus
    }
    else if (_bonus == 2)
    {
        bonus2++;
    }
}

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
