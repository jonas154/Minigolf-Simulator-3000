#include "game.h"

#include <QGraphicsTextItem>

Game::Game(StartWindow* _startW)
    :
    startW(_startW)
{
    stopTurn = false;

    connect(&deleteLevel1Timer, SIGNAL(timeout()), this, SLOT(deleteLevel1()));
    connect(&deleteLevel2Timer, SIGNAL(timeout()), this, SLOT(deleteLevel2()));
    connect(&deleteLevel3Timer, SIGNAL(timeout()), this, SLOT(deleteLevel3()));
}

void Game::construct(QGraphicsScene* _scene)
{
    if (startW->getGameMode() == true)
    {
        QGraphicsTextItem* p1 = new QGraphicsTextItem(startW->getActPlayer1Name());
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

        QGraphicsTextItem* p2 = new QGraphicsTextItem(startW->getActPlayer2Name());
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
        setTurn(QString(startW->getActPlayer1Name()));
        TurnText->setPos(400,0);
        TurnText->setDefaultTextColor(Qt::white);
        _scene->addItem(TurnText);
    }
    else
    {
        QGraphicsTextItem* p1 = new QGraphicsTextItem(startW->getActPlayer1Name());
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
    }
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
    if (getTurn() == QString(startW->getActPlayer1Name()))
    {
        if(stopTurn == true)
            return;
        else
            setTurn(QString(startW->getActPlayer2Name()));
    }
    else
    {
        if(stopTurn == true)
            return;
        else
            setTurn(QString(startW->getActPlayer1Name()));
    }
}

