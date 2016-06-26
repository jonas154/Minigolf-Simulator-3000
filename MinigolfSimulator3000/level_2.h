#ifndef LEVEL_2_H
#define LEVEL_2_H

#include "court.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QString>
#include <QGraphicsPixmapItem>

//! \brief Second level in the game
class Level_2 : public Court
{

public:

    //! \brief Constructor
    Level_2(QWidget* parent = 0);

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
    //! \brief Pointer for watermaterials to change later in updateLevel()
    GroundMaterial *water;

    //! \brief GraphicsRect Item Pointer to chance later in updateLevel()
    QGraphicsRectItem *vogel;

    //! \brief GraphicsRect Item Pointer to chance later in updateLevel()
    QGraphicsPixmapItem *vogel2;

    //! \brief Constructs the level
    void constructLevel();

    //! \brief Strings with path to files
    QString vogelimage;

    //! \brief Strings with path to files
    QString vogelimage2;

    //! \brief This bool is true when a bird should appear
    bool vogelaction;

    //! \brief Counter for BirdGraphics to handle picture changes
    int vogelcounter;

    //! \brief This bool is true if the mini menu is open
    bool menuActive;

protected:

    //! Catches ESC key presses in game to get to mini menu
    void keyPressEvent(QKeyEvent * e);


};

#endif // LEVEL_1_H
