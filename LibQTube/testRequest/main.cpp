#include <QtGui/QApplication>
#include "mainwindow.h"
#include "tuberequester.h"

#include "app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    App app;

    return a.exec();
}
