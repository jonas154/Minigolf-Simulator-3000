#include "strike.h"

Strike::Strike(QGraphicsItem *parent) : QObject(),QGraphicsPixmapItem(parent)
{
    strike = 5;
    setPixmap(QPixmap(":/Images/Images/club5.png"));
}

void Strike::decrease()
{
    strike--;
    if (strike == 4)
        setPixmap(QPixmap(":/Images/Images/club4.png"));
    else if (strike == 3)
        setPixmap(QPixmap(":/Images/Images/club3.png"));
    else if (strike == 2)
        setPixmap(QPixmap(":/Images/Images/club2.png"));
    else if (strike == 1)
        setPixmap(QPixmap(":/Images/Images/club.png"));
}

int Strike::getStrike()
{
    return strike;
}
