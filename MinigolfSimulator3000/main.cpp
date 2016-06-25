#include <QApplication>
#include "startwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWindow* w = new StartWindow;
    w->show();

    return a.exec();
}
