#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "borderline.h"
#include "groundmaterial.h"
#include "courtelement.h"
#include <QStyleOptionGraphicsItem>
#include <QObject>

#include <soundengine.h>


#include <QDebug>

//! This class displays and handles the Ball on the QMainWindow

class Ball : public QObject, public QGraphicsItem
{

Q_OBJECT

public:

    //! Constructor
    Ball(QPointF _startCoordinates);

    //! overrides the boundingRect() function of QGraphicsItem
    QRectF boundingRect() const override;

    //! paints the Ball on the QMainWindow in every time step
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    //! moves the Ball
    void advance(int phase) override;

    //! set the angle of the Ball
    void setAngle(qreal a);

    //! set the speed of the Ball
    void setSpeed(qreal s);

    void playShotSound();

    QPainterPath shape() const override;

signals:

    //! signal that the Ball does not move
    void ballStopped();

    void ballInWater();
    void ballInHole();
    void soundPlay(int);


private:

    qreal angle;
    qreal speed;

    //! counter needed to handle a collision
    int canCollide; //Zähler damit Kollision nicht abspackt, kann besser gelöst werden

    //inline bedeutet: setze den Funktionscode an die Stelle, an der die Funktion aufgerufen wird (zur Optimierung). Kann man, muss man aber nicht machen
    inline void doCollision();

    QString birdDeadPicture;
    int birdDeadCounter;
    QGraphicsPixmapItem* removeBird;

    bool stopped;

    QPointF startCoordinates;

    SoundEngine *soundEnginePointer;


};

#endif // BALL_H
