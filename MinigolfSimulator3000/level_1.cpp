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


}

//-----------------------------------

void Level_1::constructLevel()
{


    // Dateipfad als String
    QString bgroundimage = ":/Images/Images/Level_Test.png";
     waterimage = ":/Images/Images/wasser1.png";
     vogelimage = ":/Images/Images/v.png";
     vogelimage2 = ":/Images/Images/v2.png";
     vogelcounter = 0;
     wassercounter = 0;
     vogelaction = false;

    // Hintergrundbild
    scene->setBackgroundBrush(QImage(bgroundimage));

    QPen redpen;
    redpen.setWidth(2);
    redpen.setColor(Qt::red);

    // Begrenzungen hinzufügen
    BorderLine* line1 = new BorderLine(139.0,250.0,139.0,600.0,BorderLine::metal_material);
    scene->addItem(line1);

    BorderLine* line2 = new BorderLine(139.0,600.0,150.0,623.0,BorderLine::metal_material);
    scene->addItem(line2);

//  BorderLine* line3 = new BorderLine(213.0,662.0,295.0,596.0,BorderLine::metal_material);
//  scene->addItem(line3);

    BorderLine* line4 = new BorderLine(295.0,596.0,295.0,375.0,BorderLine::metal_material);
    scene->addItem(line4);

    BorderLine* line5 = new BorderLine(295.0,375.0,333.0,338.0,BorderLine::metal_material);
    scene->addItem(line5);

    BorderLine* line6 = new BorderLine(333.0,338.0,731.0,338.0,BorderLine::metal_material);
    scene->addItem(line6);

    BorderLine* line7 = new BorderLine(731.0,338.0,731.0,253.0,BorderLine::metal_material);
    scene->addItem(line7);

 // BorderLine* line8 = new BorderLine(731.0,253.0,294.0,253.0,BorderLine::metal_material);
 // scene->addItem(line8);

    BorderLine* line9 = new BorderLine(731.0,253.0,139.0,250.0,BorderLine::metal_material);
    scene->addItem(line9);

    BorderLine* line10 = new BorderLine(150.0,623.0,160,636,BorderLine::metal_material);
    scene->addItem(line10);

    BorderLine* line11 = new BorderLine(160,636,170,646,BorderLine::metal_material);
    scene->addItem(line11);

    BorderLine* line12 = new BorderLine(170,646,179,653,BorderLine::metal_material);
    scene->addItem(line12);

    BorderLine* line13 = new BorderLine(179,653,189,657,BorderLine::metal_material);
    scene->addItem(line13);

    BorderLine* line14 = new BorderLine(189,657,201,661,BorderLine::metal_material);
    scene->addItem(line14);

    BorderLine* line15 = new BorderLine(201,661,220,662,BorderLine::metal_material);
    scene->addItem(line15);

    BorderLine* line16 = new BorderLine(220,662,238,659,BorderLine::metal_material);
    scene->addItem(line16);

    BorderLine* line17 = new BorderLine(238,659,253,653,BorderLine::metal_material);
    scene->addItem(line17);

    BorderLine* line18 = new BorderLine(253,653,265,646,BorderLine::metal_material);

    scene->addItem(line18);

    BorderLine* line19 = new BorderLine(265,646,274,638,BorderLine::metal_material);
    scene->addItem(line19);

    BorderLine* line20 = new BorderLine(274,638,282,628,BorderLine::metal_material);
    scene->addItem(line20);

    BorderLine* line21 = new BorderLine(282,628,291,609,BorderLine::metal_material);
    scene->addItem(line21);

    BorderLine* line22 = new BorderLine(291,609,293,598,BorderLine::metal_material);
    scene->addItem(line22);

    BorderLine* line23 = new BorderLine(293,598,295,375,BorderLine::metal_material);
    scene->addItem(line23);


    line1->setVisible(false);
    line2->setVisible(false);
    line4->setVisible(false);
    line5->setVisible(false);
    line6->setVisible(false);
    line7->setVisible(false);
 // line8->setVisible(false);
    line9->setVisible(false);
    line10->setVisible(false);
    line11->setVisible(false);
    line12->setVisible(false);
    line13->setVisible(false);
    line14->setVisible(false);
    line15->setVisible(false);
    line16->setVisible(false);
    line17->setVisible(false);
    line18->setVisible(false);
    line19->setVisible(false);
    line20->setVisible(false);
    line21->setVisible(false);
    line22->setVisible(false);
    line23->setVisible(false);



    QPolygon water_polygon;
    water_polygon << QPoint(140,250) << QPoint(140,152) << QPoint(293,152) << QPoint(294,252);
    water = new GroundMaterial(GroundMaterial::water_material,water_polygon);
    water->setBrush(QImage(waterimage));
    scene->addItem(water);
    water->setVisible(true);
    water->setPen(Qt::NoPen);





    vogel2 = new QGraphicsPixmapItem;
    vogel2->setPixmap(vogelimage);
    vogel2->setVisible(true);
    vogel2->setPos(50,100);
    scene->addItem(vogel2);




}

//------------------------------------
void Level_1::updateLevel()
{

float rand = qrand();
int x,y;

rand /= RAND_MAX;
x = vogel2->x();
y = vogel2->y();

if (wassercounter < 6)
    {
    water->setBrush(QImage(":/Images/Images/wasser1.png"));

    }
if (wassercounter > 6 && wassercounter <= 12)
    {
    water->setBrush(QImage(":/Images/Images/wasser2.png"));

    }
if (wassercounter > 12 && wassercounter <= 16)
    {
    water->setBrush(QImage(":/Images/Images/wasser3.png"));

    }
if (wassercounter > 16 && wassercounter <= 20)
    {
    water->setBrush(QImage(":/Images/Images/wasser4.png"));

    }

if (rand < 0.001)
    {
    vogelaction = true;
    }


if(x < 1024  && vogelaction == true)
    {
    vogel2->setVisible(true);
    vogel2->setPos(x+10,y);
    }

else
    {
    vogel2->setPos(0,1000*rand);
    vogel2->setVisible(false);
    vogelaction = false;
    }

if(vogelcounter < 8)
    {
    vogel2->setPixmap(vogelimage);
    }

if(vogelcounter >= 8)
    {
    vogel2->setPixmap(vogelimage2);
    }

vogelcounter++;
wassercounter++;

if(vogelcounter >10)
    {
    vogelcounter = 0;
    }

if(wassercounter  >20)
    {
    wassercounter = 0;
    }

}
