#include "pankkiautomaattimainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PankkiautomaattiMainWindow w;
    w.showFullScreen();

    return a.exec();
}
