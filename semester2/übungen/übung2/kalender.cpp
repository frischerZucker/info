#include <iostream>
#define rote_beete 0

typedef short monat;
typedef short m_tag;
typedef struct 
{
    m_tag tag;  // Monatstag (1-31)
    monat mon;  // Monat (1-12)
    int Jahr;   // Jahr
} datum;

bool februar_in_schaltjahr(datum d)
{
    return d.mon == 2 && d.Jahr % 4 == 0;
}

/*
    Liest n Daten ein und speichert sie in das übergebene Array.
*/
void daten_einlesen(datum daten[], int n)
{
    /*
        Beinhaltet die Anzahl an Tagen der Monate, die Zahl des Monats dient als Index.
        Die Ausnahme ist der Februar in Schaltjahren, sein Index ist 0.
    */
    m_tag max_tage_in_monat[] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (size_t i = 0; i < n; i++)
    {
        std::cout << "Tag: ";
        std::cin >> daten[i].tag;
        std::cout << "Monat: ";
        std::cin >> daten[i].mon;
        std::cout << "Jahr: ";
        std::cin >> daten[i].Jahr;
        std::cout << std::endl;

        if (daten[i].mon > 12) daten[i].mon = 12;
        else if (daten[i].mon < 1) daten[i].mon = 1;
        
        if (februar_in_schaltjahr(daten[i]) && daten[i].tag > max_tage_in_monat[0]) daten[i].tag = max_tage_in_monat[0];
        else if (daten[i].tag > max_tage_in_monat[daten[i].mon]) daten[i].tag = max_tage_in_monat[daten[i].mon]; 
        else if (daten[i].tag < 1) daten[i].tag = 1;
    }
}

/*
    Verschiebt das übergebene Datum und gibt das Ergebnis zurück.
    Daten im Dezember werden zu Januar des Folgejahres.
    Wenn der Tag des verschobenen Datums größer ist, als die Anzahl an Tagen des Monats, wird der Tag auf den letzten Tag des Monats gesetzt
*/
datum datum_verschieben(datum datum)
{
    /*
        Beinhaltet die Anzahl an Tagen der Monate, die Zahl des Monats dient als Index.
        Die Ausnahme ist der Februar in Schaltjahren, sein Index ist 0.
    */
    m_tag max_tage_in_monat[] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    datum.mon += 1;
    if (datum.mon > 12) 
    {
        datum.mon = 1;
        datum.Jahr += 1;
    }

    if (februar_in_schaltjahr(datum) && datum.tag > max_tage_in_monat[0]) datum.tag = max_tage_in_monat[0];
    else if (datum.tag > max_tage_in_monat[datum.mon]) datum.tag = max_tage_in_monat[datum.mon];

    return datum;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cout << "Wie viele Daten sollen eingegeben werden? ";
    std::cin >> n;

    datum daten[n];

    daten_einlesen(daten, n);

    std::cout << "verschobene Monate:" << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        daten[i] = datum_verschieben(daten[i]);
        std::cout << daten[i].tag << "/" << daten[i].mon << "/" << daten[i].Jahr << std::endl;
    }
    
    return 0;
}
