#include "score.h"

Score::Score(QGraphicsItem *parent) : QObject(),QGraphicsPixmapItem(parent)
{
    score = 0;
    setPixmap(QPixmap(":/Images/Images/ball.png"));
}

void Score::increase()
{
    score++;
    if (score == 2)
        setPixmap(QPixmap(":/Images/Images/ball2.png"));
    else if (score == 3)
        setPixmap(QPixmap(":/Images/Images/ball3.png"));
    else if (score == 4)
        setPixmap(QPixmap(":/Images/Images/ball4.png"));
    else if (score == 5)
        setPixmap(QPixmap(":/Images/Images/ball5.png"));
}

int Score::getScore()
{
    return score;
}
