#include "meinwidget.h"
#include "cocktail.h"
#include <QDialog>

MeinWidget::MeinWidget(QWidget *parent)
    : QWidget{parent}
{
    fenster = new secwindow;
    wkfenster = new wk_window;
    list.liste_lesen_cocktail();
    list.create_Zutatenliste_gesamt();
    list.filter_cocktailliste_neu_alk_min(0);           //um die "Gesamtliste in die gefilterte Liste zu kopieren!"
    // die Liste heißt: list.zutatenliste_gesamt


    //Größenordnung
    QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);

    //Tabellen Label

    tablename = new QLabel(this);
    tablename->setText("Cocktailliste");
    tablename->setDisabled(true);
    tablename->setAlignment(Qt::AlignCenter);
    tablename->setGeometry(QRect(160, 530, 64, 21));
    sizePolicy2.setHeightForWidth(tablename->sizePolicy().hasHeightForWidth());
    tablename->setSizePolicy(sizePolicy2);
    tablename->setStyleSheet(QString::fromUtf8("font: 700 12pt \"72 Condensed\";\n"
"gridline-color: rgb(170, 170, 255);\n"
"background-color: rgb(170, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));
    tablename->setOpenExternalLinks(false);

    //Cocktail Tabelle erstellen:
    tableWidget = new QTableWidget(this);
    if (tableWidget->columnCount() < 3)
        tableWidget->setColumnCount(3);
    QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
    QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
    QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
    tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // Hier ist eigentlich die Anzahl an Zeilen
    //if (tableWidget->rowCount() < 1)
    //    tableWidget->setRowCount(CockAnzahl);


    QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
    tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
    tableWidget->verticalHeader()->count();
    //Test
    QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
    ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
    QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
    ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Alkoholgehalt", nullptr));
    QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
    ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Anzahl", nullptr));
    /*QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
    ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Nils", "1"));*/
    tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
    tableWidget->setGeometry(QRect(20, 10, 431, 281));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    //sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());

    tableWidget->setSizePolicy(sizePolicy1);
    tableWidget->setMinimumSize(QSize(271, 0));
    tableWidget->setMouseTracking(true);
    tableWidget->setContextMenuPolicy(Qt::NoContextMenu);
    tableWidget->setStyleSheet(QString::fromUtf8(";\n"
"background-color: rgb(255, 155, 130);\n"
"selection-color: rgb(170, 170, 255);\n"
"font: 700 11pt \"72 Condensed\";\n"
"color: rgb(0, 0, 0);"));
    tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
    tableWidget->setSortingEnabled(true);
    tableWidget->horizontalHeader()->setVisible(true);
    tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
    tableWidget->horizontalHeader()->setHighlightSections(true);
    tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
    tableWidget->horizontalHeader()->setStretchLastSection(false);
    tableWidget->verticalHeader()->setCascadingSectionResizes(false);
    tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));


    //
    //Zutatentabelle erstellen:
    Zutatentabelle = new QTableWidget(this);
    if (Zutatentabelle->columnCount() < 1)
        Zutatentabelle->setColumnCount(1);
    QTableWidgetItem *__qzutatentabelleitem = new QTableWidgetItem();
    Zutatentabelle->setHorizontalHeaderItem(0, __qzutatentabelleitem);
    Zutatentabelle->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QTableWidgetItem *___qzutatentabelleitem = Zutatentabelle->horizontalHeaderItem(0);
    ___qzutatentabelleitem->setText(QCoreApplication::translate("MainWindow", "Alle Zutaten", nullptr));
    Zutatentabelle->setObjectName(QString::fromUtf8("Zutatentabelle"));
    Zutatentabelle->setGeometry(QRect(20, 10, 431, 281));
    Zutatentabelle->setSizePolicy(sizePolicy1);
    Zutatentabelle->setMinimumSize(QSize(271, 0));
    Zutatentabelle->setMouseTracking(true);
    Zutatentabelle->setContextMenuPolicy(Qt::NoContextMenu);
    Zutatentabelle->setStyleSheet(QString::fromUtf8(";\n"
"background-color: rgb(255, 155, 130);\n"
"selection-color: rgb(170, 170, 255);\n"
"font: 700 11pt \"72 Condensed\";\n"
"color: rgb(0, 0, 0);"));
    Zutatentabelle->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
    Zutatentabelle->setSortingEnabled(true);
    Zutatentabelle->horizontalHeader()->setVisible(true);
    Zutatentabelle->horizontalHeader()->setCascadingSectionResizes(false);
    Zutatentabelle->horizontalHeader()->setHighlightSections(true);
    Zutatentabelle->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
    Zutatentabelle->horizontalHeader()->setStretchLastSection(false);
    Zutatentabelle->verticalHeader()->setCascadingSectionResizes(false);
    Zutatentabelle->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
    Zutatentabelle->setEditTriggers(QAbstractItemView::NoEditTriggers); //Das Externe Editieren der Felder ausschalten

    //Wunschzutatentabelle
    Wunschzutaten = new QTableWidget(this);
    if (Wunschzutaten->columnCount() < 1)
        Wunschzutaten->setColumnCount(1);
    QTableWidgetItem *__qwunschitem = new QTableWidgetItem();
    Wunschzutaten->setHorizontalHeaderItem(0, __qwunschitem);
    Wunschzutaten->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QTableWidgetItem *___qwunschitem = Wunschzutaten->horizontalHeaderItem(0);
    ___qwunschitem->setText(QCoreApplication::translate("MainWindow", "Wunschzutaten", nullptr));
    Wunschzutaten->setObjectName(QString::fromUtf8("Zutatentabelle"));
    Wunschzutaten->setGeometry(QRect(20, 10, 431, 281));
    Wunschzutaten->setSizePolicy(sizePolicy1);
    Wunschzutaten->setMinimumSize(QSize(271, 0));
    Wunschzutaten->setMouseTracking(true);
    Wunschzutaten->setContextMenuPolicy(Qt::NoContextMenu);
    Wunschzutaten->setStyleSheet(QString::fromUtf8(";\n"
"background-color: rgb(255, 155, 130);\n"
"selection-color: rgb(170, 170, 255);\n"
"font: 700 11pt \"72 Condensed\";\n"
"color: rgb(0, 0, 0);"));
    Wunschzutaten->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
    Wunschzutaten->setSortingEnabled(true);
    Wunschzutaten->horizontalHeader()->setVisible(true);
    Wunschzutaten->horizontalHeader()->setCascadingSectionResizes(false);
    Wunschzutaten->horizontalHeader()->setHighlightSections(true);
    Wunschzutaten->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
    Wunschzutaten->horizontalHeader()->setStretchLastSection(false);
    Wunschzutaten->verticalHeader()->setCascadingSectionResizes(false);
    Wunschzutaten->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
    Wunschzutaten->setEditTriggers(QAbstractItemView::NoEditTriggers);


    //QPushButton *neuerknopf = new QPushButton(this);
    neuerknopf = new QPushButton("+ Cocktail hinzufügen", this);
    reset_filter = new QPushButton("Wunschliste zurücksetzen", this);
    show_wk = new QPushButton("Cocktailliste anzeigen", this);


    min_alk = new QSlider(Qt::Horizontal);
    min_alk->setTickPosition(QSlider::TicksBelow);
    min_alk->setTickInterval(1);
    min_alk->setSingleStep(1);

    MinAlkLCD = new QLCDNumber(this);
    MinAlkLCD->setObjectName(QString::fromUtf8("MinAlkLCD"));
    MinAlkLCD->setGeometry(QRect(160, 530, 64, 21));
    sizePolicy2.setHeightForWidth(MinAlkLCD->sizePolicy().hasHeightForWidth());
    MinAlkLCD->setSizePolicy(sizePolicy2);
    MinAlkLCD->setAutoFillBackground(false);
    MinAlkLCD->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"gridline-color: rgb(170, 170, 255);"));

    MinText = new QLabel(this);
    MinText->setText("Minimum Alkoholwert");
    MinText->setAlignment(Qt::AlignCenter);
    MinText->setGeometry(QRect(160, 530, 64, 21));
    sizePolicy2.setHeightForWidth(MinText->sizePolicy().hasHeightForWidth());
    MinText->setSizePolicy(sizePolicy2);
    MinText->setStyleSheet(QString::fromUtf8("font: 700 12pt \"72 Condensed\";\n"
"gridline-color: rgb(170, 170, 255);\n"
"background-color: rgb(170, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));
    MinText->setOpenExternalLinks(false);

    MaxText = new QLabel(this);
    MaxText->setText("Maximum Alkoholwert");
    MaxText->setAlignment(Qt::AlignCenter);
    MaxText->setGeometry(QRect(160, 530, 64, 21));
    sizePolicy2.setHeightForWidth(MaxText->sizePolicy().hasHeightForWidth());
    MaxText->setSizePolicy(sizePolicy2);
    MaxText->setGeometry(QRect(30, 530, 131, 21));
    MaxText->setStyleSheet(QString::fromUtf8("font: 700 12pt \"72 Condensed\";\n"
"gridline-color: rgb(170, 170, 255);\n"
"background-color: rgb(170, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-color: rgb(0, 0, 0);"));
    MaxText->setOpenExternalLinks(false);

    max_alk = new QSlider(Qt::Horizontal);
    max_alk->setTickPosition(QSlider::TicksBelow);
    max_alk->setTickInterval(1);
    max_alk->setSingleStep(1);
    max_alk->setSliderPosition (99);

    MaxAlkLCD = new QLCDNumber(this);
    MaxAlkLCD->setObjectName(QString::fromUtf8("MinAlkLCD"));
    MaxAlkLCD->setGeometry(QRect(160, 530, 64, 21));
    sizePolicy2.setHeightForWidth(MaxAlkLCD->sizePolicy().hasHeightForWidth());
    MaxAlkLCD->setSizePolicy(sizePolicy2);
    MaxAlkLCD->setAutoFillBackground(false);
    MaxAlkLCD->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"gridline-color: rgb(170, 170, 255);"));
    MaxAlkLCD->display(99);

    // erstellen der Layouts.
    // Allgemeine Box
    vbox = new QVBoxLayout;

    //Erste Horizontale Box + innere Boxen
    hbox = new QHBoxLayout;
    vbox->addLayout(hbox);

    hvbox1 = new QVBoxLayout;
    hvbox1->addWidget(tablename);
    hvbox1->addWidget(tableWidget);
    hvbox2 = new QVBoxLayout;
    hvbox3 = new QVBoxLayout;
        // in hbox hinzufügen
        hbox->addLayout(hvbox1);
        hbox->addLayout(hvbox2);
        hbox->addLayout(hvbox3);
        // Widgets in die hbox
        hvbox3->addWidget(show_wk);
        hvbox3->addWidget(neuerknopf);
        hvbox3->addWidget(reset_filter);
        hvbox3->addWidget(Zutatentabelle);
        hvbox3->addWidget(Wunschzutaten);


    // Slider+Anzeige Boxen
    hbox2 = new QHBoxLayout;
    hbox3 = new QHBoxLayout;
    hbox4 = new QHBoxLayout;
    vbox->addLayout(hbox4);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);


    //hbox 4 (Textfeld)
    hbox4->addWidget(MinText);
    hbox4->addSpacing(30);
    hbox4->addWidget(MaxText);
    //hbox 2 (LCDs)
    hbox2->addWidget(MinAlkLCD);
    hbox2->addSpacing(30);
    hbox2->addWidget(MaxAlkLCD);

    hbox3->addWidget(min_alk);
    hbox3->addSpacing(30);
    hbox3->addWidget(max_alk);
    setLayout(vbox);

    QObject::connect(min_alk, &QSlider::valueChanged,MinAlkLCD,qOverload<int>(&QLCDNumber::display ));
    QObject::connect(max_alk, &QSlider::valueChanged,MaxAlkLCD,qOverload<int>(&QLCDNumber::display ));
    connect(neuerknopf, SIGNAL(clicked()), this, SLOT(hinzufuegen_open()));
    connect(min_alk, SIGNAL(valueChanged(int)), this, SLOT(set_min_alk(int)));
    connect(max_alk, SIGNAL(valueChanged(int)), this, SLOT(set_max_alk(int)));
    connect(fenster, SIGNAL(neuer_cocktail(Cocktail)), this, SLOT(cocktail_hinzufuegen(Cocktail)));
    connect(Zutatentabelle, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(write_in_wunschzutaten(int,int)));
    connect(fenster, SIGNAL(close_window()), this, SLOT(close_window2()));
    connect(reset_filter, SIGNAL(clicked()), this, SLOT(reset_filter_slot()));
    connect(tableWidget, SIGNAL(cellChanged(int, int)), this, SLOT(tabelle_beschrieben(int, int)));
    connect(show_wk, SIGNAL(clicked()), this, SLOT(show_wk_window()));
    connect(wkfenster, SIGNAL(close_wk()), this, SLOT(close_wk_window()));

    list.print_Zutatenliste_gesamt();
    write_in_table();
    write_in_zutatentabelle();
}

