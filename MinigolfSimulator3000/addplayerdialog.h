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
    class AddPlayerDialog;
}


//! This class is needed for creating new player and is called by the startwindow.

class AddPlayerDialog : public QDialog
{
    Q_OBJECT

public:

    //! \brief Constructor
    explicit AddPlayerDialog(StartWindow* _startwindow, QWidget *parent = 0);

    //! \brief Destructor
    ~AddPlayerDialog();

private slots:

    //!\brief If a correct name was inserted, this function adds the name to the programm
    void on_addButton_clicked();

private:

    Ui::AddPlayerDialog *ui;

    //!\brief Name of the added player
    QString name = "";

    StartWindow* startwindow;

    //! \ Index of the added player
    int number;
};

#endif // ADDPLAYERDIALOG_H
