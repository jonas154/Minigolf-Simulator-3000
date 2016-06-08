#include "level_1.h"


Level_1::Level_1(QWidget *parent)
    :
    Court(parent)
{

    this->setStartCoordinates(218.0, 600.0);
    this->constructLevel();
    this->createBall();

    this->createArrow();
    connect(arrowStart,SIGNAL(arrowStartItemReleased()),this,SLOT(shot()));

}

//-----------------------------------

void Level_1::constructLevel()
{
    // Dateipfad als String
    QString bgroundimage = ":/Images/Images/Level_1.png";
    waterimage = ":/Images/Images/wasser1.png";
    vogelimage = ":/Images/Images/v.png";
    vogelimage2 = ":/Images/Images/v2.png";
    vogelcounter = 0;
    wassercounter = 0;
    vogelaction = false;
    std::vector<BorderLine*> lineVec;

    // Hintergrundbild
    scene->setBackgroundBrush(QImage(bgroundimage));

    // Wasserbilder
    QPolygon water_polygon;
    water_polygon << QPoint(140,250) << QPoint(140,152) << QPoint(293,152) << QPoint(294,252);
    water = new GroundMaterial(GroundMaterial::water_material,water_polygon);
    water->setBrush(QImage(waterimage));
    scene->addItem(water);
    water->setVisible(true);
    water->setPen(Qt::NoPen);



    // QPen setzen
    QPen linepen;
    linepen.setWidth(2);
    linepen.setColor(QColor(0,0,0,0));
    linepen.setJoinStyle(Qt::RoundJoin);
    linepen.setCapStyle(Qt::RoundCap);


    //grass material  [zum debuggen QPen(Qt::red) anstatt linepen verwenden]
    QPolygonF grassPolygon;
    grassPolygon << QPoint(126,664) << QPoint(310,665) <<QPoint(302,382) <<QPoint(343,345) <<QPoint(740,343) <<QPoint(739,245)
    <<QPoint(292,253) <<QPoint(132,253);
    GroundMaterial* grass = new GroundMaterial(GroundMaterial::grass_material, grassPolygon);
    grass->setPen(linepen);
    scene->addItem(grass);


    //Begrenzungslinien zur Liste hinzufügen
    lineVec.push_back( new BorderLine(294.0,594.0,294.0,375.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(294.0,375.0,335.0,337.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(335.0,337.0,730.0,337.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(730.0,337.0,730.0,253.0,BorderLine::metal_material));

    lineVec.push_back( new BorderLine(294.0,253.0,294.0,151.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(730.0,253.0,294.0,253.0,BorderLine::metal_material));

    lineVec.push_back( new BorderLine(294.0,151.0,140.0,151.0,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(140.0,151.0,140.0,594.0,BorderLine::metal_material));


    // Kurve Zeichnen
    BorderLineCurveDrawer::draw(140.0, 594.0, 294.0, 594.0, 77.5, 6.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::metal_material, scene, linepen);


    //Linien unsichtbar machen + Linien zur Scene hinzufügen
    for (int i=0;i< lineVec.size();i++)
    {
        lineVec[i]->setPen(linepen);
        scene->addItem(lineVec[i]);
    }

    // Vogelbilder
    vogel2 = new QGraphicsPixmapItem;
    vogel2->setPixmap(vogelimage);
    vogel2->setVisible(true);
    vogel2->setPos(50,100);
    scene->addItem(vogel2);

    //erst connecten, wenn Wasser und Vögel schon initialisiert sind!
    connect(graphicsTimer, SIGNAL(timeout()),this, SLOT(updateLevel()));

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
