﻿#include "game.h"

#include <QGraphicsTextItem>

Game::Game(StartWindow* _startW)
    :
    startW(_startW)
{
    connect(&deleteLevel1Timer, SIGNAL(timeout()), this, SLOT(deleteLevel1()));
    connect(&deleteLevel2Timer, SIGNAL(timeout()), this, SLOT(deleteLevel2()));
    connect(&deleteLevel3Timer, SIGNAL(timeout()), this, SLOT(deleteLevel3()));
    connect(&deleteLevel4Timer, SIGNAL(timeout()), this, SLOT(deleteLevel4()));
}

//------------------------------------------

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

        if (bonus_count1 == 1)
        {
            bonus1->increase1();
        }
        else if (bonus_count1 == 2)
        {
            bonus1->increase1();
            bonus1->increase1();
        }
        else if (bonus_count1 == 3)
        {
            bonus1->increase1();
            bonus1->increase1();
            bonus1->increase1();
        }

        if (bonus_count2 == 1)
        {
            bonus2->increase2();
        }
        else if (bonus_count2 == 2)
        {
            bonus2->increase2();
            bonus2->increase2();
        }
        else if (bonus_count2 == 3)
        {
            bonus2->increase2();
            bonus2->increase2();
            bonus2->increase2();
        }



        strike1 = new Strike();
        strike1->setPos(0,90);
        _scene->addItem(strike1);

        QGraphicsTextItem* p2 = new QGraphicsTextItem(startW->getActPlayer2Name());
        p2->setPos(200-10,0);
        p2->setDefaultTextColor(Qt::white);
        _scene->addItem(p2);

        score2 = new Score();
        score2->setPos(200-10,25);
        _scene->addItem(score2);

        bonus2 = new Bonus();
        bonus2->setPos(200-10,50);
        _scene->addItem(bonus2);

        strike2 = new Strike();
        strike2->setPos(200-10,90);
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

        if (bonus_count1 == 1)
        {
            bonus1->increase1();
        }
        else if (bonus_count1 == 2)
        {
            bonus1->increase1();
            bonus1->increase1();
        }
        else if (bonus_count1 == 3)
        {
            bonus1->increase1();
            bonus1->increase1();
            bonus1->increase1();
        }

        strike1 = new Strike();
        strike1->setPos(0,90);
        _scene->addItem(strike1);

    }

//------------------------------------------

}

void Game::setTurn(QString player)
{
    Turn = player;
    TurnText->setPlainText(player + QString("'s Turn"));
}

//------------------------------------------

QString Game::getTurn()
{
    return Turn;
}

//------------------------------------------

void Game::nextPlayersTurn()
{
    if (getTurn() == QString(startW->getActPlayer1Name()))
    {
        setTurn(QString(startW->getActPlayer2Name()));
    }
    else
    {
        setTurn(QString(startW->getActPlayer1Name()));
    }
}

//------------------------------------------

