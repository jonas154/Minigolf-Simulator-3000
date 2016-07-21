/****************************************************************************
**
** The code for the arrow-class is inspired by the Qt 5.7 Diagram Scene Example
**
** arrow.h and arrow.cpp are modifications and extensions
** of the corresponding files found in the Diagram Scene Example
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

#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>
#include <QPen>
#include <QPainter>
#include <arrowstartitem.h>
#include <ball.h>
#include <qmath.h>


//! Draws an arrow between an ArrowStartItem and a Ball
/*! The arrow is used to compute the initial speed and initial angle of the ball for a shot. */

class Arrow : public QGraphicsLineItem
{
public:

    //! Initializes the start item and the end item and sets a QPen with red color
    Arrow(ArrowStartItem *startItem, Ball *endItem, QGraphicsItem *parent = 0);

    //! Reimplements the boundingRect()-function of QGraphicsLineItem
    QRectF boundingRect() const Q_DECL_OVERRIDE;

    //! Returns a QPainterPath including the arrow line and the arrow head
    QPainterPath shape() const Q_DECL_OVERRIDE;

    //! Pointer to the start item of the arrow
    ArrowStartItem *startItem() const { return myStartItem; }

    //! Pointer to the end item of the Arrow which is a Ball
    Ball *endItem() const { return myEndItem; }

    //! Returns the current angle of the Arrow
    qreal getAngle();

    //! Returns a speed value that is dependent on the length of the Arrow
    qreal getSpeed();

    //! Updates the position of the Arrow
    void updatePosition();

protected:

    //! Paints the arrow line and the arrow head in the QMainWindow
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) Q_DECL_OVERRIDE;

private:

    ArrowStartItem *myStartItem;
    Ball *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;
};

#endif // ARROW_H