void MeinWidget::close_wk_window(){
    wkfenster->close();
}

void MeinWidget::show_wk_window(){
    string buffer = "";
    for(auto it = list.warenkorb.begin(); it != list.warenkorb.end(); it++)
    {
        if(buffer == "")
        {
            buffer = buffer + it->name + " Anzahl: " + to_string(it->anz_wk) + " Anleitung: " + it->anleitung + " ";
        }
        else
        {
            buffer = buffer + "/ " + it->name + " Azahl: " + to_string(it->anz_wk) + " Anleitung: " + it->anleitung + " ";
        }
    }
    wkfenster->wk->setText(QString::fromStdString(buffer));
    vector<gesamtzutatliste> zutat;
    for(auto it = list.warenkorb.begin(); it != list.warenkorb.end(); it++)
    {
        for(auto iter = it->zutaten.begin(); iter != it->zutaten.end(); iter++)
        {
            bool vorhanden = false;
            for(auto i = zutat.begin(); i != zutat.end(); i++)
            {
                if(i->zutat == iter->name)        //Zutat in Liste schon vorhanden!
                {
                    i->anz = i->anz + (it->anz_wk * iter->menge);
                    vorhanden = true;
                }
            }
            if(!vorhanden)
            {
                zutat.push_back({iter->name, (it->anz_wk * iter->menge), iter->fluessig});
            }
        }
    }
    buffer = "";
    for(auto it = zutat.begin(); it != zutat.end(); it++)
    {
        if(buffer == "")
        {
            if(it->fluessig)
            {
                buffer = buffer + to_string(it->anz) + " ml " + it->zutat;
            }
            else
            {
                buffer = buffer + to_string(it->anz) + " St " + it->zutat;
            }
        }
        else
        {
            if(it->fluessig)
            {
                buffer = buffer + " / " + to_string(it->anz) + " ml " + it->zutat;
            }
            else
            {
                buffer = buffer + " / " + to_string(it->anz) + " St " + it->zutat;
            }
        }

    }
    wkfenster->wk_z->setText(QString::fromStdString(buffer));
    wkfenster->show();
}

