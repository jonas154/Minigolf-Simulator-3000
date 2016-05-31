#include "court2.h"
#include "ui_court2.h"

Court2::Court2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Court2)
{
    ui->setupUi(this);
}

Court2::~Court2()
{
    delete ui;
}
