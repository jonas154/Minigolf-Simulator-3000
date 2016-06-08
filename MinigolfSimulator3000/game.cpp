#include "game.h"
#include "level_1.h"
#include <QGraphicsTextItem>

Game::Game(StartWindow* _startW)
    :
    startW(_startW) // startW = _startW; Initialisierungsliste
{
}

void Game::construct(QGraphicsScene* _scene)
{

    // Player name will replace PLAYER 1
    QGraphicsTextItem* p1 = new QGraphicsTextItem("PLAYER 1");
    p1->setPos(0,0);
    p1->setDefaultTextColor(Qt::white);
    _scene->addItem(p1);

    score1 = new Score();
    score1->setPos(0,25);
    _scene->addItem(score1);

    bonus1 = new Bonus();
    bonus1->setPos(0,50);
    _scene->addItem(bonus1);

    strike1 = new Strike();
    strike1->setPos(0,90);
    _scene->addItem(strike1);

    QGraphicsTextItem* p2 = new QGraphicsTextItem("PLAYER 2");
    p2->setPos(200,0);
    p2->setDefaultTextColor(Qt::white);
    _scene->addItem(p2);

    score2 = new Score();
    score2->setPos(200,25);
    _scene->addItem(score2);

    bonus2 = new Bonus();
    bonus2->setPos(200,50);
    _scene->addItem(bonus2);

    strike2 = new Strike();
    strike2->setPos(200,90);
    _scene->addItem(strike2);

    //whose turn text
    TurnText = new QGraphicsTextItem();
    setTurn(QString("PLAYER 1"));
    TurnText->setPos(400,0);
    TurnText->setDefaultTextColor(Qt::white);
    _scene->addItem(TurnText);
}

void Game::setTurn(QString player)
{
    Turn = player;
    TurnText->setPlainText(player + QString("'s Turn"));
}

QString Game::getTurn()
{
    return Turn;
}

void Game::nextPlayersTurn()
{
    if (getTurn() == QString("PLAYER 1"))
    {
        if(stopTurn == true)
            return;
        else
            setTurn(QString("PLAYER 2"));
    }
    else
    {
        if(stopTurn == true)
            return;
        else
            setTurn(QString("PLAYER 1"));
    }
}

void Game::GameOver() // still working on it
{

    switch(currentLevel)
    {
        case 1:
            delete l1;
        break;

        case 2:
            //delete l2;
        break;

        case 3:
            //delete l3;
            calculateScore();
            if (endScore1 > endScore2)
            {
                TurnText->setPlainText(QString("Player 1 wins!"));
            }
            else if (endScore1 == endScore2)
            {
                TurnText->setPlainText(QString("Tie Game!"));
            }
            else
            {
                TurnText->setPlainText(QString("Player 2 wins!"));
            }
        break;

        default: break;
    }

    //back to main menu and move on next level?

    //wenn direkt das nächste Level aufgeht:
    ++currentLevel;

}

void Game::startLevel(int levelnumber)
{
    currentLevel = levelnumber;

    switch(levelnumber)
    {
        case 1:

            l1 = new Level_1(startW->getUi()->stackedWidget);
            this->construct(l1->getScene());
            l1->show();
            connect(l1->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));

        break;

        case 2:

            l2 = new Level_2(startW->getUi()->stackedWidget);
            this->construct(l2->getScene());
            l2->show();
            connect(l2->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));

        break;

        default: break;
    }
}

void Game::BallinWater()
{
    switch(currentLevel)
    {
        case 1:
            l1->getBall()->setPos(l1->getStartCoordinates());
            l1->createArrow();
        break;

        case 2:
            l2->getBall()->setPos(l1->getStartCoordinates());
            l2->createArrow();
        break;

        default: break;
    }
}

void Game::calculateScore()
{
    endScore1 += (1000 - ((score1->getScore(1)-1)*200)) + ((bonus1->getBonus(1))*500);
    endScore2 += (1000 - ((score2->getScore(2)-1)*200)) + ((bonus2->getBonus(2))*500);
}

void Game::BallinHole()
{
    nextPlayersTurn();
    stopTurn == true;
}

void Game::BallStopped()
{
    switch(currentLevel)
    {
        case 1:
        {
            QPointF coordinates = l1->getBall()->pos();
            //do something with the coordinates, maybe save for multiplayer?
            l1->createArrow();
        }
        break;

        case 2:
        {
            QPointF coordinates = l2->getBall()->pos();
            //do something with the coordinates, maybe save for multiplayer?
            l2->createArrow();
        }
        break;

        default: break;
    }

    //??
    //this->nextPlayersTurn();
}
