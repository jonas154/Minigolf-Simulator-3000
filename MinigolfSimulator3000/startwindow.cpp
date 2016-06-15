#include "startwindow.h"


StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{

    ui->setupUi(this);


    const int width = 1024;
    const int height = 768;
    this->setFixedSize(width,height);
    ui->stackedWidget->setCurrentIndex(0);
    QPalette* palette = new QPalette();
    //palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/Images/Images/test_background.jpg")))));
    setPalette(*palette);
   // ui->addPlayerButton->setStyleSheet("border-image:url(:/Images/Images/test_background.jpg);");
    this->checkFile();

    statusBar()->setFixedHeight(0);


    game = new Game(this);

    this->createPlayerBox();

}
StartWindow::~StartWindow()
{
    delete ui;
}

QString StartWindow::getActPlayer1Name()
{
    if (multiPlayerMode == true)
    {
        QString _actPlayerName = matrix[ui->player1BoxMP->currentIndex()][1];
        return _actPlayerName;
    }
    else
    {
        QString _actPlayerName = matrix[ui->playerBox->currentIndex()][1];
        return _actPlayerName;
    }


}

QString StartWindow::getActPlayer2Name()
{
    QString _actPlayerName = matrix[ui->player2BoxMP->currentIndex()][1];
    return _actPlayerName;
}

int StartWindow::getActPlayer1Index()
{
    if(multiPlayerMode == true)
    {
        QString _actplayerindex = matrix[ui->player1BoxMP->currentIndex()][0];
        return _actplayerindex.toInt();
    }
    else
    {
        QString _actplayerindex = matrix[ui->playerBox->currentIndex()][0];
        return _actplayerindex.toInt();
    }


}

int StartWindow::getActPlayer2Index()
{
    QString _actplayerindex = matrix[ui->player2BoxMP->currentIndex()][0];
    return _actplayerindex.toInt();
}

bool StartWindow::getGameMode()
{
    return multiPlayerMode;
}

int StartWindow::getActLevel() // HIER IST NOCH DEBUGGING CODE INSIDE !!!
{
    QString _actLevel = matrix[ui->playerBox->currentIndex()][2];
      return 2;
    //return _actLevel.toInt();

}

void StartWindow::setActLevel(int actLevel)
{
    matrix[ui->playerBox->currentIndex()][2] = actLevel;
    ui->levelBox->clear();
    this->createLevelBox();
}

void StartWindow::setActPlayer1Highscore(int actHighscore)
{
    if(multiPlayerMode == true)
    {
        matrix[ui->player1BoxMP->currentIndex()][3] = actHighscore;

    }
    else
    {
        matrix[ui->playerBox->currentIndex()][3] = actHighscore;

    }

}

void StartWindow::setActPlayer2Highscore(int actHighscore)
{
    matrix[ui->player2BoxMP->currentIndex()][3] = actHighscore;

}


int StartWindow::getActHighscorePlayer1()
{
    if (multiPlayerMode == true)
    {
        QString _actHighscore = matrix[ui->player1BoxMP->currentIndex()][3];
        return _actHighscore.toInt();
    }
    else
    {
        QString _actHighscore = matrix[ui->playerBox->currentIndex()][3];
        return _actHighscore.toInt();
    }

}

int StartWindow::getActHighscorePlayer2()
{
    QString _actHighscore = matrix[ui->player1BoxMP->currentIndex()][3];
    return _actHighscore.toInt();
}

void StartWindow::on_startButton_clicked()
{
    game->startLevel(ui->levelBox->currentIndex() + 1);
}

void StartWindow::on_exitButton_clicked()
{
    qApp->quit();
    StartWindow::writeFile();
}

void StartWindow::closeEvent(QCloseEvent *)
{
    this->on_exitButton_clicked();
}

void StartWindow::on_addPlayerButton_clicked()
{
    if (playercounter < 10)
    {
        if (multiPlayerMode == true)
        {
            addPlayerDialog playerDialog(this);
            playerDialog.setModal(true);
            playerDialog.exec();
            this->createPlayerBox();
        }
        else{
            addPlayerDialog playerDialog(this);
            playerDialog.setModal(true);
            playerDialog.exec();

            if (firstStart == false)
            {
                this->createPlayerBox();
            }
        }
    }
    else
    {
       QMessageBox::information(this,"Information","Maximale Player-Anzahl erreicht");
    }

}

