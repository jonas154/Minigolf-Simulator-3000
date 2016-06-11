#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>
#include <QPen>
#include <QPainter>
#include <arrowstartitem.h>
#include <ball.h>
#include <math.h>
#include <cmath>

//! This class draws an arrow between an ArrowStartItem and a Ball
/*! The arrow is used to compute the initial speed and initial angle of the ball for a shot. */

class Arrow : public QGraphicsLineItem
{
public:

    //! Constructor
    Arrow(ArrowStartItem *startItem, Ball *endItem, QGraphicsItem *parent = 0);

    //! Reimplements the boundingRect() function of QGraphicsLineItem
    QRectF boundingRect() const Q_DECL_OVERRIDE;

    //! Returns a QPainterPath including the arrow line and the arrow head
    QPainterPath shape() const Q_DECL_OVERRIDE;

    //! Pointer to the start item of the arrow
    ArrowStartItem *startItem() const { return myStartItem; }

    //! Pointer to the end item of the arrow
    Ball *endItem() const { return myEndItem; }

    //! returns the angle of the arrow
    qreal getAngle();

    //! returns a speed value that is dependent on the length of the arrow
    qreal getSpeed();

    //! updates the position of the arrow
    void updatePosition();

protected:

    //! paints the arrow line and the arrow head in the QMainWindow
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:

    ArrowStartItem *myStartItem;
    Ball *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;
};

#endif // ARROW_H
