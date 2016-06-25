#include "arrow.h"

Arrow::Arrow(ArrowStartItem *startItem, Ball *endItem, QGraphicsItem *parent)
    : QGraphicsLineItem(parent)
{
    myStartItem = startItem;
    myEndItem = endItem;
    myColor = Qt::red;
    setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}

QRectF Arrow::boundingRect() const
{
    // The Reimplementation is necessary because the arrow with its head occupies more space in the QMainWindow.
    // The bounding rectangle must include the whole arrow such that the right space of the QMainWindow can be updated

    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

QPainterPath Arrow::shape() const
{
    // The arrow line and the arrow head are added to a QPainterPath

    QPainterPath path = QGraphicsLineItem::shape();
    path.addPolygon(arrowHead);
    return path;
}

qreal Arrow::getAngle()
{
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    setLine(line);

    qreal angle = line.angle();

    angle = 360 - angle;
    angle = angle - 90;

    // The angle is measured clockwise and a zero degree direction points in negative y-direction.
    // The angle ranges from 0 to 360 degrees and the corresponding negative angles also occur.

    return angle;
}

qreal Arrow::getSpeed()
{
    qreal length;

    // set the scalingFactor to an appropriate value for a fun game
    qreal scalingFactor = 0.04;

    // the length of the arrow line is computed via the hypotenuse of a right-angled triangle
    length = std::sqrt((startItem()->pos().x()-endItem()->pos().x())*(startItem()->pos().x()-endItem()->pos().x())+(startItem()->pos().y()-endItem()->pos().y())*(startItem()->pos().y()-endItem()->pos().y()));

    // the speed for the ball is set to a multiplication of the arrow length with a scaling factor
    return scalingFactor * length;
}

void Arrow::updatePosition()
{
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    setLine(line);
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
          QWidget *)
{
    if (myStartItem->collidesWithItem(myEndItem))
    {
//      no arrow possible because items collide
        return;
    }

    // draw line between items
    QPen myPen = pen();
    myPen.setColor(myColor);
    painter->setPen(myPen);
    painter->setBrush(myColor);

    setLine(QLineF(myEndItem->pos(), myStartItem->pos()));
    painter->drawLine(line());

    // add arrow head
    qreal arrowSize = 15;
    double angle = ::acos(line().dx() / line().length());
       if (line().dy() >= 0)
           angle = (M_PI * 2) - angle;

           QPointF arrowP1 = line().p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                           cos(angle + M_PI / 3) * arrowSize);
           QPointF arrowP2 = line().p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                           cos(angle + M_PI - M_PI / 3) * arrowSize);

           arrowHead.clear();
           arrowHead << line().p1() << arrowP1 << arrowP2;

    painter->drawPolygon(arrowHead);

}


