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

    this->checkFile();

    statusBar()->setFixedHeight(0);


    game = new Game(this);

    this->createPlayerBox();

}
StartWindow::~StartWindow()
{
    delete ui;
}

//Gibt den Namen des ausgewählten Players als QString zurück
QString StartWindow::getActPlayerName()
{
    QString _actPlayerName = matrix[ui->playerBox->currentIndex()][1];
    return _actPlayerName;

}

// Gibt die Index-Nummer (1...10) des ausgewählten Players zurück
int StartWindow::getActPlayerIndex()
{
    QString _actplayerindex = matrix[ui->playerBox->currentIndex()][0];
    return _actplayerindex.toInt();

}
//Gibt die für den ausgewählten Player freigespielten Level zurück
int StartWindow::getActLevel()
{
    QString _actLevel = matrix[ui->playerBox->currentIndex()][2];
    return _actLevel.toInt();

}

// tbd
int StartWindow::getLevel()
{
    int level = ui->levelBox->currentIndex();
    return level;
}


//Hiermit kann man von anderen Klassen einem Player mehr Level freischalten
void StartWindow::setActLevel(int actLevel)
{
    matrix[ui->playerBox->currentIndex()][2] = actLevel;
    ui->levelBox->clear();
    this->createLevelBox();
}

// Hiermit kann man den Highscore des aktuellen Players verändern
void StartWindow::setActHighscore(int actHighscore)
{
    matrix[ui->playerBox->currentIndex()][3] = actHighscore;

}

// Hiermit kann man den Highscore des aktuell ausgewählten Players verändern
int StartWindow::getActHighscore()
{
    QString _actHighscore = matrix[ui->playerBox->currentIndex()][3];
    return _actHighscore.toInt();
}

void StartWindow::on_Start_clicked()
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

void StartWindow::on_addPlayer_clicked()
{

    if (playercounter < 10)
    {
        addPlayerDialog playerDialog(this);
        playerDialog.setModal(true);
        playerDialog.exec();

        if (firstStart == false)
        {
            ui->playerBox->clear();
            this->createPlayerBox();
        }
    }
    else
    {
        //tbd
        //QMessageBox::(this,"Maximale Anzahl an Player ist erreicht.");
    }
}

void StartWindow::on_playerBox_currentIndexChanged(int index)
{
    ui->levelBox->clear();
    this->createLevelBox();
}


void StartWindow::createLevelBox()
{
    int playerlevel = this->getActLevel();
    for (int i = 1;i <= playerlevel;i++)
    {
        ui->levelBox->addItem("Level" + QString::number(i));
    }

}

void StartWindow::createPlayerBox()
{
    for (int i = 0;i < playercounter;i++)
    {
        ui->playerBox->addItem(matrix[i][1]);
    }
}


// Aufbau der Datei: :Index:Name:Freigeschaltene_Levell:Highsccore:":2:Name:Level:":

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
            this->on_addPlayer_clicked();
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

// tbd Für was wird diese Funktion benötigt?
bool StartWindow::fileExists(QString filename){
    if (QFile::exists(filename)){
        return true;
    }else{
        return false;
    }

}

void StartWindow::on_Highscore_clicked()
{
    QStringList header;
    header << "Platz";
    header << "Name";
    header << "Punktzahl";

    ui->stackedWidget->setCurrentIndex(1);
    ui->highscoreViewer->setRowCount(playercounter);
    ui->highscoreViewer->setColumnCount(3);
    ui->highscoreViewer->verticalHeader()->setVisible(false);
    ui->highscoreViewer->horizontalHeader()->setVisible(true);

    ui->highscoreViewer->setHorizontalHeaderLabels(header);
    ui->highscoreViewer->setEditTriggers(false);
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


void StartWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
