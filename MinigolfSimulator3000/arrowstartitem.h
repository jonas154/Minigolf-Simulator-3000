#ifndef ARROWSTARTITEM_H
#define ARROWSTARTITEM_H

#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QPainter>

// The ArrowStartItem is used to adjust the arrow

class ArrowStartItem : public QGraphicsItem
{
public:
    ArrowStartItem();

    //von QGraphicsItem geerbt
    QRectF boundingRect() const;

    //malt das Item bei jedem Zeitschritt
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    QPointF arrowStartPoint;

};

#endif // ARROWSTARTITEM_H
