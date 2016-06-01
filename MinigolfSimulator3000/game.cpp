#include "game.h"
#include "level_1.h"
#include <QGraphicsTextItem>
#include <QDebug>

Game::Game(StartWindow* _startW)
    :
    startW(_startW)
{
}

void Game::construct()
{

    // Player name will replace PLAYER 1
    QGraphicsTextItem* p1 = new QGraphicsTextItem("PLAYER 1");
    p1->setPos(0,0);
    p1->setDefaultTextColor(Qt::white);
    l1->getScene()->addItem(p1);

    score1 = new Score();
    score1->setPos(0,25);
    l1->getScene()->addItem(score1);

    strike1 = new Strike();
    strike1->setPos(0,50);
    l1->getScene()->addItem(strike1);

    QGraphicsTextItem* p2 = new QGraphicsTextItem("PLAYER 2");
    p2->setPos(200,0);
    p2->setDefaultTextColor(Qt::white);
    l1->getScene()->addItem(p2);

    score2 = new Score();
    score2->setPos(200,25);
    l1->getScene()->addItem(score2);

    strike2 = new Strike();
    strike2->setPos(200,50);
    l1->getScene()->addItem(strike2);

    //whose turn text
    TurnText = new QGraphicsTextItem();
    setTurn(QString("PLAYER 1"));
    TurnText->setPos(400,0);
    TurnText->setDefaultTextColor(Qt::white);
    l1->getScene()->addItem(TurnText);
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
    // disable all scene items
    for (size_t i = 0, n = scene->items().size(); i < n; i++)
    {
            scene->items()[i]->setEnabled(false);
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
}

void Game::startLevel(int levelnumber)
{
    l1 = new Level_1(startW->getUi()->stackedWidget);
    this->construct();
    l1->show();

}

//void Game::BallinWater()
//{
//    Level_1->getBall()->setPos(Level_1->get)
//}
