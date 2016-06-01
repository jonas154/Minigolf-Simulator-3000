#ifndef LEVEL_1_H
#define LEVEL_1_H

#include "court.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsItem>
#include <QString>


class Level_1 : public Court
{

public:

    //! \brief Constructor
    Level_1(QWidget* parent = 0);

    //! \brief Destructor
    virtual ~Level_1(){};

public slots:

    void updateLevel() override;



private:
    GroundMaterial *water;
    //! \brief Constructs the level
    void constructLevel();
    QString waterimage;
    QString waterimage2;

};

#endif // LEVEL_1_H
