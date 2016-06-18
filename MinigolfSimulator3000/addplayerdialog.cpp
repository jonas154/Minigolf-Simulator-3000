#include "addplayerdialog.h"
#include "ui_addplayerdialog.h"

addPlayerDialog::addPlayerDialog(StartWindow* _startwindow, QWidget *parent) :
    startwindow(_startwindow),
    QDialog(parent),
    ui(new Ui::addPlayerDialog)
{
    ui->setupUi(this);
    const int width2 = 600;
    const int height2 = 100;
    this->setFixedSize(width2,height2);
    ui->addButton->setStyleSheet("border-image:url(:/Images/Images/button_template.png);");
    QPalette pale;
    pale.setBrush(this->backgroundRole(),QBrush(QImage(":/Images/Images/addPlayerDialog.png")));
    this->setPalette(pale);

}
addPlayerDialog::~addPlayerDialog()
{
    delete ui;
}

void addPlayerDialog::on_addButton_clicked()
{
    name = ui->inputName->text();

    if(name.isEmpty()==true)
    {
        QMessageBox::information(this,"Information","Ihre Eingabe war fehlerhaft. Es wurde kein Player angelegt.");
    }
    else{
        startwindow->playercounter = startwindow->playercounter + 1;
        number = startwindow->playercounter;
        startwindow->matrix[number - 1][0] = QString::number(number);
        startwindow->matrix[number - 1][1] = name;
        startwindow->matrix[number - 1][2] = QString::number(1);
        startwindow->matrix[number - 1][3] = QString::number(0);
        startwindow->playercounter = number;
    }

    addPlayerDialog::close();

}
