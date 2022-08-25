#ifndef ADD_ZUTAT_H
#define ADD_ZUTAT_H

#include <QWidget>
#include "cocktail.h"
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

class add_zutat : public QWidget
{
    Q_OBJECT
public:
    explicit add_zutat(QWidget *parent = nullptr);
    QPushButton *oke;
    QPushButton *abbrechen;

    QHBoxLayout *hbox;
    QHBoxLayout *hbox2;
    QVBoxLayout *vbox;
    QVBoxLayout *vbox1;
    QVBoxLayout *vbox2;
    QVBoxLayout *vbox3;
    QVBoxLayout *vbox4;

    QLabel *zutat;
    QLabel *fluessig;
    QLabel *menge;
    QLabel *alkoholgehalt;

    QLineEdit *zutat_ein;
    QLineEdit *fluessig_ein;
    QLineEdit *menge_ein;
    QLineEdit *alkoholgehalt_ein;

signals:
    void neue_zutat(Zutaten);
    void close_window(void);

private slots:
    void oke_pressed_2();
    void abbrechen_pressed_2();
};

#endif // ADD_ZUTAT_H
