#ifndef LEVEL_3_H
#define LEVEL_3_H

#include "court.h"
#include "rectitem.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QString>
#include <QGraphicsPixmapItem>


class Level_3 :  public Court
{

public:

    //! \brief Constructor
    Level_3(QWidget* parent = 0);

    //! \brief Destructor
    virtual ~Level_3(){};

public slots:

    void updateLevel() override;
    void menuLevel()  override;
    void leaveLevel() override;
    void testslot();




private:
    GroundMaterial *water;
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
    int vogelcounter;
    int wassercounter;
    bool menuActive;


protected:
    void keyPressEvent(QKeyEvent * e);




};

#endif // LEVEL_3_H
