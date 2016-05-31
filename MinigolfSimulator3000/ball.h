//BEISPIELCODE, WIRD SPÄTER ERSETZT

#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "borderline.h"
#include "courtelement.h"
#include <QStyleOptionGraphicsItem>


class Ball : public QGraphicsItem
{


public:

    Ball();

    //von QGraphicsItem geerbt
    QRectF boundingRect() const;

    //malt den Ball bei jedem Zeitschritt
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

    //bewege Ball
    void advance(int phase);

signals:

    // Signal zur SoundEngie (geht noch nicht)
    void angleChanged();

private:

    qreal angle;
    qreal speed;
    int canCollide; //Zähler damit Kollision nicht abspackt, kann besser gelöst werden

    //inline bedeutet: setze den Funktionscode an die Stelle, an der die Funktion aufgerufen wird (zur Optimierung). Kann man, muss man aber nicht machen
    inline void doCollision();
};

#endif // BALL_H
