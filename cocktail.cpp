#include "cocktail.h"

//Funktion, um Cocktail in Textdokument zu schreiben! (muss einmal ausgeführt werden, wenn vom Nutzer neue Cocktails hinzugefügt werden!)
void schreibe_cocktail(Cocktail a){
    ofstream f("Liste.txt", ios_base::app);
    if (!f)
    {
        qDebug() << "Fehler beim Öffnen der Datei";
    }
    else
    {
        f << a.name << '\n';
        f << a.alkoholgehalt_cocktail << '\n';
        f << a.anleitung << '\n';
        for (auto iter = a.zutaten.begin(); iter != a.zutaten.end(); iter++)
        {
            f << iter->name << '\n' << iter->fluessig << '\n' << iter->menge << '\n' << iter->alkoholgehalt << '\n';
        }
        f << '\n';
    }
    //Datei wieder schließen, um nächsten Zugriff nciht zu verhindern!
    f.close();
}


//Methode um Alkoholgehalt des gesamten Cocktails zu berechnen! -> muss immer beim hinzufügen gemacht werden
//damit der Wert auch in Liste abgespeicher werden kann!
void Cocktail::get_alkoholgehalt_cocktail(void) {
    double menge_getraenk = 0;
    double menge_alkohol = 0;
    for (auto it = this->zutaten.begin(); it != this->zutaten.end(); it++)
    {
        if(it->fluessig)
        {
            menge_getraenk = it->menge + menge_getraenk;
            menge_alkohol = menge_alkohol + (double(it->menge) * (double(it->alkoholgehalt)/100));
        }
    }
    this->alkoholgehalt_cocktail = int((menge_alkohol/menge_getraenk)*100);
}


//Methode, um alle Cocktails aus Textdokument einzulesen (muss zu beginn einmal ausgeführt werden!)
void Cocktailliste::liste_lesen_cocktail(void) {
    this->liste.clear();
    ifstream f("Liste.txt");
    if (!f) {
        qDebug() << "Fehler!" << '\n';
    }
    else
    {
        string line;
        while (getline(f, line))
        {
            Cocktail neu;
            neu.name = line;
            getline(f, line);
            //Der "test" string wird benötigt, da die stio funktion nicht direkt den line string verwenden kann!
            string test;
            test = line;
            neu.alkoholgehalt_cocktail = stoi(test);
            getline(f, line);
            neu.anleitung = line;
            vector<string> buffer;
            bool fluessig;
            int menge;
            int alkoholgehalt;
            for (int i = 0; i < 10; i++)
            {
               buffer.push_back(" ");
            }
            getline(f,line);
            while(line != "")
            {
                int anz_zutaten = 0;
                for (int i = 0; i < 4; i++)
                {
                    buffer.at(i) = line;
                    getline(f,line);
                    qDebug() << QString::fromStdString(line) << '\n';
                }
                if (buffer.at(1) == "1")
                {
                    fluessig = true;
                }
                else
                {
                    fluessig = false;
                }
                menge = stoi(buffer.at(2));
                alkoholgehalt = stoi(buffer.at(3));
                neu.zutaten.push_back({buffer.at(0), fluessig, menge, alkoholgehalt});
                anz_zutaten++;
            }
            //Liste scheind endlos lang zu sein!!
            this->liste.push_front(neu);
        }
    }
    //Datei wieder schließen, um nächsten Zugriff nicht zu blockieren
    f.close();

    for(auto it = this->liste.begin(); it != this->liste.end(); it++)
    {
        it->get_alkoholgehalt_cocktail();
    }
}


//Cocktail in qDebug ausgeben! (zu Testzwecken!)
void Cocktail::print_debug(void){
    qDebug() << "Cocktailname: " << QString::fromStdString(this->name) << '\n';
    qDebug() << "Anleitung: " << QString::fromStdString(this->anleitung) << '\n';
    qDebug() << "Cocktail gesamt Alkoholgehalt: " << this->alkoholgehalt_cocktail << '\n';
    int anz = 0;
    for (auto it = this->zutaten.begin(); it < this->zutaten.end(); it++)
    {
        qDebug() << "Zutat " << anz << ":" << QString::fromStdString(this->zutaten.at(anz).name) << " Fluessig: " << this->zutaten.at(anz).fluessig << " Menge: " << this->zutaten.at(anz).menge << " Alkoholgehalt: " << this->zutaten.at(anz).alkoholgehalt << '\n';
        anz++;
    }
    qDebug() << '\n';
}


