#include "court.h"


Court::Court(QWidget *parent)
    :
    QWidget(parent),
    ui(new Ui::Court),
    startCoordinates(0.0, 0.0)
{
    ui->setupUi(this);

    const int width = 1024;
    const int height = 768;

    ui->graphicsView->setFixedSize(width, height);
    ui->graphicsView->setSceneRect(0, 0, width, height);
    ui->graphicsView->setFrameStyle(0);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(33); //Bisschen mehr fps müssens schon sein!
    //Haha dann musst du aber die Zahl kleiner machen! Unbedingt bald klären, da hängt sehr viel dran!
    //25 fps reicht eigentlich fürs menschliche Auge



}

//------------------------------------------

Court::~Court()
{
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

QPointF Court::getStartCoordinates()
{
    return startCoordinates;
}

//------------------------------------------

Ball* Court::getBall()
{
    return ball;
};

//------------------------------------------

void Court::createBall()
{
    ball = new Ball;
    scene->addItem(ball);
    ball->setPos(startCoordinates);
}

void Court::createArrow()
{
    ArrowStartItem *arrowStart = new ArrowStartItem();
    scene->addItem(arrowStart);
    arrowStart->setPos(ball->pos()-QPointF(50.0,50.0));

    Arrow *arrow = new Arrow(arrowStart,ball);
    scene->addItem(arrow);
    arrow->updatePosition();
}


