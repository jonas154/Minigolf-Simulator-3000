#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "ui_startwindow.h"
#include <QMainWindow>
#include "game.h"
#include "QString"
#include "QFile"
#include "addplayerdialog.h"
class Game;
class addPlayerDialog;

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

   // void setMatrix(QString playerMatrix[10][3]);
    //QString getMatrix();

    int getLevel();
  //  int getPlayerCounter();
    bool fileExists(QString filename);
    QString matrix[10][3];
    int playercounter;

    void writeFile();
    void readLines();
private slots:
    void on_Start_clicked();
    void on_exitButton_clicked();
    void on_addPlayer_clicked();


private:
    Ui::StartWindow* ui;
   // std::vector<Player*> playerVec;


};

#endif // STARTWINDOW_H