void Game::GameOver() // still working on it
{

    switch(currentLevel)
    {
        case 1:
        {
            disconnect(l1->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            disconnect(l1->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            disconnect(l1->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            disconnect(l1.data(), SIGNAL(destroyLevel()), this, SLOT(GameOver()));

            l1->stopAndHide();
            startW->getUi()->stackedWidget->removeWidget(l1.data());
            deleteLevel1Timer.start(1000);
        }
        break;

        case 2:
            disconnect(l2->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            disconnect(l2->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            disconnect(l2->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            disconnect(l2.data(), SIGNAL(destroyLevel2()), this, SLOT(GameOver()));

            l2->stopAndHide();
            startW->getUi()->stackedWidget->removeWidget(l2.data());
            deleteLevel2Timer.start(1000);

        break;

        case 3:

            disconnect(l3->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            disconnect(l3->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            disconnect(l3->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            disconnect(l3.data(), SIGNAL(destroyLevel3()), this, SLOT(GameOver()));

            l3->stopAndHide();
            startW->getUi()->stackedWidget->removeWidget(l3.data());
            deleteLevel3Timer.start(1000);


        /*
            calculateScore();
            if (endScore1 > endScore2)
            {
                TurnText->setPlainText(QString(startW->getActPlayer1Name() + " wins!"));
            }
            else if (endScore1 == endScore2)
            {
                TurnText->setPlainText(QString("Tie Game!"));
            }
            else
            {
                TurnText->setPlainText(QString("Player 2 wins!"));
            }
        */
        break;

        default: break;
    }

    //wenn direkt das nächste Level aufgeht:
    //++currentLevel;

}

void Game::startLevel(int levelnumber)
{
    currentLevel = levelnumber;

    switch(levelnumber)
    {
        case 1:

            l1.reset(new Level_1(startW->getUi()->stackedWidget));
            this->construct(l1->getScene());
            l1->show();
            connect(l1->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            connect(l1->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            connect(l1->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            connect(l1.data(), SIGNAL(destroyLevel()), this, SLOT(GameOver()));

        break;

        case 2:

            l2.reset(new Level_2(startW->getUi()->stackedWidget));
            this->construct(l2->getScene());
            l2->show();
            connect(l2->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            connect(l2->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            connect(l2->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            connect(l2.data(), SIGNAL(destroyLevel2()), this, SLOT(GameOver()));
        break;
        case 3:

            l3.reset(new Level_3(startW->getUi()->stackedWidget));
            this->construct(l3->getScene());
            l3->show();
            connect(l3->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            connect(l3->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            connect(l3->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            connect(l3.data(), SIGNAL(destroyLevel3()), this, SLOT(GameOver()));

        break;

        default: break;
    }
}

void Game::BallinWater()
{
    // time delay for regretting your incompetence and sound being played
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    switch(currentLevel)
    {
        case 1:
            l1->getBall()->setPos(l1->getStartCoordinates());
        break;

        case 2:
            l2->getBall()->setPos(l2->getStartCoordinates());
        break;

        case 3:
            l3->getBall()->setPos(l3->getStartCoordinates());
        break;
        default: break;
    }
}

int Game::calculateScore1()
{
    //endScore1 += (1000 - ((score1->getScore(1)-1)*200)) + ((bonus1->getBonus(1))*500);
    //endScore2 += (1000 - ((score2->getScore(2)-1)*200)) + ((bonus2->getBonus(2))*500);
    endScore1 = endScore1 - 200 + ((bonus1->getBonus(1))*500);
    return endScore1;
}

int Game::calculateScore2()
{
    endScore2 = endScore2 - 200 + ((bonus2->getBonus(2))*500);
    return endScore2;
}

void Game::BallinHole()
{
    switch(currentLevel)
    {
        case 1:

            l1->getBall()->setPos(l1->getHoleCoordinates());

            if (startW->getGameMode() == true)
            {

                if (getTurn() == startW->getActPlayer1Name())
                {
                    strike1->decrease(1);
                    score1->increase(1);
                    qDebug() << "P1's L1 Score:" << calculateScore1();
                }
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);
                    qDebug() << "P2's' L1 Score:" << calculateScore2();
                }

                if(!stopTurn)
                {
                    l1->getBall()->setPos(l1->getStartCoordinates());
                    l1->createArrow();
                }

                nextPlayersTurn();
                stopTurn = true;

            }

            else
            {
                strike1->decrease(1);
                score1->increase(1);
                qDebug() << "P1's L1 Score:" << calculateScore1();
                GameOver();
                startLevel(2);
            }

        break;

        case 2:
            l2->getBall()->setPos(l2->getHoleCoordinates());

            if (startW->getGameMode() == true)
            {

                if (getTurn() == startW->getActPlayer1Name())
                {
                    strike1->decrease(1);
                    score1->increase(1);
                    qDebug() << "P1's L1 Score:" << calculateScore1();
                }
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);
                    qDebug() << "P2's' L1 Score:" << calculateScore2();
                }

                if(!stopTurn)
                {
                    l2->getBall()->setPos(l2->getStartCoordinates());
                    l2->createArrow();
                }

                nextPlayersTurn();
                stopTurn = true;


            }

            else
            {
                strike1->decrease(1);
                score1->increase(1);
                qDebug() << "P1's L1 Score:" << calculateScore1();
                GameOver();
                startLevel(3);
            }
        break;

        case 3:
            l3->getBall()->setPos(l3->getHoleCoordinates());

            if (startW->getGameMode() == true)
            {

                if (getTurn() == startW->getActPlayer1Name())
                {
                    strike1->decrease(1);
                    score1->increase(1);
                    qDebug() << "P1's L1 Score:" << calculateScore1();
                }
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);
                    qDebug() << "P2's' L1 Score:" << calculateScore2();
                }

                if(!stopTurn)
                {
                    l3->getBall()->setPos(l3->getStartCoordinates());
                    l3->createArrow();
                }

                nextPlayersTurn();
                stopTurn = true;

            }

            else
            {
                strike1->decrease(1);
                score1->increase(1);
                qDebug() << "P1's L1 Score:" << calculateScore1();
                GameOver();
        }
        break;

        default: break;
    }

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

            if (startW->getGameMode() == true)
            {

                if (getTurn() == QString(startW->getActPlayer1Name()))
                {
                    strike1->decrease(1);
                    score1->increase(1);
                    qDebug() << "P1:" << calculateScore1();
                    //nextPlayersTurn();
                }
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);
                    qDebug() << "P2:" << calculateScore2();
                    //nextPlayersTurn();
                }

            }
            else
            {
                strike1->decrease(1);
                score1->increase(1);
                qDebug() << "P1:" << calculateScore1();
            }
        }
        break;

        case 2:
        {
            QPointF coordinates = l2->getBall()->pos();
            //do something with the coordinates, maybe save for multiplayer?
            l2->createArrow();

            if (startW->getGameMode() == true)
            {

                if (getTurn() == QString(startW->getActPlayer1Name()))
                {
                    strike1->decrease(1);
                    score1->increase(1);
                    qDebug() << "P1:" << calculateScore1();
                    nextPlayersTurn();
                }
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);
                    qDebug() << "P2:" << calculateScore2();
                    nextPlayersTurn();
                }

            }
            else
            {
                strike1->decrease(1);
                score1->increase(1);
                qDebug() << "P1:" << calculateScore1();
            }
        }

        break;

        case 3:
        {
            QPointF coordinates = l3->getBall()->pos();
            //do something with the coordinates, maybe save for multiplayer?
            l3->createArrow();

            if (startW->getGameMode() == true)
            {

                if (getTurn() == QString(startW->getActPlayer1Name()))
                {
                    strike1->decrease(1);
                    score1->increase(1);
                    qDebug() << "P1:" << calculateScore1();
                    nextPlayersTurn();
                }
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);
                    qDebug() << "P2:" << calculateScore2();
                    nextPlayersTurn();
                }

            }
            else
            {
                strike1->decrease(1);
                score1->increase(1);
                qDebug() << "P1:" << calculateScore1();
            }
        }
        break;
        default: break;
    }

    //??
    //this->nextPlayersTurn();
}

void Game::deleteLevel1()
{
    deleteLevel1Timer.stop();
    l1.reset(nullptr);
}

void Game::deleteLevel2()
{
    deleteLevel2Timer.stop();
    l2.reset(nullptr);
}

void Game::deleteLevel3()
{
    deleteLevel3Timer.stop();
    l3.reset(nullptr);
}
