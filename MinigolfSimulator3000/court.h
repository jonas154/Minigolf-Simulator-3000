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
#include "rectitem.h"


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
    virtual ~Court();

    //! \brief Returns pointer to the current scene
    QGraphicsScene* getScene();

    //! \brief Returns the start coordinates of the current level
    QPointF getStartCoordinates();

    //! \brief Returns the hole coordinates of the current level
    QPointF getHoleCoordinates();

    //! \brief Returns pointer to the active ball
    Ball* getBall();

    //! \brief Create Arrow including the ArrowStartItem
    void createArrow(bool firstCreate = false);

    void stopAndHide();
    
    //! \brief Create Arrow including the ArrowStartItem
    void deleteArrow();



public slots:

    //! \brief Slot which updates the level graphics
    //! with each timestep
    virtual void updateLevel() = 0;

    //! \brief Slot which brings game into a minimenu
    virtual void menuLevel() = 0;

    //! \brief Slot which leaves the level and bring
    //! player back to main menu
    virtual void leaveLevel () = 0;

    void shot();

signals:
    //! \brief Signal which tells the game to destroy
    //! Level 1
    void destroyLevel();

    //! \brief Signal which tells the game to destroy
    //! Level 2
    void destroyLevel2();

    //! \brief Signal which tells the game to destroy
    //! Level 3
    void destroyLevel3();

    //! \brief Signal which tells the game to destroy
    //! Level 4
    void destroyLevel4();


protected:

    Ui::Court* ui;
    QGraphicsScene* scene;
    QTimer* timer;
    QTimer* graphicsTimer;

    //! \brief RectItem Pointer to make RectItems available for
    //! funktions like levelLevel
    RectItem * continueItem;

    //! \brief RectItem Pointer to make RectItems available for
    //! funktions like levelLevel
    RectItem * leaveItem;


    //! \brief Set the start coordinates of the level
    void setStartCoordinates(const QPointF startPoint);

    //! \brief Set the start coordinates of the level, overloaded function
    void setStartCoordinates(const qreal x, const qreal y);

    //! \brief Set the hole coordinates of the level
    void setHoleCoordinates(const QPointF startPoint);

    //! \brief Set the hole coordinates of the level, overloaded function
    void setHoleCoordinates(const qreal x, const qreal y);

    //! \brief Create ball and add to scene at start coordinates
    void createBall();

    ArrowStartItem* arrowStart;
    Arrow* arrow;


//---------------------------------

private:


    QPointF startCoordinates;
    QPointF holeCoordinates;

    Ball* ball;    

};

#endif // COURT_H
