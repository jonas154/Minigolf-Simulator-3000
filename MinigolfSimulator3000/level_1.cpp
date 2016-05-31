#include "level_1.h"


Level_1::Level_1(QWidget *parent)
    :
    Court(parent)
{
    this->setStartCoordinates(250.0, 300.0);
    this->constructLevel();
    this->createBall();
    this->createArrow();

}

//-----------------------------------

void Level_1::constructLevel()
{
    // Dateipfad als String
    QString bgroundimage = ":/Images/Images/Level_Test.png";

    // Hintergrundbild
    scene->setBackgroundBrush(QImage(bgroundimage));

    QPen redpen;
    redpen.setWidth(2);
    redpen.setColor(Qt::red);

    // Begrenzungen hinzufügen
    BorderLine* line1 = new BorderLine(139.0,255.0,139.0,600.0,BorderLine::metal_material);
    scene->addItem(line1);

    BorderLine* line2 = new BorderLine(139.0,600.0,213.0,662.0,BorderLine::metal_material);
    scene->addItem(line2);

    BorderLine* line3 = new BorderLine(213.0,662.0,295.0,596.0,BorderLine::metal_material);
    scene->addItem(line3);

    BorderLine* line4 = new BorderLine(295.0,596.0,295.0,375.0,BorderLine::metal_material);
    scene->addItem(line4);


    BorderLine* line5 = new BorderLine(295.0,375.0,333.0,338.0,BorderLine::metal_material);
    scene->addItem(line5);


    BorderLine* line6 = new BorderLine(333.0,338.0,731.0,338.0,BorderLine::metal_material);
    scene->addItem(line6);


    BorderLine* line7 = new BorderLine(731.0,338.0,731.0,253.0,BorderLine::metal_material);
    scene->addItem(line7);


    BorderLine* line8 = new BorderLine(731.0,253.0,294.0,253.0,BorderLine::metal_material);
    scene->addItem(line8);

    BorderLine* line9 = new BorderLine(731.0,253.0,139.0,255.0,BorderLine::metal_material);
    scene->addItem(line9);



}

//------------------------------------

