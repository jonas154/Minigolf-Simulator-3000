#ifndef LEVEL_4_H
#define LEVEL_4_H

#include "court.h"
#include "rectitem.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QString>
#include <QGraphicsPixmapItem>
#include <math.h>

class Level_4 :  public Court
{

public:

    //! \brief Constructor
    Level_4(QWidget* parent = 0);

    //! \brief Destructor
    virtual ~Level_4(){};

public slots:

    //! \brief This slot updates the level graphic pictures with each timestep
    void updateLevel() override;

    /*! \brief This slot brings the game into a mini menu where the game
    *   gets paused and the player can continue or go back to the main menu
    */
    void menuLevel()  override;

    //! \brief This slot brings the user back to the main menu
    void leaveLevel() override;


private:
    GroundMaterial *water_1;
    GroundMaterial *water_2;
    GroundMaterial *water_3;
    GroundMaterial *water_4;
    GroundMaterial *nonnewton;
    QGraphicsRectItem *vogel;
    QGraphicsPixmapItem *vogel2;
    //! \brief Constructs the level
    void constructLevel();
    QString waterimage;
    QString waterimage2;
    QString vogelimage;
    QString vogelimage2;
    QString nonnewtonimage;
    QString nonnewtonimage2;
    bool changeimage;
    bool vogelaction;
    int vogelCounter;
    int graphicsCounterFast;
    int graphicsCounterSlow;
    bool menuActive;

    QGraphicsRectItem *gate1;
    QGraphicsRectItem *gate2;
    BorderLine *gateline1;
    BorderLine *gateline2;


protected:

    //! Catches ESC key presses in game to get to mini menu
    void keyPressEvent(QKeyEvent * e);




};

#endif // LEVEL_4_H
