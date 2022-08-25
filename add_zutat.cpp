#include "add_zutat.h"

add_zutat::add_zutat(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Zutat Hinzufügen"); // Setzt das Titel eines Fensters.
    oke = new QPushButton(tr("Hinzufügen"),this);
    oke->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    abbrechen = new QPushButton(tr("Abbrechen"),this);
    abbrechen->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    zutat = new QLabel(this);
    fluessig = new QLabel(this);
    menge = new QLabel(this);
    alkoholgehalt = new QLabel(this);
    zutat->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    fluessig->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    menge->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    alkoholgehalt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    zutat->setText("Name:");
    fluessig->setText("Flüssig? [Ja/Nein]");
    menge->setText("Menge [ml]:");
    alkoholgehalt->setText("Alkoholgehalt [%]");

    zutat_ein = new QLineEdit(this);
    fluessig_ein = new QLineEdit(this);
    menge_ein = new QLineEdit(this);
    alkoholgehalt_ein = new QLineEdit(this);

    vbox = new QVBoxLayout;
    vbox1 = new QVBoxLayout;
    vbox2 = new QVBoxLayout;
    vbox3 = new QVBoxLayout;
    vbox4 = new QVBoxLayout;
    hbox = new QHBoxLayout;
    hbox2 = new QHBoxLayout;

    vbox1->addWidget(zutat);
    vbox1->addWidget(zutat_ein);
    vbox2->addWidget(fluessig);
    vbox2->addWidget(fluessig_ein);
    vbox3->addWidget(menge);
    vbox3->addWidget(menge_ein);
    vbox4->addWidget(alkoholgehalt);
    vbox4->addWidget(alkoholgehalt_ein);

    hbox2->addLayout(vbox1);
    hbox2->addLayout(vbox2);
    hbox2->addLayout(vbox3);
    hbox2->addLayout(vbox4);

    hbox->addWidget(abbrechen);
    hbox->addWidget(oke);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox);
    setLayout(vbox);

    connect(oke, SIGNAL(clicked()), this, SLOT(oke_pressed_2()));
    connect(abbrechen, SIGNAL(clicked()), this, SLOT(abbrechen_pressed_2()));
}

void add_zutat::oke_pressed_2(){
    bool ist_zahl = true;
    QString buffer;
    string buffer_std;
    //Kontrolle ob menge_ein und alkoholgehalt_ein eiine Zahl ist!
    buffer = menge_ein->text();
    buffer_std = buffer.toStdString();
    for (char const &c : buffer_std) {
        if (std::isdigit(c) == 0) ist_zahl = false;
    }
    buffer = alkoholgehalt_ein->text();
    buffer_std = buffer.toStdString();
    for (char const &c : buffer_std) {
        if (std::isdigit(c) == 0) ist_zahl = false;
    }

    if((zutat_ein->text() == "") || (fluessig_ein->text() == "") || (!ist_zahl))
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error 404");
        msgBox.setText("Es wurde nicht in alle Felder etwas oder in die Felder Menge und Alkoholgehalt keine Zahlen eingegeben!");
        msgBox.exec();
    }
    else
    {
        Zutaten neu;
        buffer = zutat_ein->text();
        neu.name = buffer.toStdString();
        buffer = fluessig_ein->text();
        if((buffer == "ja") || (buffer == "Ja"))
        {
            neu.fluessig = true;
        }
        else
        {
            neu.fluessig = false;
        }
        buffer = menge_ein->text();
        buffer_std = buffer.toStdString();
        neu.menge = stoi(buffer_std);
        buffer = alkoholgehalt_ein->text();
        buffer_std = buffer.toStdString();
        neu.alkoholgehalt = stoi(buffer_std);

        zutat_ein->clear();
        fluessig_ein->setText("");
        menge_ein->setText("");
        alkoholgehalt_ein->setText("");
        emit neue_zutat(neu);
    }
}

void add_zutat::abbrechen_pressed_2(){
    zutat_ein->setText("");
    fluessig_ein->setText("");
    menge_ein->setText("");
    alkoholgehalt_ein->setText("");
    emit close_window();
}