void StartWindow::on_playerBox_currentIndexChanged(int index)
{
    if(ui->playerBox->count() != 0)
    {
        this->createLevelBox();

    }
}

void StartWindow::createLevelBox()
{
    if (multiPlayerMode == true)
    {
        if(ui->levelBoxMP->count() != 0)
        {
            ui->levelBoxMP->clear();
        }
        for (int i = 1;i <= availableLevel;i++)
        {
            ui->levelBoxMP->addItem("Level" + QString::number(i));
        }
    }

    else
    {
        if(ui->levelBox->count() != 0)
        {
            ui->levelBox->clear();
        }
        int playerlevel = this->getActLevel();
        for (int i = 1;i <= playerlevel;i++)
        {
            ui->levelBox->addItem("Level" + QString::number(i));
        }
    }
}

void StartWindow::createPlayerBox()
{

    if(multiPlayerMode == true)
    {
        if(ui->player1BoxMP->count() != 0)
        {
            ui->player1BoxMP->clear();
        }
        if(ui->player2BoxMP->count() != 0)
        {
            ui->player2BoxMP->clear();
        }
        for (int i = 0;i < playercounter;i++)
        {
            ui->player1BoxMP->addItem(matrix[i][1]);
            ui->player2BoxMP->addItem(matrix[i][1]);
        }
    }
    else
    {
        if(ui->playerBox->count() != 0)
        {
            ui->playerBox->clear();
        }
        for (int i = 0;i < playercounter;i++)
        {
            ui->playerBox->addItem(matrix[i][1]);
        }
    }

}


void StartWindow::checkFile()
{
    QString line;
    QString verzeichnis=QCoreApplication::applicationDirPath();
    verzeichnis.append("/config.txt");
    QFile file(verzeichnis);
    if(file.open(QIODevice::ReadOnly) | QIODevice::Text)
    {

        QTextStream in(&file);
        QString reader = in.readAll();
        QString intCon;
        file.close();
        if (reader.isEmpty())
        {
            firstStart = true;
            this->on_addPlayerButton_clicked();
            firstStart = false;
        }
        else
        {
            this->readLines();
        }
    }
}

void StartWindow::readLines()
{

    QString line;
    QString verzeichnis=QCoreApplication::applicationDirPath();
    verzeichnis.append("/config.txt");
    QFile file(verzeichnis);

    if(file.open(QIODevice::ReadOnly) | QIODevice::Text)
    {

        QTextStream in(&file);
        QString reader = in.readAll();
        QString intCon;
        int pos;
        int lastpos;
        int i,z,j;

        i = 0; //Spalte
        z = 0; // Reihe
        lastpos =1;
        j=0;
        playercounter = 0;

        while(j==0)
        {

            for(i=0;i<4;i++){
                pos = reader.indexOf(":",lastpos);
                matrix[z][i] = reader.mid(lastpos,pos-lastpos);
                lastpos=pos+1;
            }

            // Falls der Index des letzten " gleich der Position von lastpos ist
            // wird j=1 gesetzt und hiermit die while-Schleife unterbrochen.
            playercounter = playercounter + 1;

            if(reader.lastIndexOf("\"") == lastpos)
            {
                j=1;
            }

            else{
                z=z+1;
                lastpos = lastpos + 2;
                // matrix
            }
        }
    }
    file.close();
}

void StartWindow::writeFile()
{
    QString verzeichnis=QCoreApplication::applicationDirPath();
    verzeichnis.append("/config.txt");
    QFile file(verzeichnis);

    if(file.open(QFile::WriteOnly | QFile::Truncate))
    {
        int z;
        QTextStream out(&file);

        for(z=0;z < playercounter;z++)
        {

            out << ":" << matrix[z][0] << ":"<< matrix[z][1] << ":" << matrix[z][2] << ":" << matrix[z][3] << ":" << "\"";
        }
    }
    file.close();
}

