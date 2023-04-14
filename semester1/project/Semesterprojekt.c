#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Kassenzettel berechnen

/*
    stellt ein eingelesenes produkt dar
*/
struct kategorie
{
    char produktname[50];
    float produktpreis;
};

/*
    variablen für dynamisches array, in das die eingelesenen daten gespeichert werden
*/
struct kategorie *kat, l;
int anzahl_der_element = 0;

/*
    fügt ein neues produkt mit dem übergebenen namen und preis zum array hinzu
*/
void neu_kategorie(char name[50], float *p_preis)
{
    //fügt dem array platz für ein weiteres element hinzu
    anzahl_der_element++;
    kat = (kat == NULL) ? malloc(sizeof(struct kategorie)) : realloc(kat, sizeof(struct kategorie) * anzahl_der_element);
    
    //  daten in neu hinzugefügtes element speichern
    strcpy(kat[anzahl_der_element - 1].produktname, name);
    kat[anzahl_der_element - 1].produktpreis = *p_preis;
}

int main()
{

    int i, j, k,                        //  indexvariablen für schleifen 
        anzahl_der_produkt;             //  anzahl von produkten einer kategorie (gleicher name)
    float summe, gesamt, mittelwert;    //  gesamtpreis aller produkte, gesamtpreis aller produkte einer kategorie, mittelwert einer kategorie
    FILE *eingabedatei;
    char pfad_der_eingabedatei[100];
    FILE *ausgabedatei;
    char pfad_der_ausgabedatei[100];
    
    //werden aus eingabedatei eingelesen
    char name[50];
    float preis;

    /*
        eingabe aus welcher datei daten gelesen bzw in welche datei die ergebnisse geschrieben werden sollen
    */
    printf("Geben Sie den Speicherort der Eingabedatei ein:> \n");
    scanf("%s", pfad_der_eingabedatei);

    printf("Geben Sie den Speicherort der Ausgabedatei ein:> \n");
    scanf("%s", pfad_der_ausgabedatei);

    /*
        versucht die eingegebenen dateien zu öffnen und beendet das programm falls dabei ein fehler auftritt
    */
    eingabedatei = fopen(pfad_der_eingabedatei, "r");
    if(eingabedatei == NULL)
    {
        printf("Fehler! Eingabedatei/Pfad der Eingabedatei nicht gefunden");
        exit(1);
    }
    ausgabedatei = fopen(pfad_der_ausgabedatei, "w");
    if(ausgabedatei == NULL)
    {
        printf("Fehler! Ausgabedatei kann nicht erstellt werden");
        exit(1);
    }

    /*
        liest so lange immer einen string und einen float ein, bis das ende der datei erreicht ist
    */
    while(!feof(eingabedatei))
    {
        fscanf(eingabedatei, "%s %f", name, &preis);
        //  eingelesene daten ins array speichern
        neu_kategorie(name,&preis);
    }

    /*
        sortiert die produkte im array alphabetisch
    */
    for(i = 0; i < anzahl_der_element; i++)
    {
        for(j = i + 1; j < anzahl_der_element; j++)
        {
            //  vergleicht zwei produktnamen und tauscht die produkte falls nötig
            if(strcmp(kat[i].produktname, kat[j].produktname) > 0)
            {
                l = kat[i];
                kat[i] = kat[j];
                kat[j] = l;
            }
        }
    }

    //Druck nach Produktname sortieren.
    printf("\n");

    summe = 0;
    for(i = 0; i < anzahl_der_element; i++)
    {
        summe += kat[i].produktpreis;
    }

    fprintf(ausgabedatei, "Ausgabedatei: \n\n");
    
    gesamt = 0;
    for(i = 0; i < anzahl_der_element; i++)
    {
        anzahl_der_produkt = 1;
        gesamt = kat[i].produktpreis;
        
        //sucht nach weiteren Elementen mit gleichem Namen, zählt die Anzahl gleicher Produkte und fasst ihre Preise im Gesamtpreis zusammen
        for(j = i + 1; j < anzahl_der_element; j++)
        {
            if(strcmp(kat[i].produktname, kat[j].produktname) == 0)
            {
                anzahl_der_produkt++;
                //Produktpreis addieren.
                gesamt += kat[j].produktpreis;
                //Gleichnamige produkte löschen.
                for(k = j; k < anzahl_der_element; k++)
                {
                    kat[k] = kat[k + 1];
                }
                j--; //j=j-1.
                anzahl_der_element--; //anzahl_der_elemente=anzahl_der_elemente-1.
            }
        }
        //mittelwert finden .
        mittelwert = gesamt / anzahl_der_produkt;
        if(anzahl_der_produkt > 1)
        {
            printf("%15s:  %10.2f,\t%d Produkte,\tMittelwert: %8.2f\n", kat[i].produktname, gesamt, anzahl_der_produkt, mittelwert);
            fprintf(ausgabedatei,"%15s:  %10.2f,\t%d Produkte,\tMittelwert: %8.2f\n", kat[i].produktname, gesamt, anzahl_der_produkt, mittelwert);

        } else
        {
            printf("%15s:  %10.2f,\t%d Produkt,\tMittelwert: %8.2f\n", kat[i].produktname, gesamt, anzahl_der_produkt, mittelwert);
            fprintf(ausgabedatei,"%15s:  %10.2f,\t%d Produkt,\tMittelwert: %8.2f\n", kat[i].produktname, gesamt, anzahl_der_produkt, mittelwert);
        }
    }
    printf("-------------------------------------");
    fprintf(ausgabedatei,"-------------------------------------");
    printf("\n          summe:  %10.2f", summe);
    fprintf(ausgabedatei,"\n          Summe:  %10.2f", summe);

    fclose(eingabedatei);
    fclose(ausgabedatei);
    printf("\n\nAusgabedatei wurde erfolgreich erstellt und gespeichert.");

    return 0;
}
//c:\Temp\C_code\input_category.txt
//c:\Temp\C_code\output_category.txt