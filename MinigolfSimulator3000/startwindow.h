#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "ui_startwindow.h"
#include <QMainWindow>
#include "game.h"

class Game;

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();
    Game* game;

    Ui::StartWindow* getUi()
    {
        return this->ui;
    };

private slots:
   // void on_pushButton_clicked();

    void on_Start_clicked();

private:
    Ui::StartWindow* ui;

};

#endif // STARTWINDOW_H
