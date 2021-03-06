#ifndef LEVEL_1_H
#define LEVEL_1_H

#include "court.h"
#include "rectitem.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QString>
#include <QGraphicsPixmapItem>

//! \brief First level in the game
class Level_1 :  public Court
{

public:

    //! \brief Constructor
    Level_1(QWidget* parent = 0);

public slots:

    //! \brief This slot updates the level graphic pictures with each timestep
    void updateLevel() override;

    //! \brief This slot brings the game into a mini menu where the game gets paused and the player can continue or go back to the main menu
    void menuLevel() override;

    //! \brief This slot brings the user back to the main menu
    void leaveLevel() override;

private:

    //! \brief Pointer for watermaterials to change later in updateLevel()
    GroundMaterial *water;

    //! \brief GraphicsRect Item Pointer to chance later in updateLevel()
    QGraphicsPixmapItem *vogel;

    //! \brief Constructs the level
    void constructLevel();

    //! \brief Strings with path to files
    QString waterimage;

    //! \brief Strings with path to files
    QString waterimage2;

    //! \brief Strings with path to files
    QString vogelimage;

    //! \brief Strings with path to files
    QString vogelimage2;

    //! \brief This bool is true when a bird should appear
    bool vogelaction;

    //! \brief Counter for BirdGraphics to handle picture changes
    //! max 10
    int vogelcounter;

    //! \brief FAST Counter for Graphics to handle picture changes
    //! max 20
    int graphicsCounterFast;

    //! \brief This bool is true if the mini menu is open
    bool menuActive;

    //! Catches ESC key presses in game to get to mini menu
    void keyPressEvent(QKeyEvent * e) override;

};

#endif // LEVEL_1_H
