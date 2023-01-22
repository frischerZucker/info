#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LÄNGE 100

struct Kategorie
{
    int anzahl;
    double preis;
    char *name;
};

struct Kategorie *kategorien;
int anzahl_kategorien = 0;

void neue_kategorie_hinzufügen(char *name, double *p_preis)
{
    anzahl_kategorien++;
    kategorien = (kategorien == NULL) ? malloc(sizeof(struct Kategorie)) : realloc(kategorien, sizeof(struct Kategorie) * anzahl_kategorien);

    kategorien[anzahl_kategorien - 1].anzahl = 1;
    kategorien[anzahl_kategorien - 1].preis = *p_preis;
    kategorien[anzahl_kategorien - 1].name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(kategorien[anzahl_kategorien - 1].name, name);
}

void zu_kategorie_hinzufügen(int i, double *p_preis)
{
    kategorien[i].anzahl++;
    kategorien[i].preis += *p_preis;
}

void daten_einlesen(FILE *input_datei)
{
    char name[MAX_STRING_LÄNGE];
    double preis;

    fscanf(input_datei, "%s %lf", name, &preis);
    neue_kategorie_hinzufügen(name, &preis);

    while (!feof(input_datei))
    {
        fscanf(input_datei, "%s %lf", name, &preis);

        /*
            überprüft ob schon eine kategorie mit dem eingelesenen namen existiert
        */
        for (int i = 0; i < anzahl_kategorien; i++)
        {
            /*
                vergleicht den namen der aktuellen kategorie (kategorien[i]) mit dem eingelesenen namen,
                springt zur nächsten kategorie wenn die namen nicht gleich sind (strcmp nicht 0 zurück gibt)
            */
            if (strcmp(name, kategorien[i].name) != 0) continue;

            zu_kategorie_hinzufügen(i, &preis);
            goto kategorie_hinzufügen_überspringen;
        }   
        
        /*
            wird nur ausgeführt wenn noch keine kategorie mit dem eingelesenen namen vorhanden ist,
            fügt neue kategorie mit dem namen zum kategorien-array hinzu
        */
        neue_kategorie_hinzufügen(name, &preis);

        kategorie_hinzufügen_überspringen:
    }
}

void daten_in_datei_schreiben(FILE *output_datei)
{
    double gesamtpreis = 0;

    for (int i = 0; i < anzahl_kategorien; i++)
    {
        fprintf(output_datei, "%s: %.2f, %d Produkte, Mittelwert: %.2f\n", kategorien[i].name, kategorien[i].preis, kategorien[i].anzahl, (kategorien[i].preis / kategorien[i].anzahl));
        gesamtpreis += kategorien[i].preis;
    }

    fprintf(output_datei, "---------------------\nSumme: %.2f\n", gesamtpreis);
}

int main(int argc, char const *argv[])
{
    char input_datei_pfad[MAX_STRING_LÄNGE], output_datei_pfad[MAX_STRING_LÄNGE];

    printf("Speicherort der Input-Datei:\n");
    scanf("%100s", input_datei_pfad);

    printf("Speicherort der Ausgabe-Datei:\n");
    scanf("%100s", output_datei_pfad);

    FILE *input_datei = fopen(input_datei_pfad, "r");

    //  beendet das programm wenn die angegebene input-datei nicht geöffnet werden kann
    if (input_datei == NULL)
    {
        printf("\"%s\" kann nicht geöffnet werden\n", input_datei_pfad);
        exit(1);
    }

    FILE *output_datei = fopen(output_datei_pfad, "w");

    daten_einlesen(input_datei);
    
    daten_in_datei_schreiben(output_datei);

    fclose(input_datei);
    fclose(output_datei);

    return 0;
}