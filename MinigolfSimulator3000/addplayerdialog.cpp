#include "addplayerdialog.h"
#include "ui_addplayerdialog.h"

addPlayerDialog::addPlayerDialog(StartWindow* _startwindow, QWidget *parent) :
    startwindow(_startwindow),
    QDialog(parent),
    ui(new Ui::addPlayerDialog)
{
    ui->setupUi(this);
}

addPlayerDialog::~addPlayerDialog()
{
    delete ui;
}

void addPlayerDialog::on_addButton_clicked()
{

    name = ui->inputName->text();


    startwindow->playercounter = startwindow->playercounter + 1;
    number = startwindow->playercounter;

    startwindow->matrix[number - 1][0] = QString::number(number);
    startwindow->matrix[number - 1][1] = name;
    startwindow->matrix[number - 1][2] = QString::number(1);
    startwindow->matrix[number - 1][3] = QString::number(0);

    startwindow->playercounter = number;

    addPlayerDialog::close();

}
