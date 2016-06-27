#include "rectitem.h"




RectItem::RectItem()
{
}

//------------------------------------------

void RectItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   //Funktion emittiert das Signal mousePressed
   qDebug() << "mousePressed";
   emit mousePressed();
}

