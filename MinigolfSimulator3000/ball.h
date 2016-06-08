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

#include <QDebug>

class Ball : public QObject, public QGraphicsItem
{

Q_OBJECT

public:

    Ball();

    //von QGraphicsItem geerbt
    QRectF boundingRect() const override;

    //malt den Ball bei jedem Zeitschritt
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    //bewege Ball
    void advance(int phase) override;

    void setAngle(qreal a);
    void setSpeed(qreal s);

signals:

    void ballStopped();

private:

    qreal angle;
    qreal speed;
    int canCollide; //Zähler damit Kollision nicht abspackt, kann besser gelöst werden

    //inline bedeutet: setze den Funktionscode an die Stelle, an der die Funktion aufgerufen wird (zur Optimierung). Kann man, muss man aber nicht machen
    inline void doCollision();

    QString birdDeadPicture;
    int birdDeadCounter;
    QGraphicsPixmapItem* removeBird;

    bool stopped;
};

#endif // BALL_H