void MeinWidget::tabelle_beschrieben(int row, int column){
    if(column > 1)
    {
        QString buffer = tableWidget->item(row,column)->text();
        string buff = buffer.toStdString();
        //Kontrolle, ob Zahl einigegeben wurde!
        bool ist_zahl = true;
        for (char const &c : buff) {
            if (std::isdigit(c) == 0) ist_zahl = false;
        }

        if(ist_zahl)
        {
            int a = stoi(buff);
            buffer = tableWidget->item(row, 0)->text();
            for(auto it = list.liste.begin(); it != list.liste.end(); it++)
            {
                if(buffer.toStdString() == it->name)
                {
                    list.set_anz_wk(*it,a);
                }
            }
        }
        else
        {
            QTableWidgetItem *pCell;
            pCell = new QTableWidgetItem;
            pCell->setText("");
            tableWidget->setItem(row,column,pCell);
        }
        qDebug() << tableWidget->item(row,column)->text() << '\n';
    }
}

void MeinWidget::reset_filter_slot(){
    list.wunschliste_zutaten.clear();
    list.filter_liste();
    Wunschzutaten->setRowCount(0);
    Wunschliste.clear();
    write_in_table();
}

void MeinWidget::close_window2(void) {
    fenster->close();
}

void MeinWidget::hinzufuegen_open(void) {
    fenster->neu_cocktail.zutaten.clear();
    fenster->eingegebene_zutaten->setText("");
    fenster->show();
}

