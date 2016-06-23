#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QObject>
#include "bonus.h"
#include "score.h"
#include "strike.h"
#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
#include "level_4.h"
#include "startwindow.h"
#include "ball.h"


class StartWindow;

class Game : public QObject
{
    Q_OBJECT

public:

    //! \brief Constructor
    Game(StartWindow* _startW);

    //! \brief Set turn to current player name
    void setTurn(QString player);

    //! \brief Return current turn
    QString getTurn();

    //! \brief Proceed to second player's turn
    void nextPlayersTurn();

    //! \brief Return the first player's score
    int calculateScore1();

    //! \brief Return the second player's score
    int calculateScore2();

    Bonus *bonus1, *bonus2;
    Score *score1, *score2;
    Strike *strike1, *strike2;
    QScopedPointer<Level_1> l1;
    QScopedPointer<Level_2> l2;
    QScopedPointer<Level_3> l3;
    QScopedPointer<Level_4> l4;

public slots:

    //! \brief Calculate score and proceed to next player's turn (MP Mode) or next level(SP Mode)
    void BallinHole();

    //! \brief Increase score bar and decrease strike bar
    void BallStopped();

    //! \brief Reset ball position to the start point
    void BallinWater();

    //! \brief Hide current level and disconnect current signals/slots
    void GameOver();

    //! \brief Start a chosen level and connect required signals/slots
    void startLevel(int levelnumber);

private:

    QString Turn;
    QGraphicsTextItem *TurnText;
    StartWindow* startW;
    int currentLevel;
    int endScore1 = 0, endScore2 = 0;
    int bonus_count1 = 0, bonus_count2 = 0;

    //! \brief Display player's name, score, strike, turn
    void construct(QGraphicsScene* _scene);

    QTimer deleteLevel1Timer;
    QTimer deleteLevel2Timer;
    QTimer deleteLevel3Timer;
    QTimer deleteLevel4Timer;

private slots:

    //! \brief Delete level 1
    void deleteLevel1();

    //! \brief Delete level 2
    void deleteLevel2();

    //! \brief Delete level 3
    void deleteLevel3();

    //! \brief Delete level 4
    void deleteLevel4();


};

#endif // GAME_H
