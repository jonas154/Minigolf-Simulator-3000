#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>
#include <QPen>
#include <QPainter>

#include <iostream>
#include <arrowstartitem.h>
#include <ball.h>
#include <math.h>
#include <cmath>

const qreal Pi = 3.14;

// This class draws an arrow between the ArrowStartItem and the Ball
// the arrow is used to compute the inital speed and inital angle for a shot
// The ArrowStartItem is moveable such that the speed and angle can be adjusted

class Arrow : public QGraphicsLineItem
{
public:

    //! \brief Constructor
    Arrow(ArrowStartItem *startItem, Ball *endItem, QGraphicsItem *parent = 0);

    //! \brief Reimplements the boundingRect() fct of QGraphicsLineItem
    //! because the arrow with its tip is thicker than a line
    QRectF boundingRect() const Q_DECL_OVERRIDE;

    //! \brief Returns QPainterPath including arrow line and arrow tip
    QPainterPath shape() const Q_DECL_OVERRIDE;

    ArrowStartItem *startItem() const { return myStartItem; }
    Ball *endItem() const { return myEndItem; }

    qreal getAngle();
    qreal getSpeed();

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:
    ArrowStartItem *myStartItem;
    Ball *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;
};

#endif // ARROW_H
