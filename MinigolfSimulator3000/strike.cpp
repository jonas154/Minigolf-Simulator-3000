#include "strike.h"

Strike::Strike(QGraphicsItem *parent) : QObject(),QGraphicsPixmapItem(parent)
{
    strike1 = 5;
    strike2 = 5;
    setPixmap(QPixmap(":/Images/Images/club5.png"));
}

void Strike::decrease(int _strike)
{
    if (_strike == 1)
    {
        strike1--;
        if (strike1 == 4)
            setPixmap(QPixmap(":/Images/Images/club4.png"));
        else if (strike1 == 3)
            setPixmap(QPixmap(":/Images/Images/club3.png"));
        else if (strike1 == 2)
            setPixmap(QPixmap(":/Images/Images/club2.png"));
        else if (strike1 == 1)
            setPixmap(QPixmap(":/Images/Images/club.png"));
        else if (strike1 == 0)
            setPixmap(QPixmap());
    }
    else if (_strike == 2)
    {
        strike2--;
        if (strike2 == 4)
            setPixmap(QPixmap(":/Images/Images/club4.png"));
        else if (strike2 == 3)
            setPixmap(QPixmap(":/Images/Images/club3.png"));
        else if (strike2 == 2)
            setPixmap(QPixmap(":/Images/Images/club2.png"));
        else if (strike2 == 1)
            setPixmap(QPixmap(":/Images/Images/club.png"));
        else if (strike2 == 0)
            setPixmap(QPixmap());
    }

}

int Strike::getStrike(int _strike)
{
    if (_strike == 1)
    {
        return strike1;
    }
    else if (_strike == 2)
    {
        return strike2;
    }
}
