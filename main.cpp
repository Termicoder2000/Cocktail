#include "mainwindow.h"
#include "meinwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MeinWidget *meins = new MeinWidget();
    w.setCentralWidget(meins);
    w.show();
    return a.exec();
}
