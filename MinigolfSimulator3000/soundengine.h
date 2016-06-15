#include <QSound>
#include <QObject>

#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

class SoundEngine : public QObject
{
    Q_OBJECT
public:
    SoundEngine()
        :
        borderCollision(new QSound(":/Sounds/Sounds/click_dummy_sound.wav"))
    {

    }

    virtual ~SoundEngine(){};

    enum eSound{borderCollisionSound=0, waterSound, holeSound};

public slots:
    void playSound(int soundNumber)
    {
        switch(soundNumber)
        {
        case borderCollisionSound:
            borderCollision->play();
            break;
        }
    }

private:
  //pointer
    QScopedPointer<QSound> borderCollision;

};

#endif // SOUNDENGINE_H
