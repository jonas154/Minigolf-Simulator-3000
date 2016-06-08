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
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(10);

    graphicsTimer = new QTimer(this);
    graphicsTimer->start(33);

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
    arrowStart = new ArrowStartItem(ball);
    scene->addItem(arrowStart);
    //arrowStart->setPos(ball->pos()-QPointF(0.0,-50.0));

    arrow = new Arrow(arrowStart,ball);
    scene->addItem(arrow);
    arrow->updatePosition();
}

void Court::deleteArrow()
{
    scene->removeItem(arrowStart);
    scene->removeItem(arrow);
    delete arrowStart;
    delete arrow;
}

void Court::shot()
{
    ball->setAngle(arrow->getAngle());
    ball->setSpeed(arrow->getSpeed());
//    qDebug() << "speed handed to ball: " << arrow->getSpeed();
    this->deleteArrow();
}


