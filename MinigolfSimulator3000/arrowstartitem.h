#ifndef ARROWSTARTITEM_H
#define ARROWSTARTITEM_H

#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include "ball.h"

#include <QDebug>

// The ArrowStartItem is used to adjust the arrow

class ArrowStartItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    ArrowStartItem(Ball* _ball, bool _firstCreate = false);

    //von QGraphicsItem geerbt
    QRectF boundingRect() const override;

    //malt das Item bei jedem Zeitschritt
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

signals:
    void arrowStartItemReleased();

private:
    QPointF arrowStartPoint;

    Ball* ball;

    bool firstCreate;

};

#endif // ARROWSTARTITEM_H
