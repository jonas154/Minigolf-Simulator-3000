#ifndef ARROWSTARTITEM_H
#define ARROWSTARTITEM_H

#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include "ball.h"


//! The ArrowStartItem is moveable and used to adjust the Arrow.
/*! It inherits from a QGraphicsItem and also from QObject because a signal is emitted. */

class ArrowStartItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    //! Initializes its position 50 pixels beneath the current Ball position
    ArrowStartItem(Ball* _ball, bool _firstCreate = false);

    //! Overrides the boundingRect() function of QGraphicsItem
    QRectF boundingRect() const override;

    //! Paints the item in every time step
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    //! Overrides the mouseReleaseEvent() function of QGraphicsItem such that a signal is emitted
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    //! Overrides the itemChange() function of QGraphicsItem and limits the distance between the Ball and the ArrowStartItem
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

signals:

    //! Signal that the mouse is released from the ArrowStartItem
    void arrowStartItemReleased();

private:

    Ball* ball;
    bool firstCreate; // needed to implement a limitation of the distance between the ball and the ArrowStartItem
    bool changeReceived;

};

#endif // ARROWSTARTITEM_H
