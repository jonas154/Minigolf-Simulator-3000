#include "level_1.h"


Level_1::Level_1()
{
    this->setStartCoordinates(250.0, 300.0);
    this->createBall();
}

//-----------------------------------

void Level_1::constructLevel()
{
    QPen redpen;
    redpen.setWidth(2);
    redpen.setColor(Qt::red);

    BorderLine* line1 = new BorderLine(200.0, 200.0, 500.0, 200.0, BorderLine::metal_material);
    line1->setPen(redpen);
    scene->addItem(line1);

    BorderLine* line2 = new BorderLine(500.0, 200.0, 500.0, 500.0, BorderLine::metal_material);
    line2->setPen(redpen);
    scene->addItem(line2);

    BorderLine* line3 = new BorderLine(500.0, 500.0, 200.0, 500.0, BorderLine::metal_material);
    line3->setPen(redpen);
    scene->addItem(line3);

    BorderLine* line4 = new BorderLine(200.0, 500.0, 200.0, 200.0, BorderLine::metal_material);
    line4->setPen(redpen);
    scene->addItem(line4);

    BorderLine* line5 = new BorderLine(210.0, 210.0, 290.0, 290.0, BorderLine::metal_material);
    line5->setPen(redpen);
    scene->addItem(line5);

}

//------------------------------------

