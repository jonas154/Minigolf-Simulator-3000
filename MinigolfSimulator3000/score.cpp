#include "score.h"

Score::Score(QGraphicsItem *parent) : QObject(),QGraphicsPixmapItem(parent)
{
    score1 = 0;
    score2 = 0;
    setPixmap(QPixmap(":/Images/Images/ball0-7.png"));
}

//------------------------------------------

void Score::increase(int _score)
{
    if (_score == 1)
    {
        score1++;
        if (score1 == 1)
            setPixmap(QPixmap(":/Images/Images/ball1-7.png"));
        else if (score1 == 2)
            setPixmap(QPixmap(":/Images/Images/ball2-7.png"));
        else if (score1 == 3)
            setPixmap(QPixmap(":/Images/Images/ball3-7.png"));
        else if (score1 == 4)
            setPixmap(QPixmap(":/Images/Images/ball4-7.png"));
        else if (score1 == 5)
            setPixmap(QPixmap(":/Images/Images/ball5-7.png"));
        else if (score1 == 6)
            setPixmap(QPixmap(":/Images/Images/ball6-7.png"));
        else if (score1 == 7)
            setPixmap(QPixmap(":/Images/Images/ball7-7.png"));
    }

    else if (_score == 2)
    {
        score2++;
        if (score2 == 1)
            setPixmap(QPixmap(":/Images/Images/ball1-7.png"));
        else if (score2 == 2)
            setPixmap(QPixmap(":/Images/Images/ball2-7.png"));
        else if (score2 == 3)
            setPixmap(QPixmap(":/Images/Images/ball3-7.png"));
        else if (score2 == 4)
            setPixmap(QPixmap(":/Images/Images/ball4-7.png"));
        else if (score2 == 5)
            setPixmap(QPixmap(":/Images/Images/ball5-7.png"));
        else if (score2 == 6)
            setPixmap(QPixmap(":/Images/Images/ball6-7.png"));
        else if (score2 == 7)
            setPixmap(QPixmap(":/Images/Images/ball7-7.png"));
    }

}

//------------------------------------------

int Score::getScore(int _score)
{
    if (_score == 1)
    {
        return score1;
    }
    else if (_score == 2)
    {
        return score2;
    }
}
