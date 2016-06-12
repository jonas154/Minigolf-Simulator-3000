#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QObject>
#include "bonus.h"
#include "score.h"
#include "strike.h"
#include "level_1.h"
#include "level_2.h"
#include "startwindow.h"
#include "ball.h"


class StartWindow;

class Game : public QObject
{
    Q_OBJECT

public:

    Game(StartWindow* _startW);

    void setTurn(QString player);
    QString getTurn();
    void nextPlayersTurn();
    void calculateScore();

    Bonus *bonus1, *bonus2;
    Score *score1, *score2;
    Strike *strike1, *strike2;
    Level_1 *l1;
    Level_2* l2;
    int endScore1 = 0, endScore2 = 0;

public slots:

    void BallinHole();
    void BallStopped();
    void BallinWater();
    void GameOver();
    void startLevel(int levelnumber);

private:

    QString Turn;
    QGraphicsTextItem *TurnText;
    StartWindow* startW;
    int currentLevel;
    bool stopTurn; // now game knows when to stop changing Turn

    void construct(QGraphicsScene* _scene);

};

#endif // GAME_H
