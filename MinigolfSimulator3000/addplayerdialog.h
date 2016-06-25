#ifndef ADDPLAYERDIALOG_H
#define ADDPLAYERDIALOG_H

#include <QDialog>
#include "startwindow.h"
#include <QString>
#include <QMessageBox>
#include <QPalette>
#include <QBrush>


class StartWindow;


namespace Ui
{
    class addPlayerDialog;
}


//! This class is needed for creating new player and is called by the startwindow.

class addPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addPlayerDialog(StartWindow* _startwindow, QWidget *parent = 0);
    ~addPlayerDialog();

private slots:
    //!\brief If a correct name was insert, this function adds the name to the programm
    void on_addButton_clicked();

private:
    Ui::addPlayerDialog *ui;

    //!\brief Name of the added player
    QString name = "";

    StartWindow* startwindow;

    //! \ Index of the added player
    int number;
};

#endif // ADDPLAYERDIALOG_H
