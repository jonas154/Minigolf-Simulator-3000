#include "level_3.h"
#include "rectitem.h"
#include "startwindow.h"


Level_3::Level_3(QWidget *parent)
    :
    Court(parent)
{
    //Startkoordinaten können zum debuggen versetzt werden "this->setStartCoordinates(528,298);"
    //um newton Fluid zu testen
    this->setStartCoordinates(240.0, 570.0);

    // Lochkoordinaten setzen
    this->setHoleCoordinates(519.0,291.0);
    this->constructLevel();

    this->createBall();
    this->createArrow(true);
}

//------------------------------------

void Level_3::constructLevel()
{
    // Pfade der Bilder in Strings Speichern
    QString bgroundimage = ":/Images/Images/Level_3.png";
    waterimage = ":/Images/Images/wasser3_1.png";
    vogelimage = ":/Images/Images/v.png";
    vogelimage2 = ":/Images/Images/v2.png";

    nonnewtonimage = ":/Images/Images/newton_1.png";
    nonnewtonimage2 = ":/Images/Images/newton_2.png";

    //Couter für Update Level initialisiern
    vogelcounter = 0;
    graphicsCounterFast = 0;
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
    // Wasserbilder Polygon erstellen
    QPolygon water_polygon;
    water_polygon << QPoint(180,322) << QPoint(180,319)  << QPoint(155,319) << QPoint(155,256)
                  << QPoint(322,256) << QPoint(322,319)  << QPoint(297,319)  << QPoint(297,323);
    water = new GroundMaterial(GroundMaterial::water_material,water_polygon);

    // Bilder einbinden und zu Scene hinzufügen
    water->setBrush(QImage(waterimage));
    scene->addItem(water);
    water->setVisible(true);
    water->setPen(Qt::NoPen);
    //--------------------------------------------------------

    //NONNEWTONFLUID 1-----------------------------------------
    //Nonnewtonsches Fluid erstellen und zur scene hinzufügen
    QPolygon nonnewton_polygon;
    nonnewton_polygon << QPoint(356,370) << QPoint(356,448) << QPoint(437,448) << QPoint(437,370);
    nonnewton = new GroundMaterial(GroundMaterial::nonNewtonian_material,nonnewton_polygon);
    nonnewton->setBrush(QImage(nonnewtonimage));
    scene->addItem(nonnewton);
    nonnewton->setVisible(true);
    nonnewton->setPen(Qt::NoPen);
    //--------------------------------------------------------

    //GRASS 1-------------------------------------------------
    //Grass 1 erstellen und zur scene hinzufügen
    QPolygonF grassPolygon1;
    grassPolygon1 << QPoint(170,625) << QPoint(178,334)  << QPoint(411,334)
                  << QPoint(411,359) << QPoint(304,356)  << QPoint(313,643);
    GroundMaterial* grass1 = new GroundMaterial(GroundMaterial::grass_material, grassPolygon1);
    grass1->setPen(linepen);
    scene->addItem(grass1);
    //--------------------------------------------------------

    //GRASS 2-------------------------------------------------
    //Grass 2 erstellen und zur scene hinzufügen
    QPolygonF grassPolygon2;
    grassPolygon2  << QPoint(371,460) << QPoint(423,460) << QPoint(423,511) << QPoint(629,511)
                   << QPoint(629,322) << QPoint(490,322) << QPoint(490,262) << QPoint(681,258)
                   << QPoint(684,560) << QPoint(367,558);
    GroundMaterial* grass2 = new GroundMaterial(GroundMaterial::grass_material, grassPolygon2);
    grass2->setPen(linepen);
    scene->addItem(grass2);
    //--------------------------------------------------------

    //HOLE 1-------------------------------------------------
    // Loch erstellen und zur scene hinzufügen
    QPolygonF holePoly;
    holePoly << QPoint(516,288) << QPoint(516,293) << QPoint(521,293) << QPoint(521,288);
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
    lineVec.push_back( new BorderLine(179,565,179,324,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(298,320,298,332,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(298,332,408,332,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(408,332,408,369,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(408,369,438,369,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(438,369,438,449,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(438,449,418,449,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(418,449,418,515,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(418,515,635,515,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(635,515,635,316,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(635,316,495,316,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(495,316,495,266,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(495,266,664,266,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(675,276,675,535,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(664,549,387,549,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(375,539,375,449,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(375,449,355,449,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(355,449,355,369,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(355,369,385,369,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(385,369,385,349,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(385,349,298,349,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(298,349,298,565,BorderLine::wood_material));

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
    BorderLineCurveDrawer::draw(375,539,387,549, 20, 6.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::wood_material, scene, linepen);
    BorderLineCurveDrawer::draw(663,549,675,535, 19, 6.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::wood_material, scene, linepen);

    BorderLineCurveDrawer::draw(664,266,675,277, 17, 6.0,
                                BorderLineCurveDrawer::left, false,
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

void Level_3::menuLevel()
{   if (menuActive == false)
    {

    // Mini menü wird aufgerufen, brushes verändert und pausiert.
    scene->setForegroundBrush(QImage(QString(":/Images/Images/Level_3_ESC_Menu.png")));
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

void Level_3::leaveLevel()
{
    emit destroyLevel3();
    qDebug() << "destroy level emittiert";
}
//------------------------------------

void Level_3::keyPressEvent(QKeyEvent *event) {

   // ESC taste wird eingefangen und menuLevel aufgerufen
   if (event->key() == Qt::Key_Escape)
   {
     menuLevel();
   }
}
//------------------------------------

void Level_3::updateLevel()
{
    //rand wird erzeugt um vogel zufällig erscheinen zu lassen
    float rand = qrand();
    int x,y;

    rand /= RAND_MAX;
    x = vogel2->x();
    y = vogel2->y();

    //WASSERANIMATIONEN&NONNEWTON FLUID-------------------------
    if (graphicsCounterFast == 6)
    {
        water->setBrush(QImage(":/Images/Images/wasser1.png"));
    }

    if (graphicsCounterFast == 12)
    {
        water->setBrush(QImage(":/Images/Images/wasser2.png"));
        nonnewton->setBrush(QImage(nonnewtonimage2));
    }

    if (graphicsCounterFast == 16)
    {
        water->setBrush(QImage(":/Images/Images/wasser3.png"));
    }

    if (graphicsCounterFast == 20)
    {
        water->setBrush(QImage(":/Images/Images/wasser4.png"));
        nonnewton->setBrush(QImage(nonnewtonimage));
    }
    //--------------------------------------------------------

    //VOGELANIMATIONEN----------------------------------------
    // Vogelaction wird mit gewisser Wahrscheinlichkeit ausgelöst
    if (rand < 0.003)
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
    if(vogelcounter < 8)
    {
        vogel2->setPixmap(vogelimage);
    }
    //Vogel auf zweites Bild seten
    if(vogelcounter >= 8)
    {
        vogel2->setPixmap(vogelimage2);
    }
    //--------------------------------------------------------

    //counter zurücksetzen (max 20)
    if(graphicsCounterFast  >20)
    {
        graphicsCounterFast = 0;
    }
    // Counter wird zurückgesetz (max 10)
    if(vogelcounter >10)
    {
        vogelcounter = 0;
    }

    //Counter werden erhöht um spezielle Timesteps erreichen zu können
    vogelcounter++;
    graphicsCounterFast++;
}

