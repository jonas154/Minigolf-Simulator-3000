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

QString StartWindow::getActPlayerName()
{
    return matrix[ui->playerBox->currentIndex()][1];

}

int StartWindow::getActPlayerIndex()
{
    QString _actplayerindex = matrix[ui->playerBox->currentIndex()][0];
    return _actplayerindex.toInt();

}

int StartWindow::getAvaLevel()
{
    QString _avalevel = matrix[ui->playerBox->currentIndex()][2];
    return _avalevel.toInt();

}

int StartWindow::getLevel()
{
    int level = ui->levelBox->currentIndex();
    return level;
}

void StartWindow::setAvaLevel(int avalevel)
{
    matrix[this->getActPlayerIndex() -1][2] = avalevel;
    ui->levelBox->clear();
    this->createLevelBox();
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
    addPlayerDialog playerDialog(this);
    playerDialog.setModal(true);
    playerDialog.exec();

    if (firstStart == false)
    {
        ui->playerBox->clear();
        this->createPlayerBox();
    }
}

void StartWindow::on_playerBox_currentIndexChanged(int index)
{
    ui->levelBox->clear();
    this->createLevelBox();
}


void StartWindow::createLevelBox()
{
    int playerlevel = this->getAvaLevel();
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

bool StartWindow::fileExists(QString filename){
    if (QFile::exists(filename)){
        return true;
    }else{
        return false;
    }

}
