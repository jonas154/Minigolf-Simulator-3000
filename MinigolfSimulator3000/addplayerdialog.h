#ifndef ADDPLAYERDIALOG_H
#define ADDPLAYERDIALOG_H

#include <QDialog>
#include "startwindow.h"
#include <QString>
#include <QMessageBox>
class StartWindow;


namespace Ui {
class addPlayerDialog;
}

class addPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addPlayerDialog(StartWindow* _startwindow, QWidget *parent = 0);
    ~addPlayerDialog();

private slots:
    void on_addButton_clicked();

private:
    Ui::addPlayerDialog *ui;
    QString name = "";
    StartWindow* startwindow;
    int number;
};

#endif // ADDPLAYERDIALOG_H
