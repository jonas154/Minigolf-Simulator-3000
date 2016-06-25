#include "level_4.h"
#include "rectitem.h"
#include "startwindow.h"


Level_4::Level_4(QWidget *parent)
    :
    Court(parent)
{
    //Startkoordinaten können zum debuggen versetzt werden "this->setStartCoordinates(374,495);"
    //um newton Fluid zu testen
    this->setStartCoordinates(240.0, 570.0);

    // Lochkoordinaten setzen
    this->setHoleCoordinates(631.0,280.0);

    this->constructLevel();
    this->createBall();
    this->createArrow(true);

}

//------------------------------------

void Level_4::constructLevel()
{
    // Pfade der Bilder in Strings Speichern
    QString bgroundimage = ":/Images/Images/Level_4.png";
    waterimage = ":/Images/Images/wasser3_1.png";
    vogelimage = ":/Images/Images/v.png";
    vogelimage2 = ":/Images/Images/v2.png";

    //Couter für Update Level initialisiern
    vogelCounter = 0;
    graphicsCounterFast = 0;
    graphicsCounterSlow = 0;
    vogelaction = false;

    //Mini Menü mit false initialisieren
    menuActive = false;

    //Vector für Verbindungslinien erstellen
    std::vector<BorderLine*> lineVec;

    // Hintergrundbild der scene setzen
    scene->setBackgroundBrush(QImage(bgroundimage));

    /* Unsichtbaren QPen für linien erstellen
     * [zum debuggen QPen(Qt::red) anstatt linepen verwenden]
     */
    QPen linepen;
    linepen.setWidth(2);
    linepen.setColor(QColor(0,0,0,0));
    linepen.setJoinStyle(Qt::RoundJoin);
    linepen.setCapStyle(Qt::RoundCap);

    //WASSERPOLYGON 1-----------------------------------------
    // Wasserbilder 1 Polygon erstellen
    QPolygon water_polygon_1;
    water_polygon_1 << QPoint(180,256) << QPoint(322,256) << QPoint(322,323) << QPoint(180,323);
    water_1 = new GroundMaterial(GroundMaterial::water_material,water_polygon_1);

    // Bilder einbinden und zu Scene hinzufügen
    water_1->setBrush(QImage(waterimage));
    scene->addItem(water_1);
    water_1->setVisible(true);
    water_1->setPen(Qt::NoPen);
    //--------------------------------------------------------

    //WASSERPOLYGON 2-----------------------------------------
    // Wasserbilder 2 Polygon erstellen
    QPolygon water_polygon_2;
    water_polygon_2 << QPoint(334,256) << QPoint(422,256) << QPoint(422,323) << QPoint(334,323);
    water_2 = new GroundMaterial(GroundMaterial::water_material,water_polygon_2);

    // Bilder einbinden und zu Scene hinzufügen
    water_2->setBrush(QImage(waterimage));
    scene->addItem(water_2);
    water_2->setVisible(true);
    water_2->setPen(Qt::NoPen);
    //--------------------------------------------------------

    //WASSERPOLYGON 3-----------------------------------------
    // Wasserbilder 3 Polygon erstellen
    QPolygon water_polygon_3;
    water_polygon_3 << QPoint(595,374) << QPoint(622,374) << QPoint(622,443) << QPoint(595,443);
    water_3 = new GroundMaterial(GroundMaterial::water_material,water_polygon_3);

    // Bilder einbinden und zu Scene hinzufügen
    water_3->setBrush(QImage(waterimage));
    scene->addItem(water_3);
    water_3->setVisible(true);
    water_3->setPen(Qt::NoPen);
    //--------------------------------------------------------

    //WASSERPOLYGON 4-----------------------------------------
    // Wasserbilder 4 Polygon erstellen
    QPolygon water_polygon_4;
    water_polygon_4 << QPoint(640,374) << QPoint(640,443) << QPoint(667,443) << QPoint(667,374);
    water_4 = new GroundMaterial(GroundMaterial::water_material,water_polygon_4);

    // Bilder einbinden und zu Scene hinzufügen
    water_4->setBrush(QImage(waterimage));
    scene->addItem(water_4);
    water_4->setVisible(true);
    water_4->setPen(Qt::NoPen);
    //--------------------------------------------------------

    //NONNEWTONFLUID 1-----------------------------------------
    //Nonnewtonsches Fluid erstellen und zur scene hinzufügen
    QPolygon nonnewton_polygon;
    nonnewton_polygon << QPoint(397,462) << QPoint(472,462) << QPoint(472,498) << QPoint(472,521)
                      << QPoint(397,521);
    nonnewton = new GroundMaterial(GroundMaterial::nonNewtonian_material,nonnewton_polygon);

    nonnewton->setBrush(QImage(nonnewtonimage));
    scene->addItem(nonnewton);
    nonnewton->setVisible(true);
    nonnewton->setPen(linepen);
    //--------------------------------------------------------

    //GATE 1&2------------------------------------------------
    // Gate 1 und 2 erstellen und zur scene hinzufügen
    gate1 = new QGraphicsRectItem();
    gate2 = new QGraphicsRectItem();
    gate1->setRect(439,522,4,40);
    gate1->setPen(linepen);
    gate1->setBrush(QImage(":/Images/Images/gatter.png"));
    scene->addItem(gate1);
    gate2->setRect(439,422,4,40);
    gate2->setPen(linepen);
    gate2->setBrush(QImage(":/Images/Images/gatter.png"));
    scene->addItem(gate2);

    //Gate 1 und 2 Collisionslinien erstellen (werden in update Level benötigt)
    gateline1 = new BorderLine(439,461,439,522,BorderLine::wood_material);
    gateline2 = new BorderLine(442,461,442,522,BorderLine::wood_material);
    gateline1->setPen(linepen);
    gateline2->setPen(linepen);

    //zur scene hinzufügen
    scene->addItem(gateline1);
    scene->addItem(gateline2);
    //--------------------------------------------------------


    //GRASS 1-------------------------------------------------
    //Grass 1 erstellen und zur scene hinzufügen
    QPolygonF grassPolygon1;
    grassPolygon1 << QPoint(161,641) << QPoint(176,334) << QPoint(429,334) << QPoint(432,455)
                     << QPoint(387,459) << QPoint(387,526) << QPoint(280,638);
    GroundMaterial* grass1 = new GroundMaterial(GroundMaterial::grass_material, grassPolygon1);
    grass1->setPen(linepen);
    scene->addItem(grass1);
    //--------------------------------------------------------

    //GRASS 2-------------------------------------------------
    //Grass 2 erstellen und zur scene hinzufügen
    QPolygonF grassPolygon2;
    grassPolygon2 << QPoint(484,528) << QPoint(484,494) << QPoint(625,452)
                       << QPoint(640,452) << QPoint(673,534);
    GroundMaterial* grass2 = new GroundMaterial(GroundMaterial::grass_material, grassPolygon2);
    grass2->setPen(linepen);
    scene->addItem(grass2);
    //--------------------------------------------------------

    //GRASS 3-------------------------------------------------
    //Grass 3 erstellen und zur scene hinzufügen
    QPolygonF grassPolygon3;
    grassPolygon3 << QPoint(635,365) << QPoint(625,365) << QPoint(529,278) << QPoint(629,184) << QPoint(761,272);
    GroundMaterial *grass3 = new GroundMaterial(GroundMaterial::grass_material, grassPolygon3);
    grass3->setPen(linepen);
    scene->addItem(grass3);
    //--------------------------------------------------------

    //HOLE 1-------------------------------------------------
    // Loch erstellen und zur scene hinzufügen
    QPolygonF holePoly;
    holePoly << QPoint(629,278) << QPoint(634,278) << QPoint(634,282) << QPoint(629,282);
    GroundMaterial* hole = new GroundMaterial(GroundMaterial::hole_material, holePoly);
    hole->setPen(linepen);
    scene->addItem(hole);
    //--------------------------------------------------------

    //CONTINUEBLOCK ------------------------------------------
    //Items für das mini menü erstellen und unsichtbar setzen
    continueItem->setRect(368,266,289,80);
    continueItem->setPen(linepen);
    continueItem->setVisible(false);
    scene->addItem(continueItem);
    //--------------------------------------------------------

    //LEVEBLOCK ----------------------------------------------
    //Items für das mini menü erstellen und unsichtbar setzen
    leaveItem->setRect(368,362,289,80);
    leaveItem->setPen(linepen);
    leaveItem->setVisible(false);
    scene->addItem(leaveItem);
    //--------------------------------------------------------

    // BORDERLINES -------------------------------------------
    //Begrenzungslinien zur Liste hinzufügen
    lineVec.push_back( new BorderLine(179,565,179,321,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(323,324,333,324,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(423,324,423,377,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(423,377,396,377,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(396,377,396,461,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(396,461,473,461,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(473,461,473,497,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(473,497,622,497,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(623,497,622,444,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(622,373,622,354,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(640,353,640,373,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(640,444,640,522,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(640,522,354,522,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(354,522,354,389,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(354,389,370,389,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(370,389,370,349,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(370,349,298,349,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(298,349,298,567,BorderLine::wood_material));

    //Linien unsichtbar machen + Linien zur Scene hinzufügen
    for (int i=0;i< static_cast<int>(lineVec.size());i++)
    {
        lineVec[i]->setPen(linepen);
        scene->addItem(lineVec[i]);
    }
    //--------------------------------------------------------

    // BORDERLINE CURVE---------------------------------------
    BorderLineCurveDrawer::draw(179,565,298,565, 60, 6.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::wood_material, scene, linepen);

    BorderLineCurveDrawer::draw(621,356,643,356, 73, 6.0,
                                BorderLineCurveDrawer::left, true,
                                BorderLine::wood_material, scene, linepen);
    //--------------------------------------------------------

    // BIRD---------------------------------------------------
    // Vogelbilder setzen + scene hinzufügen + position setzen
    vogel2 = new QGraphicsPixmapItem;
    vogel2->setPixmap(vogelimage);
    vogel2->setVisible(true);
    vogel2->setPos(50,100);
    scene->addItem(vogel2);
    //--------------------------------------------------------

    //Connecten der Slots
    connect(graphicsTimer, SIGNAL(timeout()),this, SLOT(updateLevel()));
    connect(continueItem,SIGNAL(mousePressed()),this,SLOT(menuLevel()));
    connect(leaveItem,SIGNAL(mousePressed()),this,SLOT(leaveLevel()));
}
//------------------------------------

void Level_4::menuLevel()
{   if (menuActive == false)
    {

    // Mini menü wird aufgerufen, brushes verändert und pausiert.
    scene->setForegroundBrush(QImage(QString(":/Images/Images/Level_4_ESC_Menu.png")));
    continueItem->setVisible(true);
    leaveItem->setVisible(true);
    menuActive = true;
    timer->stop();
    graphicsTimer->stop();
    }
else
    {

    // Mini menü wird geschlossen, brushes verändert und timer gestartet.
    scene->setForegroundBrush(Qt::NoBrush);
    continueItem->setVisible(false);
    leaveItem->setVisible(false);
    menuActive = false;
    timer->start();
    graphicsTimer->start();
    }
   // qDebug() << "menuLevel erreicht";
}
//------------------------------------

void Level_4::leaveLevel()
{
    emit destroyLevel4();
    qDebug() << "destroy level emittiert";
}
//------------------------------------

void Level_4::keyPressEvent(QKeyEvent *event) {

   // ESC taste wird eingefangen und menuLevel aufgerufen
   if (event->key() == Qt::Key_Escape)
   {
     menuLevel();
   }
}
//------------------------------------

void Level_4::updateLevel()
{
    //rand wird erzeugt um vogel zufällig erscheinen zu lassen
    float rand = qrand();
    int x,y;

    rand /= RAND_MAX;
    x = vogel2->x();
    y = vogel2->y();

    //WASSERANIMATIONEN---------------------------------------
    if(graphicsCounterFast == 6)
    {
        water_1->setBrush(QImage(":/Images/Images/wasser1.png"));
        water_2->setBrush(QImage(":/Images/Images/wasser4.png"));
        water_2->setBrush(QImage(":/Images/Images/wasser4.png"));
        water_4->setBrush(QImage(":/Images/Images/wasser1.png"));
    }

    if (graphicsCounterFast == 12)
    {
        water_1->setBrush(QImage(":/Images/Images/wasser2.png"));
        water_2->setBrush(QImage(":/Images/Images/wasser3.png"));
        water_3->setBrush(QImage(":/Images/Images/wasser3.png"));
        water_4->setBrush(QImage(":/Images/Images/wasser3.png"));
    }

    if (graphicsCounterFast == 16)
    {
        water_1->setBrush(QImage(":/Images/Images/wasser3.png"));
        water_2->setBrush(QImage(":/Images/Images/wasser2.png"));
        water_3->setBrush(QImage(":/Images/Images/wasser2.png"));
        water_4->setBrush(QImage(":/Images/Images/wasser3.png"));
    }

    if (graphicsCounterFast == 20)
    {
        water_1->setBrush(QImage(":/Images/Images/wasser4.png"));
        water_2->setBrush(QImage(":/Images/Images/wasser1.png"));
        water_3->setBrush(QImage(":/Images/Images/wasser1.png"));
        water_4->setBrush(QImage(":/Images/Images/wasser4.png"));
    }
    //--------------------------------------------------------

    //VOGELANIMATIONEN----------------------------------------
    // Vogelaction wird mit gewisser Wahrscheinlichkeit ausgelöst
    if (rand < 0.001)
    {
        vogelaction = true;
    }

    // Vogel wird versetzt und Bilder aktualisiert
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

    //Vogel auf erstes Bild setzen
    if(vogelCounter < 8)
    {
        vogel2->setPixmap(vogelimage);
    }

    //Vogel auf zweites Bild seten
    if(vogelCounter >= 8)
    {
        vogel2->setPixmap(vogelimage2);
    }

    //Counter zurücksetzen (max 10)
    if(vogelCounter >10)
    {
        vogelCounter = 0;
    }
    //--------------------------------------------------------

    // GATEANIMATIONEN & LINES -------------------------------
    if (graphicsCounterSlow == 20)
    {
        gate1->setRect(439,492,4,40);
        gate2->setRect(439,452,4,40);
        gateline1->setVisible(true);
        gateline2->setVisible(true);
    }
    if (graphicsCounterSlow == 40)
    {
        gate1->setRect(439,522,4,40);
        gate2->setRect(439,422,4,40);
        gateline1->setVisible(false);
        gateline2->setVisible(false);
    }
    //--------------------------------------------------------

   //counter zurücksetzen
   if(graphicsCounterFast  > 20)
   {
       graphicsCounterFast = 0;
   }
   //counter zurücksetzen
   if(graphicsCounterSlow > 40)
   {
       graphicsCounterSlow = 0;
   }

   //counter erhöhen
   vogelCounter++;
   graphicsCounterFast++;
   graphicsCounterSlow++;
}


