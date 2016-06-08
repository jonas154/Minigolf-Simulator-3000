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

    void updateLevel() override;



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




};

#endif // LEVEL_1_H