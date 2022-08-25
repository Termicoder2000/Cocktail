#include "wk_window.h"

wk_window::wk_window(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Cocktailliste"); // Setzt das Titel eines Fensters.
    close_button = new QPushButton(tr("Schließen"),this);
    close_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    titel = new QLabel(this);
    titel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    titel->setText("Cocktails: ");

    titel2 = new QLabel(this);
    titel2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    titel2->setText("Gesamte Zutaten: ");

    wk = new QLabel(this);
    wk->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    wk_z = new QLabel(this);
    wk_z->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    wk_z->setText("Test");

    vbox = new QVBoxLayout(this);
    vbox->addWidget(titel);
    vbox->addWidget(wk);
    vbox->addWidget(titel2);
    vbox->addWidget(wk_z);
    vbox->addWidget(close_button);
    setLayout(vbox);

    connect(close_button, SIGNAL(clicked()), this, SLOT(close_wk_slot()));
}

void wk_window::close_wk_slot() {
    emit close_wk();
}
