#include "level_2.h"


Level_2::Level_2(QWidget *parent)
    :
    Court(parent)
{
    //Startkoordinaten können zum debuggen versetzt werden "this->setStartCoordinates(528,298);"
    //um newton Fluid zu testen
    this->setStartCoordinates(195.0, 590.0);

    // Lochkoordinaten setzen
    this->setHoleCoordinates(693,321);
    this->constructLevel();

    this->createBall();
    this->createArrow(true);
}

//------------------------------------

void Level_2::constructLevel()
{
    // Pfade der Bilder in Strings Speichern
    QString bgroundimage = ":/Images/Images/Level_2.png";
    vogelimage = ":/Images/Images/v.png";
    vogelimage2 = ":/Images/Images/v2.png";

    //Couter für Update Level initialisiern
    vogelcounter = 0;
    vogelaction = false;

    //Mini Menü mit false initialisieren
    menuActive = false;

    //Vector für Verbindungslinien erstellen
    std::vector<BorderLine*> lineVec;

    // Hintergrundbild der scene setzen
    scene->setBackgroundBrush(QImage(bgroundimage));

    // Unsichtbaren QPen für linien erstellen
    // (zum debuggen QPen(Qt::red) anstatt linepen verwenden)

    QPen linepen;
    linepen.setWidth(2);
    linepen.setColor(QColor(0,0,0,0));
    linepen.setJoinStyle(Qt::RoundJoin);
    linepen.setCapStyle(Qt::RoundCap);

    //GRASS 1-------------------------------------------------
    //Grass 1 erstellen und zur scene hinzufügen
    QPolygonF grassPolygon1;
    grassPolygon1 << QPointF(140,638) << QPointF(134,154) << QPointF(400,154) << QPointF(410,576) << QPointF(398,590) << QPointF(390,649);
    GroundMaterial* grass1 = new GroundMaterial(GroundMaterial::grass_material, grassPolygon1);
    grass1->setPen(linepen);
    scene->addItem(grass1);
    //--------------------------------------------------------

    //GRASS 2-------------------------------------------------
    //Grass 2 erstellen und zur scene hinzufügen
    QPolygonF grassPolygon2;
    grassPolygon2 << QPointF(529,648)  << QPointF(526,591)  << QPointF(504,577)  << QPointF(505,269)  << QPointF(747,269) << QPointF(752,377)
              << QPointF(595,375) << QPointF(601,506) << QPointF(729,495) << QPointF(718,658);
    GroundMaterial* grass2 = new GroundMaterial(GroundMaterial::grass_material, grassPolygon2);
    grass2->setPen(linepen);
    scene->addItem(grass2);
    //--------------------------------------------------------

    //SAND 1-------------------------------------------------
    // Sand polygon erstellen und zur scene hinzufügen
    QPolygonF sandPolygon;
    sandPolygon << QPointF(403,648) << QPointF(520,648) << QPointF(519,592) << QPointF(404,590);
    GroundMaterial* sand = new GroundMaterial(GroundMaterial::sand_material, sandPolygon);
    sand->setPen(linepen);
    scene->addItem(sand);
    //--------------------------------------------------------

    //HOLE 1-------------------------------------------------
    // Loch erstellen und zur scene hinzufügen
    QPolygonF holePoly;
    holePoly << QPoint(690, 319) << QPoint(695, 319) << QPoint(695, 324) << QPoint(690, 324);
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
    lineVec.push_back( new BorderLine(143,590,143,269,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(246,592,246,286,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(275,288,275,378,BorderLine::wood_material));

    //line a
    lineVec.push_back( new BorderLine(275,378,317,432,BorderLine::wood_material));

    //line b
    lineVec.push_back( new BorderLine(321,443,321,521,BorderLine::wood_material));

    //line c
    lineVec.push_back( new BorderLine(318,531,277,564,BorderLine::wood_material));

    //line d
    lineVec.push_back( new BorderLine(399,379,368,430,BorderLine::wood_material));

    //line e
    lineVec.push_back( new BorderLine(364,440,364,524,BorderLine::wood_material));

    //line f
    lineVec.push_back( new BorderLine(368,533,399,566,BorderLine::wood_material));

    //line g
    lineVec.push_back( new BorderLine(399,566,399,584,BorderLine::wood_material));

    //line h
    lineVec.push_back( new BorderLine(405,593,647,592,BorderLine::wood_material));

    lineVec.push_back( new BorderLine(277,564,275,607,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(315,646,666,646,BorderLine::wood_material));

    //line i
    lineVec.push_back( new BorderLine(665,513,590,513,BorderLine::wood_material));

    //line j
    lineVec.push_back( new BorderLine(583,506,583,369,BorderLine::wood_material));

    //line k
    lineVec.push_back( new BorderLine(590,362,734,362,BorderLine::wood_material));

    lineVec.push_back( new BorderLine(734,362,734,279,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(734,279,516,279,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(516,279,516,279,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(516,570,647,570,BorderLine::wood_material));

    lineVec.push_back( new BorderLine(399,379,398,268,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(516,570,516,279,BorderLine::wood_material));

    //Linien unsichtbar machen + Linien zur Scene hinzufügen
    for (int i=0;i< static_cast<int>(lineVec.size());i++)
    {
        lineVec[i]->setPen(linepen);
        scene->addItem(lineVec[i]);
    }
    //--------------------------------------------------------


    // BORDERLINE CURVE---------------------------------------
    BorderLineCurveDrawer::draw(246,286, 275,288, 15, 6.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::wood_material, scene, linepen);
    BorderLineCurveDrawer::draw(143,269, 398,270, 130, 6.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::wood_material, scene, linepen);
    BorderLineCurveDrawer::draw(143,591, 246,590, 52, 6.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::wood_material, scene, linepen);
    BorderLineCurveDrawer::draw(315,646,275,607, 50, 6.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::wood_material, scene, linepen);
    BorderLineCurveDrawer::draw(660,645,669,513, 67, 6.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::wood_material, scene, linepen);
    BorderLineCurveDrawer::draw(648,570,647,592,12,6.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::wood_material, scene, linepen);

    //curve between line a and line b
    BorderLineCurveDrawer::draw(317,432,321,443, 15, 2.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::wood_material, scene, linepen);

    //curve between line b and line c
    BorderLineCurveDrawer::draw(321,521,318,531, 15, 2.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::wood_material, scene, linepen);

    //curve between line d and line e
    BorderLineCurveDrawer::draw(368,430,364,440, 15, 2.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::wood_material, scene, linepen);

    //curve between line e and line f
    BorderLineCurveDrawer::draw(364,524,368,533, 15, 2.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::wood_material, scene, linepen);

    //curve between line g and line h
    BorderLineCurveDrawer::draw(399,584,405,593, 8, 2.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::wood_material, scene, linepen);

    //curve between line i and line j
    BorderLineCurveDrawer::draw(590,513,583,506, 7, 2.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::wood_material, scene, linepen);

    //curve between line j and line k
    BorderLineCurveDrawer::draw(583,369,590,362, 7, 2.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::wood_material, scene, linepen);
    //--------------------------------------------------------

    // BIRD---------------------------------------------------
    // Vogelbilder setzen + scene hinzufügen + position setzen
    vogel = new QGraphicsPixmapItem;
    vogel->setPixmap(vogelimage);
    vogel->setVisible(false);
    vogel->setPos(50,100);
    scene->addItem(vogel);
    //--------------------------------------------------------

    //Connecten der Slots
    connect(graphicsTimer, SIGNAL(timeout()),this, SLOT(updateLevel()));
    connect(continueItem,SIGNAL(mousePressed()),this,SLOT(menuLevel()));
    connect(leaveItem,SIGNAL(mousePressed()),this,SLOT(leaveLevel()));
}
//------------------------------------

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
//------------------------------------

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
    //rand wird erzeugt um vogel zufällig erscheinen zu lassen
    float rand = qrand();
    int x,y;

    rand /= RAND_MAX;
    x = vogel->x();
    y = vogel->y();

    //VOGELANIMATIONEN----------------------------------------
    // Vogelaction wird mit gewisser Wahrscheinlichkeit ausgelöst
    if (rand < 0.003)
    {
        vogelaction = true;
        vogel->setVisible(true);
    }

    // Vogel wird versetzt und Bilder aktualisiert
    if(x < 1024  && vogelaction == true)
    {
        vogel->setVisible(true);
        vogel->setPos(x+10,y);
    }
    else
    {
        vogel->setPos(0,1000*rand);
        vogel->setVisible(false);
        vogelaction = false;
    }

    //Vogel auf erstes Bild setzen
    if(vogelcounter < 8)
    {
        vogel->setPixmap(vogelimage);
    }
    //Vogel auf zweites Bild seten
    if(vogelcounter >= 8)
    {
        vogel->setPixmap(vogelimage2);
    }
    //--------------------------------------------------------

    // Counter wird zurückgesetz (max 10)
    if(vogelcounter >10)
    {
        vogelcounter = 0;
    }

    //Counter werden erhöht um spezielle Timesteps erreichen zu können
    vogelcounter++;
}
