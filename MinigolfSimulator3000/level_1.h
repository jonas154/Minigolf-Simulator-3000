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


class Level_1 : public Court
{

public:

    //! \brief Constructor
    Level_1(QWidget* parent = 0);

    //! \brief Destructor
    virtual ~Level_1(){};

public slots:

    void updateLevel() override;
    void menuLevel()  override;
    void leaveLevel() override;

 signals:

    void destroyLevel();

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
    void keyPressEvent(QKeyEvent * e);




};

#endif // LEVEL_1_H
