#include "game.h"
#include "level_1.h"
#include <QGraphicsTextItem>
#include <QDebug>

Game::Game(StartWindow* _startW)
    :
    startW(_startW)
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

    strike1 = new Strike();
    strike1->setPos(0,50);
    _scene->addItem(strike1);

    QGraphicsTextItem* p2 = new QGraphicsTextItem("PLAYER 2");
    p2->setPos(200,0);
    p2->setDefaultTextColor(Qt::white);
    _scene->addItem(p2);

    score2 = new Score();
    score2->setPos(200,25);
    _scene->addItem(score2);

    strike2 = new Strike();
    strike2->setPos(200,50);
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
        setTurn(QString("PLAYER 2"));
    }
    else
    {
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

        default: break;

    }

    if (score1->getScore() < score2->getScore())
    {
        TurnText->setPlainText(QString("Player 1 wins!"));
    }
    else if (score1->getScore() == score2->getScore())
    {
        TurnText->setPlainText(QString("Tie Game!"));
    }
    else
    {
        TurnText->setPlainText(QString("Player 2 wins!"));
    }


    //back to main menu and move on next level

    //wenn direkt das nächste Level aufgeht:
    //++currentLevel;

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

        break;

        case 2:

            //l2 = new Level_2(startW->getUi()->stackedWidget);
            //this->construct(l2->getScene());
            //l2->show();

        break;

        default: break;
    }
}

//void Game::BallinWater()
//{
//    l1->getBall()->setPos(Level_1->getStartCoordinates());
//}
