#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "ui_startwindow.h"
#include <QMainWindow>
#include "game.h"
#include "QString"
#include "QFile"

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

    void setLevel(int level);

private slots:
    void on_Start_clicked();

    void on_exitButton_clicked();

private:
    Ui::StartWindow* ui;

};

#endif // STARTWINDOW_H
