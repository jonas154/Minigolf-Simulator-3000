/****************************************************************************
**
** The code for the arrowStartItem-class is inspired by the Qt 5.7 Diagram Scene Example
**
** arrowStartItem.h and arrowStartItem.cpp are modifications and extensions
** of parts of the DiagramItem-class found in the Diagram Scene Example
**
** BSD License Usage
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/


#ifndef ARROWSTARTITEM_H
#define ARROWSTARTITEM_H

#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include "ball.h"


//! The ArrowStartItem is moveable and used to adjust the Arrow.
/*! It inherits from a QGraphicsItem and also from QObject because a signal is emitted. */

class ArrowStartItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:

    //! Initializes its position 50 pixels beneath the current Ball position
    ArrowStartItem(Ball* _ball, bool _firstCreate = false);

    //! Overrides the boundingRect() function of QGraphicsItem
    QRectF boundingRect() const override;

    //! Paints the item in every time step
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    //! Overrides the mouseReleaseEvent() function of QGraphicsItem such that a signal is emitted
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    //! Overrides the itemChange() function of QGraphicsItem and limits the distance between the Ball and the ArrowStartItem
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

signals:

    //! Signal that the mouse is released from the ArrowStartItem
    void arrowStartItemReleased();

private:

    Ball* ball;
    bool firstCreate; // needed to implement a limitation of the distance between the ball and the ArrowStartItem
    bool changeReceived;

};

#endif // ARROWSTARTITEM_H
