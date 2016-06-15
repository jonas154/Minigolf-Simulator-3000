#include "level_2.h"


Level_2::Level_2(QWidget *parent)
    :
    Court(parent)
{

    this->setStartCoordinates(195.0, 590.0);
    this->constructLevel();
    this->createBall();

    this->createArrow(true);


}

//-----------------------------------

void Level_2::constructLevel()
{
    // Dateipfad als String
    QString bgroundimage = ":/Images/Images/Level_2.png";
    waterimage = ":/Images/Images/wasser1.png";
    vogelimage = ":/Images/Images/v.png";
    vogelimage2 = ":/Images/Images/v2.png";
    vogelcounter = 0;
    wassercounter = 0;
    vogelaction = false;
    menuActive = false;
    std::vector<BorderLine*> lineVec;

    // Hintergrundbild
    scene->setBackgroundBrush(QImage(bgroundimage));


    // Wasserbilder

    QPolygon water_polygon;
    water_polygon << QPoint(140,250) << QPoint(140,152) << QPoint(293,152) << QPoint(294,252);
    water = new GroundMaterial(GroundMaterial::water_material,water_polygon);
    water->setBrush(QImage(waterimage));
    //scene->addItem(water);
    water->setVisible(true);
    water->setPen(Qt::NoPen);



    // QPen setzen
    QPen linepen;
    linepen.setWidth(2);
    linepen.setColor(QColor(0,0,0,0));
    linepen.setJoinStyle(Qt::RoundJoin);
    linepen.setCapStyle(Qt::RoundCap);


    //grass material
    QPolygonF grassPolygon;
    grassPolygon << QPointF(140,638) << QPointF(134,154) << QPointF(400,154) << QPointF(410,576) << QPointF(504,577) << QPointF(505,269)
                 << QPointF(747,269) << QPointF(752,377) << QPointF(595,375) << QPointF(601,506) << QPointF(729,495) << QPointF(718,658);
    GroundMaterial* grass = new GroundMaterial(GroundMaterial::grass_material, grassPolygon);
    grass->setPen(linepen);
    scene->addItem(grass);


    continueItem->setRect(368,266,289,80);
    continueItem->setPen(linepen);
    continueItem->setVisible(false);
    scene->addItem(continueItem);

    leaveItem->setRect(368,362,289,80);
    leaveItem->setPen(linepen);
    leaveItem->setVisible(false);
    scene->addItem(leaveItem);

    //Begrenzungslinien zur Liste hinzufügen
    lineVec.push_back( new BorderLine(143,590,143,269,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(246,592,246,286,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(275,288,275,378,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(275,378,321,437,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(321,526,277,564,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(277,564,275,607,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(315,646,666,646,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(665,513,583,513,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(583,513,583,362,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(583,362,734,362,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(734,362,734,279,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(734,279,516,279,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(516,279,516,279,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(516,570,647,570,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(647,592,399,592,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(399,592,399,566,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(399,566,364,529,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(364,529,364,435,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(364,435,399,379,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(399,379,398,268,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(399,379,398,268,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(321,438,321,526,BorderLine::metal_material));
    lineVec.push_back( new BorderLine(516,570,516,279,BorderLine::metal_material));

    // Kurve Zeichnen
    BorderLineCurveDrawer::draw(246,286, 275,288, 15, 6.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::metal_material, scene, linepen);

    BorderLineCurveDrawer::draw(143,269, 398,270, 130, 6.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::metal_material, scene, linepen);

    BorderLineCurveDrawer::draw(143,591, 246,590, 52, 6.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::metal_material, scene, linepen);

    BorderLineCurveDrawer::draw(315,646,275,607, 50, 6.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::metal_material, scene, linepen);


    BorderLineCurveDrawer::draw(660,645,669,513, 67, 6.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::metal_material, scene, linepen);

    BorderLineCurveDrawer::draw(648,570,647,592,12,6.0,
                                BorderLineCurveDrawer::left, false,
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
    connect(continueItem,SIGNAL(mousePressed()),this,SLOT(menuLevel()));
    connect(leaveItem,SIGNAL(mousePressed()),this,SLOT(leaveLevel()));

}

void Level_2::menuLevel()
{   if (menuActive == false)
    {
    scene->setForegroundBrush(QImage(QString(":/Images/Images/Level_2_ESC_Menu.png")));
    continueItem->setVisible(true);
    leaveItem->setVisible(true);
    menuActive = true;
    timer->stop();
    graphicsTimer->stop();
    }
else
    {
    scene->setForegroundBrush(Qt::NoBrush);
    continueItem->setVisible(false);
    leaveItem->setVisible(false);
    menuActive = false;
    timer->start();
    graphicsTimer->start();
    }
   // qDebug() << "menuLevel erreicht";
}
void Level_2::leaveLevel()
{
    emit destroyLevel2();
    qDebug() << "destroyLevel2 emittiert";
}
void Level_2::keyPressEvent(QKeyEvent *event) {

   if (event->key() == Qt::Key_Escape)
   {
     menuLevel();
   }
}

//------------------------------------
void Level_2::updateLevel()
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
