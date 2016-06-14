#ifndef ARROWSTARTITEM_H
#define ARROWSTARTITEM_H

#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include "ball.h"


//! The ArrowStartItem is moveable and used to adjust the arrow.
/*! It inherits from a QGraphicsItem and also from QObject because a signal is emitted. */

class ArrowStartItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    //! Constructor
    ArrowStartItem(Ball* _ball, bool _firstCreate = false);

    //! overrides the boundingRect() function of QGraphicsItem
    QRectF boundingRect() const override;

    //! paints the item in every time step
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    //! overrides the mouseReleaseEvent() function of QGraphicsItem such that a signal is emitted
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    //! overrides the itemChange() function of QGraphicsItem and limits the distance between the Ball and the ArrowStartItem
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

signals:

    //! signal that the mouse is released from the ArrowStartItem
    void arrowStartItemReleased();

private:

    //! Pointer to the ball
    Ball* ball;

    //! needed to implement a limitation of the distance between the ball and the ArrowStartItem
    bool firstCreate;

    bool changeReceived;

};

#endif // ARROWSTARTITEM_H
