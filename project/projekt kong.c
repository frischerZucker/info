#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Kassenzettel berechnen

struct Kategorie
{
    char Produktname[50];
    float Produktpreis;
};

//Global der Array-Struktur
struct Kategorie *kategorien, zwischenspeicher_für_kategorie;
int anzahl_kategorien = 0;

void neue_kategorie_hinzufügen(char name[50], float *p_preis)
{
    anzahl_kategorien++;
    kategorien = (kategorien == NULL) ? malloc(sizeof(struct Kategorie)) : realloc(kategorien, sizeof(struct Kategorie) * anzahl_kategorien);
    strcpy(kategorien[anzahl_kategorien - 1].Produktname, name);
    kategorien[anzahl_kategorien - 1].Produktpreis = *p_preis;
}

int main()
{
    int i, j, k, anzahl_produkte_in_kategorie;
    float Summe, gesamtpreis_von_kategorie, Mittelwert;
    FILE *Eingabedatei;
    char Pfad_der_Eingabedatei[100];
    FILE *Ausgabedatei;
    char Pfad_der_Ausgabedatei[100];
    //lesen Eingabedatei
    char Name[50];
    float Preis;

    //Pfad_der_Eingabedatei
    printf("Geben Sie den Speicherort der Eingabedatei ein:> \n");
    scanf("%s",Pfad_der_Eingabedatei);

    printf("Geben Sie den Speicherort der Ausgabedatei ein:> \n");
    scanf("%s",Pfad_der_Ausgabedatei);

    Eingabedatei = fopen(Pfad_der_Eingabedatei, "r");
    if (Eingabedatei == NULL)
    {
        printf("Fehler! Eingabedatei/Pfad der Ausgabedatei nicht gefunden");
        exit(1);
    }
    Ausgabedatei = fopen(Pfad_der_Ausgabedatei, "w");
    if (Ausgabedatei == NULL)
    {
        printf("Fehler! Ausgabedatei kann nicht erstellt werden");
        exit(1);
    }

    /*
        fügt jedes produkt als neue kategorie hinzu
    */
    while (!feof(Eingabedatei))
    {
        fscanf(Eingabedatei, "%s %f", Name, &Preis);
        neue_kategorie_hinzufügen(Name, &Preis);
    }
    
    /*
        alphabetisches sortieren der kategorien

        nicht in der aufgabe gefordert
    */
    for (i = 0; i < anzahl_kategorien; i++)
    {
        for (j = i + 1; j < anzahl_kategorien; j++)
        {
            if (strcmp(kategorien[i].Produktname, kategorien[j].Produktname)>0)
            {
                zwischenspeicher_für_kategorie = kategorien[i];
                kategorien[i] = kategorien[j];
                kategorien[j] = zwischenspeicher_für_kategorie;
            }
        }
    }

    printf("\n");

    /*
        berechnung der summe aller preise
    */
    Summe = 0;
    for (i = 0; i < anzahl_kategorien; i++) Summe += kategorien[i].Produktpreis;
        //printf("%s\t%.2f\t%d\n", Kat[i].Produktname,Kat[i].Produktpreis, i);

    fprintf(Ausgabedatei,"Ausgabedatei: \n");
    gesamtpreis_von_kategorie = 0;
    
    /*
        geht alle kategorien durch
    */
    for (i = 0; i < anzahl_kategorien; i++)
    {
        anzahl_produkte_in_kategorie = 1;
        gesamtpreis_von_kategorie = kategorien[i].Produktpreis;
        
        /*
            geht alle kategorien nach der aktuellen (i) kategorie durch
        */
        for (j = i + 1; j < anzahl_kategorien; j++)
        {
            /*
                vergleicht produktnamen beider kategorien (i und j) -> zusammenfassen gleicher kategorien
            */
            if (strcmp(kategorien[i].Produktname, kategorien[j].Produktname) == 0)
            {
                anzahl_produkte_in_kategorie++;
                //Produktpreis addieren
                gesamtpreis_von_kategorie += kategorien[j].Produktpreis;
                
                /*
                    verschiebt alle kategorien um einen platz nach vorne
                */
                for (k = j; k < anzahl_kategorien; k++) kategorien[k] = kategorien[k+1];
                /*
                    verringert die grenze des arrays
                */
                j--; //j=j-1
                anzahl_kategorien--; //anzahl_kategorien =anzahl_kategorien-1
            }
        }

        //Mittelwert finden .
        Mittelwert = gesamtpreis_von_kategorie / anzahl_produkte_in_kategorie;

        /*
            überspringt kategorien mit name "0" -> soll leere kategorien auslassen?
            falls ja nicht zielführend, da nirgends produktname = "0" gesetzt und produkte die wirklich "0" heißen wegfallen

            kann weggekürzt werden, da quasi nie false triggert wird, außer wenn der nutzer eine kategorie "0" haben wollte
        */
        if(strcmp(kategorien[i].Produktname, "0") !=0)
        {
            /*
                unterscheidung zwischen "produkt" und "produkte"
            */
            if(anzahl_produkte_in_kategorie > 1)
            {
                printf("%15s:  %10.2f,\t%d Produkte,\tMittelwert: %8.2f\n", kategorien[i].Produktname, gesamtpreis_von_kategorie, anzahl_produkte_in_kategorie, Mittelwert);
                fprintf(Ausgabedatei,"%15s:  %10.2f,\t%d Produkte,\tMittelwert: %8.2f\n", kategorien[i].Produktname, gesamtpreis_von_kategorie, anzahl_produkte_in_kategorie, Mittelwert);

            } 
            else
            {
                printf("%15s:  %10.2f,\t%d Produkt,\tMittelwert: %8.2f\n", kategorien[i].Produktname, gesamtpreis_von_kategorie, anzahl_produkte_in_kategorie, Mittelwert);
                fprintf(Ausgabedatei,"%15s:  %10.2f,\t%d Produkt,\tMittelwert: %8.2f\n", kategorien[i].Produktname, gesamtpreis_von_kategorie, anzahl_produkte_in_kategorie, Mittelwert);
            }
        }
    }
    printf("-------------------------------------");
    fprintf(Ausgabedatei,"-------------------------------------");
    printf("\n          Summe:  %10.2f", Summe);
    fprintf(Ausgabedatei,"\n          Summe:  %10.2f", Summe);

    fclose(Eingabedatei);
    fclose(Ausgabedatei);
    printf("\n\nAusgabedatei wurde erfolgreich erstellt und gespeichert.\n");

    return 0;
}
//c:\\Temp\C_code\input_category.txt
//c:\\Temp\C_code\output_category.txt
