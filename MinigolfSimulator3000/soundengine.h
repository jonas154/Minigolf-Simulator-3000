#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <QSoundEffect>
#include <QObject>
#include <QtConcurrent/QtConcurrent>
#include <QThreadPool>

#include <QDebug>

class SoundEngine : public QObject
{
    Q_OBJECT

public:

    enum eSound{borderCollisionSound=0, waterSound, birdHitSound, cheeringSound, sandSound, shotSound};

    SoundEngine()
        :
        borderCollision(new QSoundEffect),
        water(new QSoundEffect),
        birdHit(new QSoundEffect),
        cheering(new QSoundEffect),
        sand(new QSoundEffect),
        shot(new QSoundEffect)
    {
        borderCollision->setSource(QUrl::fromLocalFile(":/Sounds/Sounds/bounce2.wav"));
        water->setSource(QUrl::fromLocalFile(":/Sounds/Sounds/water2.wav"));
        birdHit->setSource(QUrl::fromLocalFile(":/Sounds/Sounds/birdHit.wav"));
        cheering->setSource(QUrl::fromLocalFile(":/Sounds/Sounds/cheering.wav"));
        sand->setSource(QUrl::fromLocalFile(":/Sounds/Sounds/sand.wav"));
        shot->setSource(QUrl::fromLocalFile(":/Sounds/Sounds/shot2.wav"));

        pool.setMaxThreadCount(3);
        pool.setExpiryTimeout(-1);
        pool.reserveThread();
    }

    virtual ~SoundEngine(){};


public slots:

    void playSound(int soundNumber)
    {

        //define lambda which should be executed on different thread
        auto play = [this](int num)
        {
            switch(num)
            {
                case borderCollisionSound: // inaktiv; signal in ball.cpp auskommentiert
//                qDebug() << "border collision sound before if";
//                    if(!borderCollision->isPlaying())
//                    {
                        qDebug() << "border collision sound";
                        borderCollision->play();
//                    }
                break;

                case waterSound:
                    water->play();
                break;

                case birdHitSound:
                    birdHit->play();
                break;

                case cheeringSound: // inaktiv; signal in ball.cpp auskommentiert
                    cheering->play();
                break;

                case sandSound:
                    sand->play();
                break;

                case shotSound:
                    shot->play();
                break;

                default: break;

            }

        }; //lambda end

        //start the lambda on a different thread
        QtConcurrent::run(&pool, play, soundNumber);

    }

private:

    QScopedPointer<QSoundEffect> borderCollision;
    QScopedPointer<QSoundEffect> water;
    QScopedPointer<QSoundEffect> birdHit;
    QScopedPointer<QSoundEffect> cheering;
    QScopedPointer<QSoundEffect> sand;
    QScopedPointer<QSoundEffect> shot;

    QThreadPool pool;

};

#endif // SOUNDENGINE_H