void Game::GameOver()
{

    switch(currentLevel)
    {
        case 1:
        {
            disconnect(l1->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            disconnect(l1->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            disconnect(l1->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            disconnect(l1.data(), SIGNAL(destroyLevel()), this, SLOT(GameOver()));
            disconnect(l1.data(), SIGNAL(destroyLevel()), this, SLOT(resetScore()));
            disconnect(l1->getBall(), SIGNAL(birdHit()), bonus1, SLOT(increase1()));

            l1->stopAndHide();
            startW->getUi()->stackedWidget->removeWidget(l1.data());
            deleteLevel1Timer.start(500);
        }
        break;

        case 2:
            disconnect(l2->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            disconnect(l2->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            disconnect(l2->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            disconnect(l2.data(), SIGNAL(destroyLevel2()), this, SLOT(GameOver()));
            disconnect(l2.data(), SIGNAL(destroyLevel2()), this, SLOT(resetScore()));
            disconnect(l2->getBall(), SIGNAL(birdHit()), bonus1, SLOT(increase1()));

            l2->stopAndHide();
            startW->getUi()->stackedWidget->removeWidget(l2.data());
            deleteLevel2Timer.start(500);

        break;

        case 3:

            disconnect(l3->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            disconnect(l3->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            disconnect(l3->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            disconnect(l3.data(), SIGNAL(destroyLevel3()), this, SLOT(GameOver()));
            disconnect(l3.data(), SIGNAL(destroyLevel3()), this, SLOT(resetScore()));
            disconnect(l3->getBall(), SIGNAL(birdHit()), bonus1, SLOT(increase1()));

            l3->stopAndHide();
            startW->getUi()->stackedWidget->removeWidget(l3.data());
            deleteLevel3Timer.start(500);

        break;

        case 4:

            disconnect(l4->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            disconnect(l4->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            disconnect(l4->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            disconnect(l4.data(), SIGNAL(destroyLevel4()), this, SLOT(GameOver()));
            disconnect(l4.data(), SIGNAL(destroyLevel4()), this, SLOT(resetScore()));
            disconnect(l4->getBall(), SIGNAL(birdHit()), bonus1, SLOT(increase1()));

            l4->stopAndHide();
            startW->getUi()->stackedWidget->removeWidget(l4.data());
            deleteLevel4Timer.start(500);

            endScore1 = 0;
            endScore2 = 0;

            bonus_count1 = 0;
            bonus_count2 = 0;

        break;

        default: break;
    }

}

//------------------------------------------

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
            connect(l1.data(), SIGNAL(destroyLevel()), this, SLOT(resetScore()));
            connect(l1.data(), SIGNAL(destroyLevel()), this, SLOT(GameOver()));
            connect(l1->getBall(), SIGNAL(birdHit()), bonus1, SLOT(increase1()));

        break;

        case 2:

            l2.reset(new Level_2(startW->getUi()->stackedWidget));
            this->construct(l2->getScene());
            l2->show();
            connect(l2->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            connect(l2->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            connect(l2->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            connect(l2.data(), SIGNAL(destroyLevel2()), this, SLOT(resetScore()));
            connect(l2.data(), SIGNAL(destroyLevel2()), this, SLOT(GameOver()));
            connect(l2->getBall(), SIGNAL(birdHit()), bonus1, SLOT(increase1()));

        break;
        case 3:

            l3.reset(new Level_3(startW->getUi()->stackedWidget));
            this->construct(l3->getScene());
            l3->show();
            connect(l3->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            connect(l3->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            connect(l3->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            connect(l3.data(), SIGNAL(destroyLevel3()), this, SLOT(resetScore()));
            connect(l3.data(), SIGNAL(destroyLevel3()), this, SLOT(GameOver()));
            connect(l3->getBall(), SIGNAL(birdHit()), bonus1, SLOT(increase1()));

        break;

        case 4:

            l4.reset(new Level_4(startW->getUi()->stackedWidget));
            this->construct(l4->getScene());
            l4->show();
            connect(l4->getBall(), SIGNAL(ballStopped()), this, SLOT(BallStopped()));
            connect(l4->getBall(), SIGNAL(ballInWater()), this, SLOT(BallinWater()));
            connect(l4->getBall(), SIGNAL(ballInHole()), this, SLOT(BallinHole()));
            connect(l4.data(), SIGNAL(destroyLevel4()), this, SLOT(resetScore()));
            connect(l4.data(), SIGNAL(destroyLevel4()), this, SLOT(GameOver()));
            connect(l4->getBall(), SIGNAL(birdHit()), bonus1, SLOT(increase1()));

         break;

        default: break;
    }
}

//------------------------------------------

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

        case 4:
            l4->getBall()->setPos(l4->getStartCoordinates());
        break;
        default: break;
    }
}

//------------------------------------------

int Game::calculateScore1()
{
    endScore1 += (1400 - ((score1->getScore(1))*200)) + ((bonus1->getBonus(1))*500);
    return endScore1;
}

//------------------------------------------

int Game::calculateScore2()
{
    endScore2 += (1400 - ((score2->getScore(2))*200)) + ((bonus2->getBonus(2))*500);
    return endScore2;
}

//------------------------------------------

void Game::BallinHole()
{

    switch(currentLevel)
    {
        case 1:
        {
            l1->getBall()->setPos(l1->getHoleCoordinates());

            // time for joy
            QTime dieTime= QTime::currentTime().addSecs(2);
            while (QTime::currentTime() < dieTime) {
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            }

//Multiplayer Mode L1
            if (startW->getGameMode() == true)
            {
                strike1->decrease(1);
                score1->increase(1);

    //first player L1
                if (getTurn() == startW->getActPlayer1Name())
                {
                    if (score1->getScore(1) > 6)
                    {
                        if (bonus1->getBonus(1) > 0)
                        {
                            qDebug() << "Bonus: " << bonus1->getBonus(1);
                            endScore1 = 500;
                            bonus_count1 = 1;
                        }
                        else
                            endScore1 = 0;
                    }
                    else
                    {
                        qDebug() << "Bonus: " << bonus1->getBonus(1);
                        if (bonus1->getBonus(1) > 0)
                        {
                           bonus_count1 = 1;
                        }

                        qDebug() << "P1's L1 Score:" << calculateScore1();
                    }

                    if(startW->getActHighscorePlayer1() < endScore1)
                    {
                        startW->setActPlayer1Highscore(endScore1);
                    }
                    qDebug() << "P1's HighScore:" << startW->getActHighscorePlayer1();

                    nextPlayersTurn();
                    l1->getBall()->setPos(l1->getStartCoordinates());
                    l1->createArrow();
                }

    //second player L1
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);

                    if (score2->getScore(2) > 6)
                    {
                        if (bonus2->getBonus(2) > 0)
                        {
                            endScore2 = 500;
                            bonus_count2 = 1;
                        }
                        else
                            endScore2 = 0;
                    }
                    else
                    {
                        if (bonus2->getBonus(2) > 0)
                        {
                            bonus_count2 = 1;
                        }
                        qDebug() << "P2's L1 Score:" << calculateScore2();
                    }

                    if(startW->getActHighscorePlayer2() < endScore2)
                    {
                        startW->setActPlayer2Highscore(endScore2);
                    }
                    qDebug() << "P2's HighScore:" << startW->getActHighscorePlayer2();

                    GameOver();

                    disconnect(l1->getBall(), SIGNAL(birdHit()), bonus2, SLOT(increase2()));

                    startLevel(2);
                    //startW->setActLevel(2);
                }

            }

//Single Player Mode L1
            else
            {
                strike1->decrease(1);
                score1->increase(1);

                if (score1->getScore(1) > 6)
                {
                    if (bonus1->getBonus(1) > 0)
                    {
                        qDebug() << "Bonus: " << bonus1->getBonus(1);
                        endScore1 = 500;
                        bonus_count1 = 1;
                    }
                    else
                        endScore1 = 0;
                }
                else
                {
                    if (bonus1->getBonus(1) > 0)
                    {
                        bonus_count1 = 1;
                    }
                    qDebug() << "P1's L1 Score:" << calculateScore1();
                }

                if(startW->getActHighscorePlayer1() < endScore1)
                {
                    startW->setActPlayer1Highscore(endScore1);
                }
                qDebug() << "P1's HighScore:" << startW->getActHighscorePlayer1();

                GameOver();
                startLevel(2);

                if(startW->getActLevel() < 2) startW->setActLevel(2);
            }
        }
        break;

        case 2:
        {
            l2->getBall()->setPos(l2->getHoleCoordinates());

            // time for joy
            QTime dieTime= QTime::currentTime().addSecs(2);
            while (QTime::currentTime() < dieTime) {
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            }

//Multiplayer Mode L2
            if (startW->getGameMode() == true)
            {

    //first player L2
                if (getTurn() == startW->getActPlayer1Name())
                {
                    strike1->decrease(1);
                    score1->increase(1);

                    if (score1->getScore(1) > 6)
                    {
                        if (bonus1->getBonus(1) > 0)
                        {
                            qDebug() << "Bonus: " << bonus1->getBonus(1);
                            endScore1 += 500;
                            bonus_count1 += 1;
                        }
                    }
                    else
                    {
                        if (bonus1->getBonus(1) > 0)
                        {
                            bonus_count1 += 1;
                        }
                        qDebug() << "P1's L2 Score:" << calculateScore1();
                    }

                    if(startW->getActHighscorePlayer1() < endScore1)
                    {
                        startW->setActPlayer1Highscore(endScore1);
                    }
                    qDebug() << "P1's HighScore:" << startW->getActHighscorePlayer1();

                    nextPlayersTurn();
                    l2->getBall()->setPos(l2->getStartCoordinates());
                    l2->createArrow();

                    connect(l2->getBall(), SIGNAL(birdHit()), bonus2, SLOT(increase2()));
                }

    //second player L2

                else
                {
                    strike2->decrease(2);
                    score2->increase(2);

                    if (score2->getScore(2) > 6)
                    {
                        if (bonus2->getBonus(2) > 0)
                        {
                            endScore2 += 500;
                            bonus_count2 += 1;
                        }
                    }
                    else
                    {
                        if (bonus2->getBonus(2) > 0)
                        {
                            bonus_count2 += 1;
                        }
                        qDebug() << "P2's L2 Score:" << calculateScore2();
                    }

                    if(startW->getActHighscorePlayer2() < endScore2)
                    {
                        startW->setActPlayer2Highscore(endScore2);
                    }
                    qDebug() << "P2's HighScore:" << startW->getActHighscorePlayer2();

                    GameOver();

                    disconnect(l2->getBall(), SIGNAL(birdHit()), bonus2, SLOT(increase2()));

                    startLevel(3);
                    //startW->setActLevel(3);
                }

            }

//Single Player Mode L2
            else
            {
                strike1->decrease(1);
                score1->increase(1);

                if (score1->getScore(1) > 6)
                {
                    if (bonus1->getBonus(1) > 0)
                    {
                        qDebug() << "Bonus: " << bonus1->getBonus(1);
                        endScore1 += 500;
                        bonus_count1 += 1;
                    }
                }
                else
                {
                    if (bonus1->getBonus(1) > 0)
                    {
                        bonus_count1 += 1;
                    }
                    qDebug() << "P1's L2 Score:" << calculateScore1();
                }

                if(startW->getActHighscorePlayer1() < endScore1)
                {
                    startW->setActPlayer1Highscore(endScore1);
                }
                qDebug() << "P1's HighScore:" << startW->getActHighscorePlayer1();

                GameOver();
                startLevel(3);

                if(startW->getActLevel() < 3) startW->setActLevel(3);
            }
        }
        break;

        case 3:
        {
            l3->getBall()->setPos(l3->getHoleCoordinates());

            // time for joy
            QTime dieTime= QTime::currentTime().addSecs(2);
            while (QTime::currentTime() < dieTime) {
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            }

//Multiplayer Mode L3
            if (startW->getGameMode() == true)
            {

    //first player L3
                if (getTurn() == startW->getActPlayer1Name())
                {
                    strike1->decrease(1);
                    score1->increase(1);

                    if (score1->getScore(1) > 6)
                    {
                        if (bonus1->getBonus(1) > 0)
                        {
                            qDebug() << "Bonus: " << bonus1->getBonus(1);
                            endScore1 += 500;
                            bonus_count1 += 1;
                        }
                    }
                    else
                    {
                        if (bonus1->getBonus(1) > 0)
                        {
                            bonus_count1 += 1;
                        }
                        qDebug() << "P1's L3 Score:" << calculateScore1();
                    }

                    if(startW->getActHighscorePlayer1() < endScore1)
                    {
                        startW->setActPlayer1Highscore(endScore1);
                    }
                    qDebug() << "P1's HighScore:" << startW->getActHighscorePlayer1();

                    nextPlayersTurn();
                    l3->getBall()->setPos(l3->getStartCoordinates());
                    l3->createArrow();

                    connect(l3->getBall(), SIGNAL(birdHit()), bonus2, SLOT(increase2()));
                }

    //second player L3
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);

                    if (score2->getScore(2) > 6)
                    {
                        if (bonus2->getBonus(2) > 0)
                        {
                            qDebug() << "Bonus: " << bonus2->getBonus(2);
                            endScore2 += 500;
                            bonus_count2 += 1;
                        }
                    }
                    else
                    {
                        if (bonus1->getBonus(1) > 0)
                        {
                            bonus_count2 += 1;
                        }
                        qDebug() << "P2's L3 Score:" << calculateScore2();
                    }

                    if(startW->getActHighscorePlayer2() < endScore2)
                    {
                        startW->setActPlayer2Highscore(endScore2);
                    }
                    qDebug() << "P2's HighScore:" << startW->getActHighscorePlayer2();

                    GameOver();

                    disconnect(l3->getBall(), SIGNAL(birdHit()), bonus2, SLOT(increase2()));

                    startLevel(4);
                    //startW->setActLevel(4);
                }

            }

//Single Player Mode L3
            else
            {
                strike1->decrease(1);
                score1->increase(1);

                if (score1->getScore(1) > 6)
                {
                    if (bonus1->getBonus(1) > 0)
                    {
                        qDebug() << "Bonus: " << bonus1->getBonus(1);
                        endScore1 += 500;
                        bonus_count1 += 1;
                    }
                }
                else
                {
                    if (bonus1->getBonus(1) > 0)
                    {
                        bonus_count1 += 1;
                    }
                    qDebug() << "P1's L3 Score:" << calculateScore1();
                }

                if(startW->getActHighscorePlayer1() < endScore1)
                {
                    startW->setActPlayer1Highscore(endScore1);
                }
                qDebug() << "P1's HighScore:" << startW->getActHighscorePlayer1();

                GameOver();
                startLevel(4);
                if(startW->getActLevel() < 4) startW->setActLevel(4);
            }
        }
        break;

        case 4:
        {
            l4->getBall()->setPos(l4->getHoleCoordinates());

            // time for joy
            QTime dieTime= QTime::currentTime().addSecs(2);
            while (QTime::currentTime() < dieTime) {
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            }

    //Multiplayer Mode L4
            if (startW->getGameMode() == true)
            {

    //first player L4
                if (getTurn() == startW->getActPlayer1Name())
                {
                    strike1->decrease(1);
                    score1->increase(1);

                    if (score1->getScore(1) > 6)
                    {
                        if (bonus1->getBonus(1) > 0)
                        {
                            qDebug() << "Bonus: " << bonus1->getBonus(1);
                            endScore1 += 500;
                            bonus_count1 += 1;
                        }
                    }
                    else
                    {
                        if (bonus1->getBonus(1) > 0)
                        {
                            bonus_count1 += 1;
                        }
                        qDebug() << "P1's L3 Score:" << calculateScore1();
                    }

                    if(startW->getActHighscorePlayer1() < endScore1)
                    {
                        startW->setActPlayer1Highscore(endScore1);
                    }
                    qDebug() << "P1's HighScore:" << startW->getActHighscorePlayer1();

                    nextPlayersTurn();
                    l4->getBall()->setPos(l4->getStartCoordinates());
                    l4->createArrow();

                    connect(l4->getBall(), SIGNAL(birdHit()), bonus2, SLOT(increase2()));
                }

    //second player L4
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);

                    if (score2->getScore(2) > 6)
                    {
                        if (bonus2->getBonus(2) > 0)
                        {
                            qDebug() << "Bonus: " << bonus2->getBonus(2);
                            endScore2 += 500;
                            bonus_count2 += 1;
                        }
                    }
                    else
                    {
                        if (bonus1->getBonus(1) > 0)
                        {
                            bonus_count2 += 1;
                        }
                        qDebug() << "P2's L3 Score:" << calculateScore2();
                    }

                    if(startW->getActHighscorePlayer2() < endScore2)
                    {
                        startW->setActPlayer2Highscore(endScore2);
                    }
                    qDebug() << "P2's HighScore:" << startW->getActHighscorePlayer2();

                    GameOver();

                    disconnect(l4->getBall(), SIGNAL(birdHit()), bonus2, SLOT(increase2()));
                }

            }

    //Single Player Mode L4
            else
            {
                strike1->decrease(1);
                score1->increase(1);

                if (score1->getScore(1) > 6)
                {
                    if (bonus1->getBonus(1) > 0)
                    {
                        qDebug() << "Bonus: " << bonus1->getBonus(1);
                        endScore1 += 500;
                        bonus_count1 += 1;
                    }
                }
                else
                {
                    if (bonus1->getBonus(1) > 0)
                    {
                        bonus_count1 += 1;
                    }
                    qDebug() << "P1's L4 Score:" << calculateScore1();
                }

                if(startW->getActHighscorePlayer1() < endScore1)
                {
                    startW->setActPlayer1Highscore(endScore1);
                }
                qDebug() << "P1's HighScore:" << startW->getActHighscorePlayer1();

                GameOver();
            }
        }
        break;

        default: break;
    }

}

//------------------------------------------

void Game::BallStopped()
{
    switch(currentLevel)
    {
        case 1:
        {
            l1->createArrow();

            if (startW->getGameMode() == true)
            {

                if (getTurn() == QString(startW->getActPlayer1Name()))
                {
                    strike1->decrease(1);
                    score1->increase(1);
                }
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);
                }

            }
            else
            {
                strike1->decrease(1);
                score1->increase(1);
            }
        }
        break;

        case 2:
        {
            l2->createArrow();

            if (startW->getGameMode() == true)
            {

                if (getTurn() == startW->getActPlayer1Name())
                {
                    strike1->decrease(1);
                    score1->increase(1);
                }
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);
                }

            }
            else
            {
                strike1->decrease(1);
                score1->increase(1);
            }
        }

        break;

        case 3:
        {
            l3->createArrow();

            if (startW->getGameMode() == true)
            {

                if (getTurn() == QString(startW->getActPlayer1Name()))
                {
                    strike1->decrease(1);
                    score1->increase(1);
                }
                else
                {
                    strike2->decrease(2);
                    score2->increase(2);
                }

            }
            else
            {
                strike1->decrease(1);
                score1->increase(1);
            }
        }
        break;

    case 4:
    {
        l4->createArrow();

        if (startW->getGameMode() == true)
        {

            if (getTurn() == QString(startW->getActPlayer1Name()))
            {
                strike1->decrease(1);
                score1->increase(1);
            }
            else
            {
                strike2->decrease(2);
                score2->increase(2);
            }

        }
        else
        {
            strike1->decrease(1);
            score1->increase(1);
        }
    }
    break;
        default: break;
    }

}

//------------------------------------------

void Game::deleteLevel1()
{
    deleteLevel1Timer.stop();
    l1.reset(0);
}

//------------------------------------------

void Game::deleteLevel2()
{
    deleteLevel2Timer.stop();
    l2.reset(0);
}

//------------------------------------------

void Game::deleteLevel3()
{
    deleteLevel3Timer.stop();
    l3.reset(0);
}

//------------------------------------------

void Game::deleteLevel4()
{
    deleteLevel4Timer.stop();
    l4.reset(0);
}

//------------------------------------------

void Game::resetScore()
{
    endScore1 = 0;
    endScore2 = 0;

    bonus_count1 = 0;
    bonus_count2 = 0;
}
