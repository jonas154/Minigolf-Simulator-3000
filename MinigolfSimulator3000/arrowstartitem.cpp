#include "arrowstartitem.h"

ArrowStartItem::ArrowStartItem(Ball* _ball)
    :
    ball(_ball)
{
    arrowStartPoint = QPointF(0.0,0.0);

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    setPos(ball->pos()-QPointF(0.0,-50.0));

}

QRectF ArrowStartItem::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void ArrowStartItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setClipRect(option->exposedRect);

    QRectF rec = QRectF(-7,-7,14,14);
    QBrush brush(Qt::red);

    painter->fillRect(rec,brush);

}

void ArrowStartItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    emit arrowStartItemReleased();
}


QVariant ArrowStartItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if(change==ItemPositionChange&&scene())
    {
        QPointF newPos = value.toPointF();
        QLineF line(ball->pos(), newPos);

        if(line.length() > 150.0)
        {
            line.setLength(150.0);
            newPos.setX(line.x2());
            newPos.setY(line.y2());
        }
        return newPos;
    }
    return QGraphicsItem::itemChange(change, value);
}
