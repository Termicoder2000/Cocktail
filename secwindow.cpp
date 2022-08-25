#include "secwindow.h"

secwindow::secwindow(QWidget *parent)
    : QWidget{parent}
{
    fenster2 = new add_zutat;

    setWindowTitle("Hinzufügen"); // Setzt das Titel eines Fensters.
    oke = new QPushButton(tr("Hinzufügen"),this);
    oke->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    abbrechen = new QPushButton(tr("Abbrechen"),this);
    abbrechen->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    plus_zutat = new QPushButton(tr("+"),this);
    plus_zutat->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    Name = new QLineEdit(this);
    Anleitung = new QLineEdit(this);
    Name->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    Anleitung->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    Name_txt = new QLabel(this);
    Anleitung_txt = new QLabel(this);
    Name_txt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    Anleitung_txt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    Name_txt->setText("Name");
    Anleitung_txt->setText("Anleitung");

    anz_zutaten = new QLabel(this);
    anz_zutaten->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    anz_zutaten->setText("Zutaten: ");

    eingegebene_zutaten = new QLabel(this);
    eingegebene_zutaten->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    eingegebene_zutaten->setText(" ");

    vbox = new QVBoxLayout;
    hbox = new QHBoxLayout;
    hbox2 = new QHBoxLayout;
    vbox2 = new QVBoxLayout;

    vbox->addWidget(Name_txt);
    vbox->addWidget(Name);
    vbox->addWidget(Anleitung_txt);
    vbox->addWidget(Anleitung);
    hbox2->addWidget(anz_zutaten);
    hbox2->addWidget(plus_zutat);
    vbox->addLayout(hbox2);
    vbox->addLayout(vbox2);
    vbox->addWidget(eingegebene_zutaten);
    hbox->addWidget(abbrechen);
    hbox->addWidget(oke);
    vbox->addLayout(hbox);
    setLayout(vbox);


    connect(oke, SIGNAL(clicked()), this, SLOT(oke_pressed()));
    connect(abbrechen, SIGNAL(clicked()), this, SLOT(abbrechen_pressed()));
    connect(fenster2, SIGNAL(neue_zutat(Zutaten)), this, SLOT(zutat_hinzufuegen(Zutaten)));
    connect(plus_zutat, SIGNAL(clicked()), this, SLOT(zutatenfenster_open()));
    connect(fenster2, SIGNAL(close_window()), this, SLOT(close_window3()));
}


void secwindow::zutatenfenster_open(){
    fenster2->show();
}

void secwindow::close_window3(){
    fenster2->close();
}

void secwindow::zutat_hinzufuegen(Zutaten neu){
    neu_cocktail.zutaten.push_back(neu);
    if (buffer != "")
    {
        buffer = buffer + ", " + neu.name;
    }
    else
    {
        buffer = buffer + neu.name;
    }
    QString buff;
    buff = QString::fromStdString(buffer);
    eingegebene_zutaten->setText(buff);
    fenster2->close();
}

void secwindow::oke_pressed(){
    if((Name->text() == "") || (Anleitung->text() == "") || (neu_cocktail.zutaten.size() == 0))
    {
        QMessageBox msgBox1;
        msgBox1.setWindowTitle("Error 404");
        msgBox1.setText("Es wurde nicht in alle Felder entwas eingegeben oder keine Zutat hinzugefügt!");
        msgBox1.exec();
    }
    else
    {
        QString buffer;
        buffer = Name->text();
        neu_cocktail.name = buffer.toStdString();
        buffer = Anleitung->text();
        neu_cocktail.anleitung = buffer.toStdString();
        Name->clear();
        Anleitung->clear();
        emit neuer_cocktail(neu_cocktail);
    }
}

void secwindow::abbrechen_pressed(){
    Name->clear();
    Anleitung->clear();
    neu_cocktail.zutaten.clear();
    emit close_window();
}



