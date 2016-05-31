#include "arrowstartitem.h"

ArrowStartItem::ArrowStartItem()
{
    arrowStartPoint = QPointF(0.0,0.0);

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

}

QRectF ArrowStartItem::boundingRect() const
{
    return QRectF(-7,-7,14,14); //Größe 16*16, Mittelpunkt für Rotation in der Mitte
}

void ArrowStartItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setClipRect(option->exposedRect);

    QRectF rec = boundingRect();
    QBrush brush(Qt::red);

    painter->fillRect(rec,brush);

}
