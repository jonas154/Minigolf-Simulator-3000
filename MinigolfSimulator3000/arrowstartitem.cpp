#include "arrowstartitem.h"

ArrowStartItem::ArrowStartItem(Ball* _ball, bool _firstCreate)
    :
    ball(_ball), firstCreate(_firstCreate), changeReceived(false)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    this->setPos(ball->pos()-QPointF(0.0,-50.0));
}

QRectF ArrowStartItem::boundingRect() const
{
    /*! The Reimplementation is necessary because the ArrowStartItem occupies more space in the QMainWindow */

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
    if(changeReceived) emit arrowStartItemReleased();
}


QVariant ArrowStartItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if(change==ItemPositionChange&&scene())
    {
        changeReceived = true;

        QPointF newPos;

        //bug workaround
        //on first creation, value is relative to point (0,0) of scene
        //on the next creations, value is relative to this->pos()
        //WTF???

        if(firstCreate) newPos = value.toPointF();
        else newPos = ball->pos() - QPointF(0.0,-50.0) + value.toPointF();

        QLineF line(ball->pos(), newPos);

        if(line.length() > 150.0)
        {
            line.setLength(150.0);
            newPos.setX(line.x2());
            newPos.setY(line.y2());
        }
        return newPos;
    }
    else
    {
        return QGraphicsItem::itemChange(change, value);
    }
}
