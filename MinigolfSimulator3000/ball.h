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
#include <QTimer>
#include <soundengine.h>


//! This class handles the ball animation and physical interaction with the Court
class Ball : public QObject, public QGraphicsItem
{

Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:

    //! Constructor
    //! @param _startCoordinates The start coordinates of the active level
    Ball(QPointF _startCoordinates);

    //! Overrides the boundingRect() function of QGraphicsItem
    QRectF boundingRect() const override;

    //! Paints the Ball on the QMainWindow in every time step
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    //! Moves the Ball
    void advance(int phase) override;

    //! Set the angle of the Ball
    //! @param a The new angle
    void setAngle(qreal a);

    //! Set the speed of the Ball
    //! @param s The new speed
    void setSpeed(qreal s);

    //! Emits a signal whenever a shot is done
    void playShotSound();

    //! Sets a circular shape for the Ball
    QPainterPath shape() const override;



signals:

    //! Signal that the Ball does not move
    void ballStopped();

    //! Signal that the Ball is over a water ground material
    void ballInWater();

    //! Signal that the Ball is over a hole ground material
    void ballInHole();

    //! Signal that a certain sound effect occurs
    void soundPlay(int);

    //! Signal that the Bird is hit
    void birdHit();


private:

    qreal angle;
    qreal speed;

    int canCollide; // counter needed to handle a collision

    void doCollision();

    QString birdDeadPicture;
    int birdDeadCounter;
    QGraphicsPixmapItem* removeBird;

    bool stopped;

    QPointF startCoordinates;

    SoundEngine *soundEnginePointer;

    bool isBirdDead;

};

#endif // BALL_H
