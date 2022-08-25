//Verwenden der Cocktail cpp!
//Zu beginn des Progammes muss eine Cocktailliste erstellt werden und mit der Methode "liste_lesen_cocktails" die Cocktail Zutaten und Rezepte aus der Textdatei gelesen werden
//Danach kann mit der Methode create_Zutatenliste_gesamt eine Liste erstellt werden, in der alle Zutaten genau einmal aufgelistet werden!
//Wird ein neuer Cocktail hinzugefügt, kann mit der Methode get_alkoholgehalt_cocktail der Alkoholgehalt des Cocktails berechnet werden!
//Wenn neuer Cocktil hinzugfügt wird, muss er (nur eimalig) mit der schreibe_cocktail(cocktail) Funktion das Textdokument geschireben werden

#ifndef COCKTAIL_H
#define COCKTAIL_H

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

using namespace std;

class Zutaten
{
public:
    string name;
    bool fluessig;          //True wenn Flüssig (dann menge in ml, sonst als anzahl)
    int menge;
    int alkoholgehalt;      //Alkoholgehalt der Zutat
};

class gesamtzutatliste
{
public:
    string zutat;
    int anz;
    bool fluessig;
};

class Cocktail
{
public:
    string name;
    string anleitung;
    int alkoholgehalt_cocktail;
    vector<Zutaten> zutaten;
    void print_debug(void);                    //Zu Testzwecken
    void get_alkoholgehalt_cocktail(void);
};

class Warenkorb : public Cocktail
{
public:
    int anz_wk;
};

class Cocktailliste
{
public:
    forward_list<Cocktail> liste;
    forward_list<Cocktail> gefilterte_liste;
    //Nur string, da Zutaten auch in verschiedenen Mengen vorkommen können!
    forward_list<string> zutatenliste_gesamt;
    int alk_min = 0;
    int alk_max = 99;
    vector<string> wunschliste_zutaten;
    void filter_liste(void);
    void liste_lesen_cocktail (void);
    void create_Zutatenliste_gesamt(void);
    void print_Zutatenliste_gesamt(void);       //Zu Testzwecken
    void print_gefilterte_liste(void);         //Zu Testzwecken
    //Filter zur Liste "gefilterte_liste" hinzufügen (Alter Filter bleibt erhalten -> Filter wird zur hinzugefügt, sodass nach beiden optionen gefiltert wird!)
    void filter_cocktailliste_bestehend(string);
    //Filtert die Cocktails neu, sodass nur nach den einem Filter gefiltert wird!
    void filter_cocktailliste_neu(string);
    //Gleichen Filter (nur für Alkoholgehalt)
    //evtl. noch default werte für min gehalt ("0") machen!
    void filter_cocktailliste_bestehend_alk_max(int);
    void filter_cocktailliste_bestehend_alk_min(int);
    void filter_cocktailliste_neu_alk_max(int);
    void filter_cocktailliste_neu_alk_min(int);

    //Warenkorb Objekte und Methoden
    forward_list<Warenkorb> warenkorb;
    forward_list<Zutaten> warenkorb_zutaten;
    //Cocktail hinzufügen (anz + 1)
    void add_wk(Cocktail);
    //Cocktail entfernen (anz -1) -> Falls anz = 0, wird Cocktail aus Warenkorb gelöscht
    void remove_wk(Cocktail);
    //Warenkorb leeren
    void clear_wk();
    //Anz des Cocktails in Warenkorb setzen -> falls 0 wird Cocktail aus Warenkorb gelöscht!
    void set_anz_wk(Cocktail, int);
    void print_wk();            //nur zum Debug!
};

//Cocktail in das Text-File schreiben (im Richtigen Format - ist wichtig zum wieder einlesen!)
void schreibe_cocktail(Cocktail);

//Cocktail aus WK forward_list entfernen (wenn anz = 0) -> Dient als UP für die Methode remove_wk(Cocktail)
bool Null(const Warenkorb&);

#endif // COCKTAIL_H
