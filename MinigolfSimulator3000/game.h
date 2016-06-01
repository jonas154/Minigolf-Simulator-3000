#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>

#include "score.h"
#include "strike.h"
#include "court.h"
#include "level_1.h"
#include "startwindow.h"

class StartWindow;

class Game : public Court
{
    Q_OBJECT
public:
    Game(StartWindow* _startW);

    void setTurn(QString player);
    QString getTurn();
    void nextPlayersTurn();

    Score *score1, *score2;
    Strike *strike1, *strike2;
    Level_1 *l1;

    void construct();

public slots:
    //void BallinHole();
    //void BallinWater(); getBall setStartCoor
    //void BallStopped(QPoint coordinates);
    void GameOver();
    void startLevel(int levelnumber);

private:
    QString Turn;
    QGraphicsTextItem *TurnText;
    StartWindow* startW;

};

#endif // GAME_H
