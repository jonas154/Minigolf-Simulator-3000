#include "rectitem.h"
#include <QDebug>
#include "game.h"

RectItem::RectItem()

{

}
void RectItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   qDebug() << "mousePressed";
   emit mousePressed();

}

