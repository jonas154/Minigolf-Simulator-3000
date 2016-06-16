#include "court.h"


Court::Court(QWidget *parent)
    :
    QWidget(parent),
    ui(new Ui::Court),
    startCoordinates(0.0, 0.0),
    holeCoordinates(0.0, 0.0)
{
    ui->setupUi(this);

    const int width = 1024;
    const int height = 768;

    ui->graphicsView->setFixedSize(width, height);
    ui->graphicsView->setSceneRect(0, 0, width, height);
    ui->graphicsView->setFrameStyle(0);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1024,768);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(10);

    graphicsTimer = new QTimer(this);
    graphicsTimer->start(33);

    continueItem = new RectItem;
    leaveItem = new RectItem;




}

//------------------------------------------

Court::~Court()
{
    delete ball;
    delete timer;
    delete graphicsTimer;
    delete continueItem;
    delete leaveItem;
    delete scene;
    delete ui;
};

//------------------------------------------

QGraphicsScene* Court::getScene()
{
    return this->scene;
};

//------------------------------------------

void Court::setStartCoordinates(const QPointF startPoint)
{
    startCoordinates = startPoint;
};

void Court::setStartCoordinates(const qreal x, const qreal y)
{
    startCoordinates = QPointF(x, y);
};

//------------------------------------------

void Court::setHoleCoordinates(const QPointF startPoint)
{
    holeCoordinates = startPoint;
};

void Court::setHoleCoordinates(const qreal x, const qreal y)
{
    holeCoordinates = QPointF(x, y);
};

//------------------------------------------

QPointF Court::getStartCoordinates()
{
    return startCoordinates;
}

//------------------------------------------

QPointF Court::getHoleCoordinates()
{
    return holeCoordinates;
}

//------------------------------------------

Ball* Court::getBall()
{
    return ball;
};

//------------------------------------------

void Court::createBall()
{
    ball = new Ball(startCoordinates);
    scene->addItem(ball);
    ball->setPos(startCoordinates);
}

void Court::createArrow(bool firstCreate)
{
    arrowStart = new ArrowStartItem(ball, firstCreate);
    scene->addItem(arrowStart);
    //arrowStart->setPos(ball->pos()-QPointF(0.0,-50.0));

    arrow = new Arrow(arrowStart,ball);
    scene->addItem(arrow);
    //arrow->updatePosition();
    connect(arrowStart,SIGNAL(arrowStartItemReleased()),this,SLOT(shot()));
}

void Court::deleteArrow()
{
    disconnect(arrowStart,SIGNAL(arrowStartItemReleased()),this,SLOT(shot()));
    scene->removeItem(arrowStart);
    scene->removeItem(arrow);
    delete arrow;
    delete arrowStart;
}

void Court::shot()
{
    ball->playShotSound();
    ball->setAngle(arrow->getAngle());
    ball->setSpeed(arrow->getSpeed());
//    qDebug() << "speed handed to ball: " << arrow->getSpeed();
    this->deleteArrow();
}


