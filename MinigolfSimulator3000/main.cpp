//DIES IST EIN TESTPROGRAMM, WIRD SPÄTER ERSETZT

#include "level_1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //wird später von der Logik ausgeführt
    Level_1* w = new Level_1;
    w->constructLevel();
    w->show();

    return a.exec();
}
