#include "soundengine.h"


SoundEngine::SoundEngine()
   :
collision(new QSound(":/sounds/Testsounds/been_bad.wav"))
{

// geht noch nicht, warum auch immer
// connect(Ball,SIGNAL(angleChanged()),this,SLOT(playCollisionSound()));

}

void SoundEngine::playCollisionSound()
{

// collision->play();
}

void SoundEngine::playWinSound(){}
void SoundEngine::playWaterSound(){}
void SoundEngine::playLooseSound(){}
void SoundEngine::playStrikeSound(){}