//Methode der Klasse Cocktailliste, welche die zuvor gefüllte Liste an Cocktails (forward_list der Klasse Cocktais in der Klasse Cocktailliste)
//nach den Zuaten durchsucht und alle in einer neuen forward_list des Objekts Cocktailliste Zutaten speichert und dabei doppelt vorkommende Zutaten nur einmal aufnimmt
void Cocktailliste::create_Zutatenliste_gesamt(void){
    //Liste beinhaltet Cocktails -> iter ist ein pointer auf Cocktails!!
    for(auto iter = this->liste.begin(); iter != this->liste.end(); iter++)
    {
        //it zeigt auf Zutaten, da iter auf Coktails zeigt, welche Zutaten beinhalten!
        for(auto it = iter->zutaten.begin(); it != iter->zutaten.end(); it++)
        {
            bool schon_vorhanden = false;
            for(auto iterator = this->zutatenliste_gesamt.begin(); iterator != this->zutatenliste_gesamt.end(); iterator++)
            {   //Schauen, ob Zutat schon in Zutatenliste
                if(it->name == *iterator)
                {
                    schon_vorhanden = true;
                }
            }
            if (!(schon_vorhanden))
            {   //Zutat noch nicht in Liste -> Hinzufügen!
                this->zutatenliste_gesamt.push_front(it->name);
            }
        }
    }
}


//Zu Testzwekcen, um Zutantenliste über qDegub anzeigen lassen zu können!
void Cocktailliste::print_Zutatenliste_gesamt(void){
    for(auto it = this->zutatenliste_gesamt.begin(); it != this->zutatenliste_gesamt.end(); it++)
    {
        qDebug() <<  QString::fromStdString(*it) << '\n';
    }
}


//Zu Testzwekcen, um gefilterte liste über qDegub anzeigen lassen zu können!
void Cocktailliste::print_gefilterte_liste(void){
    for(auto it = this->gefilterte_liste.begin(); it != this->gefilterte_liste.end(); it++)
    {
        qDebug() <<  QString::fromStdString(it->name) << '\n';
    }
}


//Filter zu dem schon bestehenden Filter hinzufügen, sodass gefilterte_liste weiter verkleinerd wird!
void Cocktailliste::filter_cocktailliste_bestehend(string Zutat) {
    forward_list<Cocktail> buffer;
    for (auto iter = this->gefilterte_liste.begin(); iter != this->gefilterte_liste.end(); iter++)
    {
        for(auto it = iter->zutaten.begin(); it != iter->zutaten.end(); it++)
        {
            if (Zutat == it->name)
            {
                buffer.push_front(*iter);
            }
        }
    }
    this->gefilterte_liste.clear();
    this->gefilterte_liste = buffer;
}


//Neuer (und vorerst einziger - außer es wird danach einer mit "..._bestehend" zugefügt)
void Cocktailliste::filter_cocktailliste_neu(string Zutat) {
    this->gefilterte_liste.clear();         //Liste leeren
    for (auto iter = this->liste.begin(); iter != this->liste.end(); iter++)
    {
        for(auto it = iter->zutaten.begin(); it != iter->zutaten.end(); it++)
        {
            if (Zutat == it->name)
            {
                this->gefilterte_liste.push_front(*iter);
            }
        }
    }
}


