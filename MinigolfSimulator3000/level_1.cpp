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
    connect(arrowStart,SIGNAL(arrowStartItemReleased()),this,SLOT(shot()));

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
    std::vector<BorderLine*> lineVec;

    // Hintergrundbild
    scene->setBackgroundBrush(QImage(bgroundimage));

   // QPen setzen
    QPen linepen;
    linepen.setWidth(3);
    linepen.setColor(QColor(0,0,0,0));

    //Begrenzungslinien zur Liste hinzufügen
    lineVec.push_back( new BorderLine(139.0,250.0,139.0,600.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(139.0,600.0,150.0,623.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(295.0,596.0,295.0,375.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(295.0,375.0,333.0,338.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(333.0,338.0,731.0,338.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(731.0,338.0,731.0,253.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(731.0,253.0,139.0,250.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(150.0,623.0,160,636,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(160,636,170,646,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(170,646,179,653,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(179,653,189,657,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(189,657,201,661,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(201,661,220,662,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(220,662,238,659,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(238,659,253,653,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(253,653,265,646,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(265,646,274,638,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(274,638,282,628,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(282,628,291,609,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(291,609,293,598,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(293,598,295,375,BorderLine::metal_material));

    //Linien unsichtbar machen + Linien zur Scene hinzufügen
    for (int i=0;i< lineVec.size();i++)
        {
        lineVec[i]->setVisible(true);
        lineVec[i]->setPen(linepen);
        scene->addItem(lineVec[i]);
        }

    // Wasserbilder
    QPolygon water_polygon;
    water_polygon << QPoint(140,250) << QPoint(140,152) << QPoint(293,152) << QPoint(294,252);
    water = new GroundMaterial(GroundMaterial::water_material,water_polygon);
    water->setBrush(QImage(waterimage));
    scene->addItem(water);
    water->setVisible(true);
    water->setPen(Qt::NoPen);

    // Vogelbilder
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
