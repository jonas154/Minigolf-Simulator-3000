#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <QObject>
#include <QMediaPlayer>

class SoundEngine : public QObject
{
    Q_OBJECT

public:

    enum eSound{borderCollisionSound=0, waterSound, birdHitSound, cheeringSound, sandSound, shotSound};

    SoundEngine()
        :
        borderCollision(new QMediaPlayer),
        water(new QMediaPlayer),
        birdHit(new QMediaPlayer),
        cheering(new QMediaPlayer),
        sand(new QMediaPlayer),
        shot(new QMediaPlayer)
    {
        borderCollision->setMedia(QUrl("qrc:/Sounds/Sounds/bounce5.wav"));
        water->setMedia(QUrl("qrc:/Sounds/Sounds/water2.wav"));
        birdHit->setMedia(QUrl("qrc:/Sounds/Sounds/birdHit.wav"));
        cheering->setMedia(QUrl("qrc:/Sounds/Sounds/cheering2.wav"));
        sand->setMedia(QUrl("qrc:/Sounds/Sounds/sand2.wav"));
        shot->setMedia(QUrl("qrc:/Sounds/Sounds/shot2.wav"));

    }

    virtual ~SoundEngine(){};


public slots:

    void playSound(int soundNumber)
    {
        switch(soundNumber)
        {
            case borderCollisionSound:
                borderCollision->play();
            break;

            case waterSound:
                water->play();
            break;

            case birdHitSound:
                birdHit->play();
            break;

            case cheeringSound:
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



    }

private:

    QScopedPointer<QMediaPlayer> borderCollision;
    QScopedPointer<QMediaPlayer> water;
    QScopedPointer<QMediaPlayer> birdHit;
    QScopedPointer<QMediaPlayer> cheering;
    QScopedPointer<QMediaPlayer> sand;
    QScopedPointer<QMediaPlayer> shot;

};

#endif // SOUNDENGINE_H
