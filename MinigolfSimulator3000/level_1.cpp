#include "level_1.h"


Level_1::Level_1(QWidget *parent)
    :
    Court(parent)
{
    connect(timer, SIGNAL(timeout()),this, SLOT(updateLevel()));
    this->setStartCoordinates(250.0, 300.0);
    this->constructLevel();
    this->createBall();

    this->createArrow();
    connect(arrowStart, SIGNAL(arrowStartItemReleased()), this, SLOT(shot()));





}

//-----------------------------------

void Level_1::constructLevel()
{


    // Dateipfad als String
    QString bgroundimage = ":/Images/Images/Level_Test.png";
     waterimage = ":/Images/Images/wasser.png";
     waterimage2 = ":/Images/Images/wasser2.png";
     vogelimage = ":/Images/Images/v.png";
     vogelimage2 = ":/Images/Images/v2.png";

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


    QPolygon water_polygon;
    water_polygon << QPoint(140,250) << QPoint(140,152) << QPoint(293,152) << QPoint(294,252);
    water = new GroundMaterial(GroundMaterial::water_material,water_polygon);
    water->setBrush(QImage(waterimage));
    scene->addItem(water);
    water->setVisible(true);



    vogel2 = new QGraphicsPixmapItem;
    vogel2->setPixmap(vogelimage);
    vogel2->setVisible(true);
    vogel2->setPos(50,100);
    scene->addItem(vogel2);

    vogelcounter = 0;


}

//------------------------------------
void Level_1::updateLevel()
{
float rand = qrand();

rand /= RAND_MAX;

if (changeimage)
{
water->setBrush(QImage(waterimage2));
changeimage = false;
}
else
{
water->setBrush(QImage(waterimage));
changeimage = true;
}
//qDebug() << "test";
int x,y;
if (rand < 0.001)
{
vogelaction = true;
}
x = vogel2->x();
y = vogel2->y();
if(x < 1024  && vogelaction == true)
{
vogel2->setVisible(true);
vogel2->setPos(x+10,y);
}
else
{vogel2->setPos(0,100);
 vogel2->setVisible(false);
 vogelaction = false;
}

if(vogelcounter < 8)
{
vogelcounter++;
vogel2->setPixmap(vogelimage);
}

if(vogelcounter >= 8)
{
vogelcounter++;
vogel2->setPixmap(vogelimage2);
}
if(vogelcounter >10)
{
vogelcounter = 0;
}
}
