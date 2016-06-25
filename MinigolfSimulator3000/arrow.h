#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>
#include <QPen>
#include <QPainter>
#include <arrowstartitem.h>
#include <ball.h>
#include <qmath.h>


//! Draws an arrow between an ArrowStartItem and a Ball
/*! The arrow is used to compute the initial speed and initial angle of the ball for a shot. */

class Arrow : public QGraphicsLineItem
{
public:

    //! Initializes the start item and the end item and sets a QPen with red color
    Arrow(ArrowStartItem *startItem, Ball *endItem, QGraphicsItem *parent = 0);

    //! Reimplements the boundingRect()-function of QGraphicsLineItem
    QRectF boundingRect() const Q_DECL_OVERRIDE;

    //! Returns a QPainterPath including the arrow line and the arrow head
    QPainterPath shape() const Q_DECL_OVERRIDE;

    //! Pointer to the start item of the arrow
    ArrowStartItem *startItem() const { return myStartItem; }

    //! Pointer to the end item of the Arrow which is a Ball
    Ball *endItem() const { return myEndItem; }

    //! Returns the current angle of the Arrow
    qreal getAngle();

    //! Returns a speed value that is dependent on the length of the Arrow
    qreal getSpeed();

    //! Updates the position of the Arrow
    void updatePosition();

protected:

    //! Paints the arrow line and the arrow head in the QMainWindow
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:

    ArrowStartItem *myStartItem;
    Ball *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;
};

#endif // ARROW_H
