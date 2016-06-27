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

//! \brief This class handles the game logic
class Game : public QObject
{
    Q_OBJECT

public:

    //! \brief Constructor
    //! @param _startW Pointer to the StartWindow
    Game(StartWindow* _startW);    

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

    //! \brief Pointers to bonus objects
    Bonus *bonus1, *bonus2;

    //! \brief Pointers to score objects
    Score *score1, *score2;

    //! \brief Pointers to strike objects
    Strike *strike1, *strike2;

    //! \brief Pointer to level 1
    QScopedPointer<Level_1> l1;

    //! \brief Pointer to level 1
    QScopedPointer<Level_2> l2;

    //! \brief Pointer to level 1
    QScopedPointer<Level_3> l3;

    //! \brief Pointer to level 1
    QScopedPointer<Level_4> l4;

    //! \brief Display player's name, score, strike, turn
    void construct(QGraphicsScene* _scene);

    QString Turn;
    QGraphicsTextItem *TurnText;
    StartWindow* startW;
    int currentLevel;
    int endScore1 = 0, endScore2 = 0;
    int bonus_count1 = 0, bonus_count2 = 0;

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

    //! \brief Reset score and bonus to 0
    void resetScore();

};

#endif // GAME_H
