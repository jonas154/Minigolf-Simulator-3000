#include "rectitem.h"
#include <QDebug>
#include "game.h"


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

