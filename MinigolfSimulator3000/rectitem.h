#ifndef RECTITEM_H
#define RECTITEM_H
#include <QGraphicsRectItem>
#include <QDebug>

//! This class inherits from QGraphicsRectItem and makes QGraphicsRectItems clickable with mouse

class RectItem : public QObject, public QGraphicsRectItem
{
Q_OBJECT
public:
    //! Constructor
    RectItem();

signals:
   //! \brief RectItem emits a signal if it is pressed with the mouse
   void mousePressed();

protected:
   //! \brief This function gets called if a RectItem is pressed with the mouse
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // RECTITEM_H
