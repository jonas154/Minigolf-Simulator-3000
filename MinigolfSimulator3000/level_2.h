#ifndef LEVEL_2_H
#define LEVEL_2_H

#include "court.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QString>
#include <QGraphicsPixmapItem>


class Level_2 : public Court
{

public:

    //! \brief Constructor
    Level_2(QWidget* parent = 0);

    //! \brief Destructor
    virtual ~Level_2(){};

public slots:
    //! \brief This slot updates the level graphic pictures with each timestep
    void updateLevel() override;

    /*! \brief This slot brings the game into a mini menu where the game
    *   gets paused and the player can continue or go back to the main menu
    */
    void menuLevel() override;

    //! \brief This slot brings the user back to the main menu
    void leaveLevel() override;


private:
    GroundMaterial *water;
    QGraphicsRectItem *vogel;
    QGraphicsPixmapItem *vogel2;
    //! \brief Constructs the level
    void constructLevel();
    QString waterimage;
    QString waterimage2;
    QString vogelimage;
    QString vogelimage2;
    bool changeimage;
    bool vogelaction;
    int vogelcounter;
    int wassercounter;
    bool menuActive;

protected:

    //! Catches ESC key presses in game to get to mini menu
    void keyPressEvent(QKeyEvent * e);


};

#endif // LEVEL_1_H
