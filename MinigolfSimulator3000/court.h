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


//! \brief Baseclass for the Levels, provides graphical interface for playing the game
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

    //! \brief Stops timers and calls this->hide()
    void stopAndHide();
    
    //! \brief Create Arrow including the ArrowStartItem
    void deleteArrow();



public slots:

    //! \brief Slot which updates the level graphics with each timestep
    virtual void updateLevel() = 0;

    //! \brief Slot which brings game into a minimenu
    virtual void menuLevel() = 0;

    //! \brief Slot which leaves the level and bring player back to main menu
    virtual void leaveLevel () = 0;

    //! \brief Set the new speed and angle of the ball and delete the Arrow
    void shot();

signals:
    //! \brief Signal which tells the game to destroy Level 1
    void destroyLevel();

    //! \brief Signal which tells the game to destroy Level 2
    void destroyLevel2();

    //! \brief Signal which tells the game to destroy Level 3
    void destroyLevel3();

    //! \brief Signal which tells the game to destroy Level 4
    void destroyLevel4();


protected:

    //! \brief Pointer to the UI
    Ui::Court* ui;

    //! \brief Pointer to the GraphicsScene
    QGraphicsScene* scene;

    //! \brief Timer for ball animation
    QTimer* timer;

    //! \brief Timer for water, lava, bird animations
    QTimer* graphicsTimer;

    //! \brief Pointer to RectItem in the Esc Menu
    RectItem* continueItem;

    //! \brief Pointer to RectItem in the Esc Menu
    RectItem* leaveItem;

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

    //! \brief Pointer to the Arrow start item
    ArrowStartItem* arrowStart;

    //! \brief Pointer to the Arrow
    Arrow* arrow;


//---------------------------------

private:


    QPointF startCoordinates;
    QPointF holeCoordinates;

    Ball* ball;    

};

#endif // COURT_H
