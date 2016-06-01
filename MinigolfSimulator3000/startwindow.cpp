#include "startwindow.h"


StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{

    ui->setupUi(this);

    int availableLevel = 2;
    const int width = 1024;
    const int height = 768;
    this->setFixedSize(width,height);

    statusBar()->setFixedHeight(0);

    ui->stackedWidget->setCurrentIndex(0);


    game = new Game(this);

    for (int i = 1;i <= availableLevel;i++)
    {
        ui->levelBox->addItem("Level" + QString::number(i));
    }


    QString mFilename = ":/mingolfSimulator3000.txt";
    QFile file(mFilename);



}


StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::on_Start_clicked()
{
    game->startLevel(1);
}

void StartWindow::setLevel(int level)
{
    level = ui->levelBox->currentIndex();
}

void StartWindow::on_exitButton_clicked()
{
    qApp->quit();
}
