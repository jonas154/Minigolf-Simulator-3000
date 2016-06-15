#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H


#include <QSoundEffect>
#include <QObject>
#include <QtConcurrent/QtConcurrent>
#include <QThreadPool>


class SoundEngine : public QObject
{
    Q_OBJECT

public:

    enum eSound{borderCollisionSound=0, waterSound, holeSound};

    SoundEngine()
        :
        borderCollision(new QSoundEffect)
    {
        borderCollision->setSource(QUrl::fromLocalFile(":/Sounds/Sounds/click_dummy_sound.wav"));

        pool.setMaxThreadCount(1);
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
                case borderCollisionSound:

                    if(!borderCollision->isPlaying())
                    {
                        borderCollision->play();
                    }

                break;

                case waterSound:

                break;

                default: break;

            }

        }; //lambda end

        //start the lambda on a different thread
        QtConcurrent::run(&pool, play, soundNumber);

    }

private:

    QScopedPointer<QSoundEffect> borderCollision;

    QThreadPool pool;

};

#endif // SOUNDENGINE_H
