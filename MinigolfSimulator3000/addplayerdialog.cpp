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

    number = startwindow->playercounter + 1;


    startwindow->matrix[number-1][0] = QString::number(number);
    startwindow->matrix[number-1][1] = name;
    startwindow->matrix[number-1][2] = "Level1";
    startwindow->playercounter = number;

    addPlayerDialog::close();

}