// (Alkohol) Filter zu dem schon bestehenden Filter hinzufügen, sodass gefilterte_liste weiter verkleinerd wird!
void Cocktailliste::filter_cocktailliste_bestehend_alk_max(int alk_max) {
    forward_list<Cocktail> buffer;
    for (auto iter = this->gefilterte_liste.begin(); iter != this->gefilterte_liste.end(); iter++)
    {
        if(iter->alkoholgehalt_cocktail <= alk_max)
        {
            buffer.push_front(*iter);
        }
    }
    this->gefilterte_liste.clear();
    this->gefilterte_liste = buffer;
}
void Cocktailliste::filter_cocktailliste_bestehend_alk_min(int alk_min) {
    forward_list<Cocktail> buffer;
    for (auto iter = this->gefilterte_liste.begin(); iter != this->gefilterte_liste.end(); iter++)
    {
        if(iter->alkoholgehalt_cocktail >= alk_min)
        {
            buffer.push_front(*iter);
        }
    }
    this->gefilterte_liste.clear();
    this->gefilterte_liste = buffer;
}


//(Alkohol) Neuer (und vorerst einziger - außer es wird danach einer mit "..._bestehend" zugefügt)
void Cocktailliste::filter_cocktailliste_neu_alk_max(int alk_max) {
    this->gefilterte_liste.clear();         //Liste leeren
    for (auto iter = this->liste.begin(); iter != this->liste.end(); iter++)
    {
        if(iter->alkoholgehalt_cocktail <= alk_max)
        {
            this->gefilterte_liste.push_front(*iter);
        }
    }
}
void Cocktailliste::filter_cocktailliste_neu_alk_min(int alk_min) {
    this->gefilterte_liste.clear();         //Liste leeren
    for (auto iter = this->liste.begin(); iter != this->liste.end(); iter++)
    {
        if(iter->alkoholgehalt_cocktail >= alk_min)
        {
            this->gefilterte_liste.push_front(*iter);
        }
    }
}


//Warenkorb Methode add_wk (Cocktail zu Warenkorb hinzufügen!)
void Cocktailliste::add_wk(Cocktail neu) {
    bool vorhanden = false;
    for(auto it = this->warenkorb.begin(); it != this->warenkorb.end(); it++)
    {
        if(neu.name == it->name)
        {
            vorhanden = true;
            it->anz_wk++;
        }
    }
    if(!vorhanden)
    {
        this->warenkorb.push_front({neu,1});
    }
}


//Cocktail aus Warenkorb entfernen
void Cocktailliste::remove_wk(Cocktail neu){
    for (auto iter = this->warenkorb.begin(); iter != this->warenkorb.end(); iter++)
    {
        if(iter->name == neu.name)
        {
            iter->anz_wk = iter->anz_wk - 1;
        }
    }
    this->warenkorb.remove_if(Null);
}
bool Null(const Warenkorb& a)
{
    if(a.anz_wk == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//Warenkorb leeren
void Cocktailliste::clear_wk(){
    this->warenkorb.clear();
}

//########################################################################################################################muss noch getestet werden!
//Anz des Cocktails in Warenkorb setzen!
void Cocktailliste::set_anz_wk(Cocktail neu, int anz) {
    bool vorhanden = false;
    for(auto it = this->warenkorb.begin(); it != this->warenkorb.end(); it++)
    {
        if(neu.name == it->name)
        {
            vorhanden = true;
            it->anz_wk = anz;
        }
    }
    if(!vorhanden)
    {
        this->warenkorb.push_front({neu,anz});
    }
    this->warenkorb.remove_if(Null);
}


//Print WK -> um sich im Debug den WK anzeigen zu lassen!
void Cocktailliste::print_wk(){
    qDebug() << '\n';
    //auto iter = this->cocktail_anz_warenkorb.begin();
    for(auto it = this->warenkorb.begin(); it != this->warenkorb.end(); it++)
    {
        qDebug() << "Cocktailname: " << QString::fromStdString(it->name) << " Azahl: " << it->anz_wk << '\n';
        //iter++;
    }
    qDebug() << '\n';
}

void Cocktailliste::filter_liste(){
    this->filter_cocktailliste_neu_alk_min(0);          //Um gefilterteliste mit allem wieder zu befüllen!
    for(auto it = this->wunschliste_zutaten.begin(); it != this->wunschliste_zutaten.end(); it++)
    {
        this->filter_cocktailliste_bestehend(*it);
    }
    this->filter_cocktailliste_bestehend_alk_min(this->alk_min);
    this->filter_cocktailliste_bestehend_alk_max(this->alk_max);
}
