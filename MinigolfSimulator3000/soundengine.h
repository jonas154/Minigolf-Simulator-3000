#include <QObject>
#include <QSound>
#include <memory>
#include <ball.h>
#include <QObject>

#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H



class SoundEngine : private QObject
{
Q_OBJECT
public:
    SoundEngine();
public slots:

  void playCollisionSound();
  void playWinSound();
  void playWaterSound();
  void playLooseSound();
  void playStrikeSound();

private:
  //pointer
    std::unique_ptr<QSound> collision;

};

#endif // SOUNDENGINE_H
