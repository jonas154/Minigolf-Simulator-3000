#include "startwindow.h"


StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{

    ui->setupUi(this);

    int availableLevel = 2;
    const int width = 1024;
    const int height = 768;
    this->setFixedSize(width,height);
    this->readLines();

    statusBar()->setFixedHeight(0);

    ui->stackedWidget->setCurrentIndex(0);


    game = new Game(this);

    for (int i = 1;i <= availableLevel;i++)
    {
        ui->levelBox->addItem("Level" + QString::number(i));
    }

    for (int i = 0;i < playercounter;i++)
    {
        ui->playerBox->addItem(matrix[i][1]);
    }


}


StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::on_Start_clicked()
{
    game->startLevel(ui->levelBox->currentIndex() + 1);
}

int StartWindow::getLevel()
{
    int level = ui->levelBox->currentIndex();
    return level;
}

void StartWindow::on_exitButton_clicked()
{
    qApp->quit();
    StartWindow::writeFile();
}

bool StartWindow::fileExists(QString filename){
    if (QFile::exists(filename)){
        return true;
    }else{
        return false;
    }

}

void StartWindow::on_addPlayer_clicked()
{
    addPlayerDialog playerDialog(this);
    playerDialog.setModal(true);
    playerDialog.exec();
}

// Aufbau der Datei: :1:Name:Level:":2:Name:Level:":
void StartWindow::readLines()
{

    QString line;
    QString verzeichnis=QCoreApplication::applicationDirPath();
    verzeichnis.append("/minigolfSimulator3000.txt");

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

            for(i=0;i<3;i++){
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
    verzeichnis.append("/minigolfSimulator3000.txt");
    QFile file(verzeichnis);

    if(file.open(QFile::WriteOnly | QFile::Truncate))
    {
       int z;
       QTextStream out(&file);

       for(z=0;z < playercounter;z++)
       {

            out << ":" << matrix[z][0] << ":"<< matrix[z][1] << ":" << matrix[z][2] << ":" << "\"";
//            out << endl;
       }
    }
    file.close();
}