void MeinWidget::set_min_alk(int a) {
    max_alk->setMinimum(a);
    qDebug() << a << '\n';
    list.alk_min = a;
    list.filter_liste();
    write_in_table();
}

void MeinWidget::set_max_alk(int a) {
    qDebug() << a << '\n';
    list.alk_max = a;
    list.filter_liste();
    write_in_table();
}

//Übergabe Funktioniert!
void MeinWidget::cocktail_hinzufuegen(Cocktail neu) {
    neu.get_alkoholgehalt_cocktail();
    bool schon_vorhanden = false;
    for(auto it = list.liste.begin(); it != list.liste.end(); it++)
    {
        if(neu.name == it->name)
        {
            schon_vorhanden = true;
        }
    }

    if (schon_vorhanden)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error 404");
        msgBox.setText("Cocktail schon vorhanden! - Kann nur unter einem anderen Namen abgespeichert werden!");
        msgBox.exec();
    }
    else
    {
        list.liste.push_front(neu);
        schreibe_cocktail(neu);
        list.create_Zutatenliste_gesamt();
        list.filter_liste();
        write_in_table();
        write_in_zutatentabelle();
        neu.print_debug();
    }
    fenster->close();
}

//Daten in Tabelle schreiben
void MeinWidget::write_in_table(void){
    // Anzahl der Zeilen anpassen
    tableWidget->setRowCount(distance(list.gefilterte_liste.begin(), list.gefilterte_liste.end()));
    //Inhalt der Zellen anpassen
    int r=0;
    for (auto iter = list.gefilterte_liste.begin(); iter != list.gefilterte_liste.end(); iter++){

        for (int c= 0; c<2; c++){

            QTableWidgetItem *pCell = tableWidget->item(r, c);
                        if(!pCell)
                        {
                            pCell = new QTableWidgetItem;
                            tableWidget->setItem(r, c, pCell);
                        }
            if (c == 0){
              pCell->setText(QString::fromStdString(iter->name));
            }
            else{
                ;
                pCell->setText(QString::fromStdString(to_string(iter->alkoholgehalt_cocktail)));
            }
        }
        r++;
    }

}

