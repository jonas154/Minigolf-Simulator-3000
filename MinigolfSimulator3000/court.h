#ifndef COURT_H
#define COURT_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include "ui_court.h"
#include "borderline.h"
#include "groundmaterial.h"
#include "ball.h"
#include "arrow.h"
#include "arrowstartitem.h"
#include "borderlinecurvedrawer.h"
#include <vector>

#include <QDebug>

namespace Ui {
class Court;
}


class Court : public QWidget
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

    //! \brief Create Arrow including the ArrowStartItem
    void createArrow();

public slots:

    virtual void updateLevel() = 0;

    void shot();

//---------------------------------

protected:

    Ui::Court* ui;

    QGraphicsScene* scene;

    QTimer* timer;
    QTimer* graphicsTimer;

    //! \brief Set the start coordinates of the level
    void setStartCoordinates(const QPointF startPoint);

    //! \brief Set the start coordinates of the level, overloaded function
    void setStartCoordinates(const qreal x, const qreal y);

    //! \brief Create ball and add to scene at start coordinates
    void createBall();

    //! \brief Create Arrow including the ArrowStartItem
    void deleteArrow();


//---------------------------------

private:


    QPointF startCoordinates;

    Ball* ball;


protected:
    ArrowStartItem* arrowStart;
    Arrow* arrow;

};

#endif // COURT_H
