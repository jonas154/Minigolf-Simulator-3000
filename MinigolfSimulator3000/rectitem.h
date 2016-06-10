#ifndef RECTITEM_H
#define RECTITEM_H
#include <QGraphicsRectItem>

class RectItem : public QObject, public QGraphicsRectItem
{
Q_OBJECT
public:
    RectItem();

signals:
   void mousePressed();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // RECTITEM_H
