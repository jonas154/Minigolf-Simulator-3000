#include "arrow.h"
#include "math.h"
#include "cmath"

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
    qreal extra = (pen().width() + 20) / 2.0;

    return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                      line().p2().y() - line().p1().y()))
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

QPainterPath Arrow::shape() const
{
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

//    qDebug() << "angle handed to ball: " << angle;
    return angle;
}

qreal Arrow::getSpeed()
{
    qreal speed;
    qreal scalingFactor = 0.05;
    speed = 0.75*std::sqrt((startItem()->pos().x()-endItem()->pos().x())*(startItem()->pos().x()-endItem()->pos().x())+(startItem()->pos().y()-endItem()->pos().y())*(startItem()->pos().y()-endItem()->pos().y()));
    return scalingFactor * speed;
}

void Arrow::updatePosition()
{
    QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    //if(line.length()>100.0) line.setLength(100.0);
    setLine(line);
}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
          QWidget *)
{
    if (myStartItem->collidesWithItem(myEndItem))
    {
//        std::cout << "no arrow possible because items collide" << std::endl;
        return;
    }

    // draw line between items
    QPen myPen = pen();
    myPen.setColor(myColor);
    painter->setPen(myPen);
    painter->setBrush(myColor);

    setLine(QLineF(myEndItem->pos(), myStartItem->pos()));
    painter->drawLine(line());

    // add arrow tip
    qreal arrowSize = 15;
    double angle = ::acos(line().dx() / line().length());
       if (line().dy() >= 0)
           angle = (Pi * 2) - angle;

           QPointF arrowP1 = line().p1() + QPointF(sin(angle + Pi / 3) * arrowSize,
                                           cos(angle + Pi / 3) * arrowSize);
           QPointF arrowP2 = line().p1() + QPointF(sin(angle + Pi - Pi / 3) * arrowSize,
                                           cos(angle + Pi - Pi / 3) * arrowSize);

           arrowHead.clear();
           arrowHead << line().p1() << arrowP1 << arrowP2;

    painter->drawPolygon(arrowHead);

}


