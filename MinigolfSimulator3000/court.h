#ifndef COURT_H
#define COURT_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "borderline.h"
#include "groundmaterial.h"
#include "ball.h"
#include "QWidget"

namespace Ui {
class Court;
}

class Court : public QDialog
{
    Q_OBJECT

public:

    //! \brief Constructor
    explicit Court(QWidget *parent = 0);

    //! \brief Destructor
    ~Court();

    //! \brief Returns pointer to the current scene
    QGraphicsScene* getScene();

    //! \brief Returns the start coordinates of the current level
    QPointF getStartCoordinates();

    //! \brief Returns pointer to the active ball
    Ball* getBall();

//---------------------------------

protected:

    Ui::Court* ui;

    QGraphicsScene* scene;

    //! \brief Set the start coordinates of the level
    void setStartCoordinates(const QPointF startPoint);

    //! \brief Set the start coordinates of the level, overloaded function
    void setStartCoordinates(const qreal x, const qreal y);

    //! \brief Create ball and add to scene at start coordinates
    void createBall();

//---------------------------------

private:

    //Ui::Court *ui;

    QTimer* timer;

    QPointF startCoordinates;

    Ball* ball;

};

#endif // COURT_H
