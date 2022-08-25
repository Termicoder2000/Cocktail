#ifndef MEINWIDGET_H
#define MEINWIDGET_H

#include "cocktail.h"
#include <algorithm>
#include <QWidget>
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
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QLCDNumber>
#include <QTableWidget>
#include <QtWidgets/QHeaderView>
#include "secwindow.h"
#include "wk_window.h"


class MeinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MeinWidget(QWidget *parent = nullptr);
    Cocktailliste list;
    std::list <QString> Wunschliste;

    void write_in_table(void);
    void write_in_zutatentabelle(void);

private:
    QPushButton *neuerknopf;
    QPushButton *reset_filter;
    QPushButton *show_wk;
    QVBoxLayout *vbox;
    QVBoxLayout *hvbox1;
    QVBoxLayout *hvbox2;
    QVBoxLayout *hvbox3;
    QHBoxLayout *hbox;
    QHBoxLayout *hbox2;
    QHBoxLayout *hbox3;
    QHBoxLayout *hbox4;
    QTableWidget *tableWidget;
    QTableWidget *Zutatentabelle;
    QTableWidget *Wunschzutaten;
    QTextEdit *tedit;
    QLabel *tablename;
    QLineEdit *ledit;
    QSlider *min_alk;
    QSlider *max_alk;
    secwindow *fenster;
    QLCDNumber *MinAlkLCD;
    QLCDNumber *MaxAlkLCD;
    QLabel *MinText;
    QLabel *MaxText;
    wk_window *wkfenster;

signals:

private slots:

    void hinzufuegen_open(void);
    void close_window2(void);
    void set_min_alk(int);
    void set_max_alk(int);
    void cocktail_hinzufuegen(Cocktail);
    void write_in_wunschzutaten(int,int);
    void reset_filter_slot(void);
    void tabelle_beschrieben(int, int);
    void show_wk_window(void);
    void close_wk_window(void);
};

#endif // MEINWIDGET_H
