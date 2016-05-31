#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    const int width = 1024;
    const int height = 768;
    this->setFixedSize(width,height);

   MyCourt = new Court(ui->stackedWidget);

    ui->stackedWidget->addWidget(MyCourt);
    ui->stackedWidget->setCurrentIndex(0);
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
    ui->stackedWidget->setCurrentWidget(MyCourt);

}
