#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "level_1.h"
#include "court.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
   // void on_pushButton_clicked();

    void on_Start_clicked();

private:
    Ui::StartWindow *ui;
    Court *MyCourt;

};

#endif // STARTWINDOW_H
