#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "ui_startwindow.h"
#include <QMainWindow>
#include "game.h"
#include "QString"
#include "QFile"
#include "addplayerdialog.h"
#include <QMessageBox>
#include <QPalette>


class Game;
class addPlayerDialog;

namespace Ui
{
    class StartWindow;
}


//! This class creates the startwindow and manages the player and their parameter.

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:

    //! \brief Constructor
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

    QScopedPointer<Game> game;

    Ui::StartWindow* getUi()
    {
        return this->ui;
    };

    //! \brief In this matrix all player data is stored
    QString matrix[100][4];

    //! \brief Counts how many players are already added
    int playercounter = 0;

    //! \brief Game mode
    //! "false" = Single-Player-Mode (SP)
    //! "true" = Multi-Player-Mode (MP)
    bool multiPlayerMode = false;

    //! \brief Creates Level-Box with unlocked levels
    void createLevelBox();

    //! \brief Creates Player-Box with player names
    void createPlayerBox();

    //! \brief returns the actual Player1 (MP-mode) or Player (SP-mode) name
    QString getActPlayer1Name();

    //! \brief returns the actual Player2 (MP-mode) name
    QString getActPlayer2Name();

    //! \brief returns the unlocked level for the chosen Player (SP-mode)
    int getActLevel();

    //! \brief changes the unlocked level for the actual Player
    void setActLevel(int actLevel);

    //! \brief returns the actual Player1 (MP-mode) or Player (SP-mode) index-number
    int getActPlayer1Index();

    //! \brief returns the actual Player2 (MP-mode) index-number
    int getActPlayer2Index();

    //! \brief returns the actual Player1 (MP-mode) or Player (SP-mode) highscore
    int getActHighscorePlayer1();

    //! \brief returns the actual Player2 (MP-mode) highscore
    int getActHighscorePlayer2();

    //! \brief changes the highscore of the actual Player1 (MP-mode) or Player (SP-Mode)
    void setActPlayer1Highscore(int actHighscorePlayer1);

    //! \brief changes the highscore of the actual Player2 (MP-mode)
    void setActPlayer2Highscore(int actHighscorePlayer2);

    //! \brief returns the game mode
    //! "false" = Single-Player-Mode (SP)
    //! "true" = Multi-Player-Mode (MP)
    bool getGameMode();

private slots:

    //! \brief Starts a SP-game with the in the level-box selected level
    void on_startButton_clicked();

    //! \brief Closes the programm
    void on_exitButton_clicked();

    //! \brief Opens a Dialog for adding a new player
    void on_addPlayerButton_clicked();

    //! \brief Opens the Highscore-Screen (page 2 in Stacked-Widget)
    //! As sort algorithm for sorting the player names according to the highscore points is a bubble sort implemented.
    void on_highscoreButton_clicked();

    //! \brief Changes to the the MultiPlayer-Mode (page 1 in Stacked-Widget)
    void on_mpModeButton_clicked();

    //! \brief Checks if a new Player is in the PlayerBox choosen and updates the LevelBox
    void on_playerBox_currentIndexChanged(int index);



    //! \brief Starts a MP-game with the in the level-box selected level
    void on_startMPButton_clicked();

    //! \brief Closes the programm
    void on_exitMPButton_clicked();

    //! \brief Opens a Dialog for adding a new player
    void on_addPlayerMPButton_clicked();

    //! \brief Opens the Highscore-Screen (next page in Stacked-Widget)
    void on_highscoreMPButton_clicked();

    //! \brief Changes to the the SinglePlayer/Standard-Mode (page 0 in Stacked-Widget)
    void on_spModeButton_clicked();

    //void on_player1BoxMP_currentIndexChanged(int index);

    //void on_player2BoxMP_currentIndexChanged(int index);

    //! \brief To get from the highscore back to the last Game-Menu (Single-Player or Multi-Player mode)
    void on_backToMainMenuButton_clicked();


private:
    Ui::StartWindow* ui;

    //! \brief Variable with the number of available levels
    int availableLevel = 4;

    bool firstStart = false;

    int maxPlayer = 100;


    //! \brief Functions for checking and file-handling if we are in the first start of the programm
    void checkFile();

    //! \brief Writing players data to config.txt
    //! Structure: Index:Name:Freigeschaltene_Levell:Highsccore:"
    //! Example: 1:Jonas:2:1000:":2:TestUser:1:50"
    void writeFile();

    //! \brief Reads players data from config.txt
    void readLines();

    //! \brief Manipulating the X-Button of the window
    void closeEvent(QCloseEvent *);

};

#endif // STARTWINDOW_H
