#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <QObject>
#include <QMediaPlayer>

//! Plays sound effects for certain events during the game
/*! There is one slot with an enumeration parameter such that various sounds can be played */

class SoundEngine : public QObject
{
    Q_OBJECT

public:

    //! Enumeration lisiting the available sounds
    enum eSound{borderCollisionSound=0, waterSound, birdHitSound, cheeringSound, sandSound, shotSound, lavaSound};

    //! Constructor, initializes a QMediaPlayer and sets the file paths
    SoundEngine()
        :
        borderCollision(new QMediaPlayer),
        water(new QMediaPlayer),
        birdHit(new QMediaPlayer),
        cheering(new QMediaPlayer),
        sand(new QMediaPlayer),
        shot(new QMediaPlayer),
        lava(new QMediaPlayer)

    {
        borderCollision->setMedia(QUrl("qrc:/Sounds/Sounds/woodBounce.wav"));
        water->setMedia(QUrl("qrc:/Sounds/Sounds/water2.wav"));
        birdHit->setMedia(QUrl("qrc:/Sounds/Sounds/birdHit.wav"));
        cheering->setMedia(QUrl("qrc:/Sounds/Sounds/cheering2.wav"));
        sand->setMedia(QUrl("qrc:/Sounds/Sounds/sand2.wav"));
        shot->setMedia(QUrl("qrc:/Sounds/Sounds/golfHit.wav"));
        lava->setMedia(QUrl("qrc:/Sounds/Sounds/lavaBurn.wav"));

        borderCollision->setVolume(80);
        water->setVolume(90);
        cheering->setVolume(90);
        birdHit->setVolume(80);
        cheering->setVolume(90);
        lava->setVolume(90);

    }

    //! Destructor
    virtual ~SoundEngine(){};


public slots:

    //! Plays the sound that is requested by the enumeration parameter
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

            case lavaSound:
                lava->play();
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
    QScopedPointer<QMediaPlayer> lava;

};

#endif // SOUNDENGINE_H
