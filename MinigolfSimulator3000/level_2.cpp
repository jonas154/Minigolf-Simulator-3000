#include "level_2.h"


Level_2::Level_2(QWidget *parent)
    :
    Court(parent)
{

    this->setStartCoordinates(195.0, 590.0);
    this->setHoleCoordinates(689,318);
    this->constructLevel();
    this->createBall();

    this->createArrow(true);


}

//-----------------------------------

void Level_2::constructLevel()
{
    // Pfade der Bilder in Strings Speichern
    QString bgroundimage = ":/Images/Images/Level_2.png";
    waterimage = ":/Images/Images/wasser1.png";
    vogelimage = ":/Images/Images/v.png";
    vogelimage2 = ":/Images/Images/v2.png";

    //Couter für Update Level initialisiern
    vogelcounter = 0;
    wassercounter = 0;
    vogelaction = false;

    //Mini Menü mit false initialisieren
    menuActive = false;

    //Vector für Verbindungslinien erstellen
    std::vector<BorderLine*> lineVec;

    // Hintergrundbild der scene setzen
    scene->setBackgroundBrush(QImage(bgroundimage));

    // Unsichtbaren QPen für linien erstellen
    QPen linepen;
    linepen.setWidth(2);
    linepen.setColor(QColor(0,0,0,0));
    linepen.setJoinStyle(Qt::RoundJoin);
    linepen.setCapStyle(Qt::RoundCap);

    //Grass Material erstellen und zur scene hinzufügen
    //[zum debuggen QPen(Qt::red) anstatt linepen verwenden]
    QPolygonF grassPolygon1;
    QPolygonF grassPolygon2;
    grassPolygon1 << QPointF(140,638) << QPointF(134,154) << QPointF(400,154) << QPointF(410,576) << QPointF(398,590) << QPointF(390,649);
    grassPolygon2 << QPointF(529,648)  << QPointF(526,591)  << QPointF(504,577)  << QPointF(505,269)  << QPointF(747,269) << QPointF(752,377)
                  << QPointF(595,375) << QPointF(601,506) << QPointF(729,495) << QPointF(718,658);
    GroundMaterial* grass1 = new GroundMaterial(GroundMaterial::grass_material, grassPolygon1);
    GroundMaterial* grass2 = new GroundMaterial(GroundMaterial::grass_material, grassPolygon2);
    grass1->setPen(linepen);
    scene->addItem(grass1);
    grass2->setPen(linepen);
    scene->addItem(grass2);

    // Sand polygon erstellen und zur scene hinzufügen
    QPolygonF sandPolygon;
    sandPolygon << QPointF(403,648) << QPointF(520,648) << QPointF(519,592) << QPointF(404,590);
    GroundMaterial* sand = new GroundMaterial(GroundMaterial::sand_material, sandPolygon);
    sand->setPen(linepen);
    scene->addItem(sand);

    //Items für das mini menü erstellen und unsichtbar setzen
    continueItem->setRect(368,266,289,80);
    continueItem->setPen(linepen);
    continueItem->setVisible(false);
    scene->addItem(continueItem);

    //Items für das mini menü erstellen und unsichtbar setzen
    leaveItem->setRect(368,362,289,80);
    leaveItem->setPen(linepen);
    leaveItem->setVisible(false);
    scene->addItem(leaveItem);

    // Loch erstellen und zur scene hinzufügen
    QPolygonF holePoly;
    holePoly << QPoint(689, 318) << QPoint(689, 343) << QPoint(694, 348) << QPoint(689, 343);
    GroundMaterial* hole = new GroundMaterial(GroundMaterial::hole_material, holePoly);
    hole->setPen(linepen);
    scene->addItem(hole);

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

    // Kurven Zeichnen
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
    for (int i=0;i< static_cast<int>(lineVec.size());i++)
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

    //Connecten der Slots
    connect(graphicsTimer, SIGNAL(timeout()),this, SLOT(updateLevel()));
    connect(continueItem,SIGNAL(mousePressed()),this,SLOT(menuLevel()));
    connect(leaveItem,SIGNAL(mousePressed()),this,SLOT(leaveLevel()));

}

void Level_2::menuLevel()
{   if (menuActive == false)
    {
    // Mini menü wird aufgerufen, brushes verändert und pausiert.
    scene->setForegroundBrush(QImage(QString(":/Images/Images/Level_2_ESC_Menu.png")));
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

    if(vogelcounter < 8)
    {
        vogel2->setPixmap(vogelimage);
    }

    if(vogelcounter >= 8)
    {
        vogel2->setPixmap(vogelimage2);
    }

    //Counter werden erhöht um spezielle Timesteps erreichen zu können
    vogelcounter++;

    // Counter wird zurückgesetz
    if(vogelcounter >10)
    {
        vogelcounter = 0;
    }

}
