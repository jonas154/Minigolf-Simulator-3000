#include "startwindow.h"


StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    const int width = 1024;
    const int height = 768;
    this->setFixedSize(width,height);

    statusBar()->setFixedHeight(0);

    ui->stackedWidget->setCurrentIndex(0);

    game = new Game(this);


}

StartWindow::~StartWindow()
{
    delete ui;
}



//void StartWindow::on_pushButton_clicked()
//{

//    Level_1* w = new Level_1;
//    ui->algoSettingsStackedWidget->setCurrentWidget(MyCourt);
//    w->show();

//}

void StartWindow::on_Start_clicked()
{
    game->startLevel(1);
}
