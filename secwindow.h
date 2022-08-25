#ifndef SECWINDOW_H
#define SECWINDOW_H

#include "cocktail.h"
#include <QWidget>
#include <string.h>
#include <forward_list>
#include <vector>
#include <QIODevice>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <QVector2D>
#include <QDataStream>
#include <QString>
#include <QList>
#include <QFile>
#include <QVector>
#include "cocktail.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QSlider>
#include <QMessageBox>
#include <QApplication>
#include <QSpinBox>
#include "add_zutat.h"

class secwindow : public QWidget
{
    Q_OBJECT
public:
    explicit secwindow(QWidget *parent = nullptr);

    QPushButton *oke;
    QPushButton *abbrechen;
    QHBoxLayout *hbox;
    QHBoxLayout *hbox2;
    QVBoxLayout *vbox;
    QVBoxLayout *vbox2;
    QLineEdit *Name;
    QLineEdit *Anleitung;
    QLabel *Name_txt;
    QLabel *Anleitung_txt;
    QLabel *anz_zutaten;
    QPushButton *plus_zutat;
    add_zutat *fenster2;
    QLabel *eingegebene_zutaten;

    string buffer;
    Cocktail neu_cocktail;


signals:
    void neuer_cocktail(Cocktail);
    void close_window(void);

private slots:
    void oke_pressed();
    void abbrechen_pressed();
    void zutat_hinzufuegen(Zutaten);
    void zutatenfenster_open();
    void close_window3(void);
    //void spinbox_value(int);
};

#endif // SECWINDOW_H
