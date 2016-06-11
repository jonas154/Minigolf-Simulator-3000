#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "ui_startwindow.h"
#include <QMainWindow>
#include "game.h"
#include "QString"
#include "QFile"
#include "addplayerdialog.h"
#include <QMessageBox>
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

    int getLevel();
    bool fileExists(QString filename);
    QString matrix[10][4];
    int playercounter = 0;
    bool firstStart = false;

    void writeFile();
    void readLines();
    void createLevelBox();
    void createPlayerBox();
    QString getActPlayerName();
    void setActLevel(int actLevel);
    int getActLevel();
    int getActPlayerIndex();
    void setActHighscore(int actHighscore);
    int getActHighscore();

private slots:
    void on_Start_clicked();
    void on_exitButton_clicked();
    void on_addPlayer_clicked();
    void on_playerBox_currentIndexChanged(int index);

    void on_Highscore_clicked();

    void on_pushButton_clicked();

private:
    Ui::StartWindow* ui;
    int availableLevel = 2;
    void checkFile();
    void closeEvent(QCloseEvent *);

};

#endif // STARTWINDOW_H
