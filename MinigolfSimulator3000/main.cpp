//DIES IST EIN TESTPROGRAMM, WIRD SPÄTER ERSETZT

#include "level_1.h"
#include <QApplication>
#include "startwindow.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    StartWindow w;
    w.show();


//    //wird später von der Logik ausgeführt
//    Level_1* w = new Level_1;
//    w->show();

    return a.exec();
}
