#ifndef WK_WINDOW_H
#define WK_WINDOW_H

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

class wk_window : public QWidget
{
    Q_OBJECT
public:
    explicit wk_window(QWidget *parent = nullptr);
    QLabel *titel;
    QLabel *titel2;
    QLabel *wk;
    QLabel *wk_z;
    QPushButton *close_button;
    QVBoxLayout *vbox;

signals:
    void close_wk(void);

private slots:
    void close_wk_slot(void);

};

#endif // WK_WINDOW_H
