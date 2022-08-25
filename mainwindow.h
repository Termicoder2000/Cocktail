#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>
#include <forward_list>
#include <QIODevice>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <QVector2D>
#include <QDataStream>
#include <QString>
#include <QList>
#include <QFile>
#include <QMessageBox>
#include <QVector>
#include "cocktail.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
