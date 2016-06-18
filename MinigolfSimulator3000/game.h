#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QObject>
#include "bonus.h"
#include "score.h"
#include "strike.h"
#include "level_1.h"

#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
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
    int calculateScore1();
    int calculateScore2();

    Bonus *bonus1, *bonus2;
    Score *score1, *score2;
    Strike *strike1, *strike2;
    QScopedPointer<Level_1> l1;
    QScopedPointer<Level_2> l2;
    QScopedPointer<Level_3> l3;

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
    int endScore1 = 0, endScore2 = 0;

    void construct(QGraphicsScene* _scene);

    QTimer deleteLevel1Timer;
    QTimer deleteLevel2Timer;
    QTimer deleteLevel3Timer;

private slots:

    void deleteLevel1();
    void deleteLevel2();
    void deleteLevel3();


};

#endif // GAME_H
