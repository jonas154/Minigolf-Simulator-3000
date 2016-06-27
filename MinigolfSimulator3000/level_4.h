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

//! \brief Fourth level in the game
class Level_4 :  public Court
{

public:

    //! \brief Constructor
    Level_4(QWidget* parent = 0);

public slots:

    //! \brief This slot updates the level graphic pictures with each timestep
    void updateLevel() override;

    //! \brief This slot brings the game into a mini menu where the game gets paused and the player can continue or go back to the main menu
    void menuLevel()  override;

    //! \brief This slot brings the user back to the main menu
    void leaveLevel() override;


private:

    //! \brief Pointer for watermaterials to change later in updateLevel()
    GroundMaterial *water_1;

    //! \brief Pointer for watermaterials to change later in updateLevel()
    GroundMaterial *water_2;

    //! \brief Pointer for watermaterials to change later in updateLevel()
    GroundMaterial *water_3;

    //! \brief Pointer for watermaterials to change later in updateLevel()
    GroundMaterial *water_4;

    //! \brief Pointer for nonnewton to change later in updateLevel()
    GroundMaterial *nonnewton;

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

    //! \brief Strings with path to files
    QString nonnewtonimage;

    //! \brief Strings with path to files
    QString nonnewtonimage2;

    //! \brief This bool is true when a bird should appear
    bool vogelaction;

    //! \brief Counter for BirdGraphics to handle picture changes
    //! max 10
    int vogelCounter;

    //! \brief FAST Counter for Graphics to handle picture changes
    //! max 20
    int graphicsCounterFast;

    //! \brief SLOW Counter for Graphics to handle picture changes
    //! max 40
    int graphicsCounterSlow;

    //! \brief This bool is true if the mini menu is open
    bool menuActive;

    //! \brief RectItems pointer for Gates to chance in updateLevel()
    QGraphicsRectItem *gate1;

    //! \brief RectItems pointer for Gates to chance in updateLevel()
    QGraphicsRectItem *gate2;

    //! \brief Borderline gate1 pointer to chance in updateLevel()
    BorderLine *gateline1;

    //! \brief Borderline gate2 pointer to chance in updateLevel()
    BorderLine *gateline2;

    //! Catches ESC key presses in game to get to mini menu
    void keyPressEvent(QKeyEvent * e) override;

};

#endif // LEVEL_4_H
