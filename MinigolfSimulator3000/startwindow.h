#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "level_1.h"
#include "QString"
#include "QFile"

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

    void setLevel(int level);

private slots:
    void on_Start_clicked();

    void on_exitButton_clicked();

private:
    Ui::StartWindow *ui;
    Level_1 *myLevel_1;

};

#endif // STARTWINDOW_H