void StartWindow::on_backToMainMenuButton_clicked()
{
    if(multiPlayerMode == true)
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else{
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void StartWindow::on_mpModeButton_clicked()
{
    multiPlayerMode = true;
    ui->stackedWidget->setCurrentIndex(1);
    this->createPlayerBox();
    this->createLevelBox();

}

void StartWindow::on_spModeButton_clicked()
{
    multiPlayerMode = false;
    ui->stackedWidget->setCurrentIndex(0);
    this->createPlayerBox();

}

void StartWindow::on_addPlayerMPButton_clicked()
{
    this->on_addPlayerButton_clicked();
}

void StartWindow::on_startMPButton_clicked()
{
    if(getActPlayer1Index() == getActPlayer2Index())
    {
        QMessageBox::information(this,"Fehler","Bitte zwei verschiedene Player auswählen.");
    }
    else
    {
        game->startLevel(ui->levelBoxMP->currentIndex() + 1);
    }
}

void StartWindow::on_highscoreMPButton_clicked()
{
    this->on_highscoreButton_clicked();
}

void StartWindow::on_exitMPButton_clicked()
{
    this->on_exitButton_clicked();
}

//void StartWindow::on_player1BoxMP_currentIndexChanged(int index)
//{
//    this->createLevelBox();
//}

//void StartWindow::on_player2BoxMP_currentIndexChanged(int index)
//{
//    this->createLevelBox();
//}

void StartWindow::on_highscoreButton_clicked()
{
    QStringList header;
    header << "Platz";
    header << "Name";
    header << "Punktzahl";

    ui->stackedWidget->setCurrentIndex(2);
    ui->highscoreViewer->setRowCount(playercounter);
    ui->highscoreViewer->setColumnCount(3);
    ui->highscoreViewer->verticalHeader()->setVisible(false);
    ui->highscoreViewer->horizontalHeader()->setVisible(true);

    ui->highscoreViewer->setHorizontalHeaderLabels(header);
    ui->highscoreViewer->setEditTriggers(QAbstractItemView::NoEditTriggers);
    int i,z,n;
    for(i=0;i<playercounter;i++)
    {
        QString _widgetName = matrix[i][1];
        QString _widgetHighscore = matrix[i][3];
        ui->highscoreViewer->setItem(i,1,new QTableWidgetItem(_widgetName));
        ui->highscoreViewer->setItem(i,2,new QTableWidgetItem(_widgetHighscore));
        //ui->highscoreViewer->sortItems(1,Qt::AscendingOrder);
    }

    //Bubble-Sort
    for(n=playercounter;n>1;n--)
    {

        for(i=0;i<n-1;i++)
        {
            int firstHighscoreINT = ui->highscoreViewer->item(i,2)->text().toInt();
            int compareHighscoreINT = ui->highscoreViewer->item(i+1,2)->text().toInt();

            if (compareHighscoreINT > firstHighscoreINT)
            {
                QString compareHighscoreName = ui->highscoreViewer->item(i+1,1)->text();
                QString compareHighscore = ui->highscoreViewer->item(i+1,2)->text();
                QString firstHighscoreName = ui->highscoreViewer->item(i,1)->text();
                QString firstHighscore = ui->highscoreViewer->item(i,2)->text();
                ui->highscoreViewer->setItem(i,2,new QTableWidgetItem(compareHighscore));
                ui->highscoreViewer->setItem(i,1,new QTableWidgetItem(compareHighscoreName));
                ui->highscoreViewer->setItem(i+1,2,new QTableWidgetItem(firstHighscore));
                ui->highscoreViewer->setItem(i+1,1,new QTableWidgetItem(firstHighscoreName));
            }
        }
    }

    for(z=0;z<playercounter;z++)
    {
        // tbd Hier fehlt eine Logik, die bei zwei gleichen Punktzahlen, den gleichen Platz vergibt.
        QString place = QString::number(z+1);
        ui->highscoreViewer->setItem(z,0,new QTableWidgetItem(place));
    }
}