void MeinWidget::write_in_zutatentabelle(void){
    // Anzahl der Zeilen anpassen
    Zutatentabelle->setRowCount(distance(list.zutatenliste_gesamt.begin(), list.zutatenliste_gesamt.end()));
    //Inhalt der Zellen anpassen
    int r=0;
    int c= 0;
    for (auto iter = list.zutatenliste_gesamt.begin(); iter != list.zutatenliste_gesamt.end(); iter++){

            QTableWidgetItem *pCell = Zutatentabelle->item(r, c);
                        if(!pCell)
                        {
                            pCell = new QTableWidgetItem;
                            Zutatentabelle->setItem(r, c, pCell);
                        }

             pCell->setText(QString::fromStdString(*iter));
            r++;
        }

}

void MeinWidget::write_in_wunschzutaten(int a, int b){
    QString itabtext = Zutatentabelle->item(a,b)->text();
    // Create a list Iterator
    std::list<QString>::iterator it;
    // Fetch the iterator of element with value 'the'
    it = std::find(Wunschliste.begin(), Wunschliste.end(), itabtext);
    // Check if iterator points to end or not
    if(it != Wunschliste.end()){}
        //Existiert schon in Liste, mache nichts
    else{
        Wunschzutaten->setRowCount(Wunschzutaten->rowCount()+1);
        Wunschliste.push_front(itabtext);
        QTableWidgetItem *pCell = Wunschzutaten->item(67, 1);
                if(!pCell)
                {
                    pCell = new QTableWidgetItem;
                    Wunschzutaten->setItem(Wunschzutaten->rowCount()-1, b, pCell);
                }
        pCell->setText(itabtext);
    }

    list.wunschliste_zutaten.clear();
    for(auto it = Wunschliste.begin(); it != Wunschliste.end(); it++)
    {
        list.wunschliste_zutaten.push_back(it->toStdString());
    }
    list.filter_liste();
    write_in_table();
}

