#include "level_1.h"



Level_1::Level_1(QWidget *parent)
    :
    Court(parent)
{
    //Startkoordinaten können zum debuggen versetzt werden "this->setStartCoordinates(528,298);"
    //um newton Fluid zu testen
    this->setStartCoordinates(218.0, 600.0);

    // Lochkoordinaten setzen
    this->setHoleCoordinates(693.5, 296.0);
    this->constructLevel();

    this->createBall();
    this->createArrow(true);

}

//------------------------------------

void Level_1::constructLevel()
{
    // Pfade der Bilder in Strings Speichern
    QString bgroundimage = ":/Images/Images/Level_1.png";
    waterimage = ":/Images/Images/wasser1.png";
    vogelimage = ":/Images/Images/v.png";
    vogelimage2 = ":/Images/Images/v2.png";

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
    water_polygon << QPoint(140,250) << QPoint(140,152) << QPoint(293,152) << QPoint(294,252);
    water = new GroundMaterial(GroundMaterial::water_material,water_polygon);

    // Bilder einbinden und zu Scene hinzufügen
    water->setBrush(QImage(waterimage));
    scene->addItem(water);
    water->setVisible(true);
    water->setPen(Qt::NoPen);
    //--------------------------------------------------------



    //GRASS 1-------------------------------------------------
    //Grass 1 erstellen und zur scene hinzufügen
    QPolygonF grassPolygon;
    grassPolygon << QPoint(126,664) << QPoint(310,665) <<QPoint(302,382) <<QPoint(343,345) <<QPoint(740,343) <<QPoint(739,245)
    <<QPoint(300,245) << QPoint(300, 265) <<QPoint(132,265);
    GroundMaterial* grass = new GroundMaterial(GroundMaterial::grass_material, grassPolygon);
    grass->setPen(linepen);
    scene->addItem(grass);
    //--------------------------------------------------------

    //HOLE 1-------------------------------------------------
    // Loch erstellen und zur scene hinzufügen
    QPolygonF holePoly;
    holePoly << QPoint(691, 294) << QPoint(696, 294) << QPoint(696, 299) << QPoint(691, 299);
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
    lineVec.push_back( new BorderLine(294.0,594.0,294.0,380.0,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(298.0,371.0,331.0,341.0,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(340.0,337.0,730.0,337.0,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(730.0,337.0,730.0,253.0,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(294.0,253.0,294.0,151.0,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(730.0,253.0,294.0,253.0,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(294.0,151.0,140.0,151.0,BorderLine::wood_material));
    lineVec.push_back( new BorderLine(140.0,151.0,140.0,594.0,BorderLine::wood_material));

    //Linien unsichtbar machen + Linien zur Scene hinzufügen
    for (int i=0;i< static_cast<int>(lineVec.size());i++)
    {
        lineVec[i]->setPen(linepen);
        scene->addItem(lineVec[i]);
    }
    //--------------------------------------------------------

    // BORDERLINE CURVE---------------------------------------
    BorderLineCurveDrawer::draw(140.0, 594.0, 294.0, 594.0, 77.5, 6.0,
                                BorderLineCurveDrawer::right, false,
                                BorderLine::wood_material, scene, linepen);

    BorderLineCurveDrawer::draw(294.0, 380.0, 298.0, 371.0, 15.0, 2.0,
                                BorderLineCurveDrawer::left, false,
                                BorderLine::wood_material, scene, linepen);

    BorderLineCurveDrawer::draw(331.0, 341.0, 340.0, 337.0, 15.0, 2.0,
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

void Level_1::menuLevel()
{   if (menuActive == false)
    {
        // Mini menü wird aufgerufen, brushes verändert und pausiert.
        scene->setForegroundBrush(QImage(QString(":/Images/Images/Level_1_ESC_Menu.png")));
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

void Level_1::leaveLevel()
{
    emit destroyLevel();
    qDebug() << "destroy level emittiert";
}

//------------------------------------

void Level_1::keyPressEvent(QKeyEvent *event) {

    // ESC taste wird eingefangen und menuLevel aufgerufen
    if (event->key() == Qt::Key_Escape)
    {
        menuLevel();
    }
}
//------------------------------------
void Level_1::updateLevel()
{

    float rand = qrand();
    int x,y;

    rand /= RAND_MAX;
    x = vogel->x();
    y = vogel->y();

    //WASSERANIMATIONEN----------------------------------------
    if (graphicsCounterFast == 6)
    {
        water->setBrush(QImage(":/Images/Images/wasser1.png"));
    }

    if (graphicsCounterFast == 12)
    {
        water->setBrush(QImage(":/Images/Images/wasser2.png"));
    }

    if (graphicsCounterFast == 16)
    {
        water->setBrush(QImage(":/Images/Images/wasser3.png"));
    }

    if (graphicsCounterFast == 20)
    {
        water->setBrush(QImage(":/Images/Images/wasser4.png"));
    }
    //--------------------------------------------------------

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
        vogel->setPos(0,500);
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

    //counter zurücksetzen (max 20)
    if(graphicsCounterFast  >20)
    {
        graphicsCounterFast = 0;
    }

    //Counter werden erhöht um spezielle Timesteps erreichen zu können
    vogelcounter++;
    graphicsCounterFast++;
}
