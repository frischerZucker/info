#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Kategorie
{
    int anzahl;
    double preis;
    char *name;
};

struct Kategorie *kategorien;
int anzahl_kategorien = 0;

/*
    liest einen string mit vorher unbekannter länge ein
    stdin für *datei übergeben, um aus der konsole einzulesen
*/
void string_einlesen(char **p_string, FILE *datei)
{
    int anzahl_chars = 0, max_anzahl_chars = 10;

    /*
        erstellt string mit start-länge von 10 chars
    */
    *p_string = malloc(sizeof(char) * max_anzahl_chars);

    char c;

    while (!feof(datei))
    {
        anzahl_chars++;
        c = fgetc(datei);

        /*
            vergrößert den string um platz für 10 chars falls die maximale größe erreicht wurde
        */
        if (anzahl_chars == max_anzahl_chars)
        {
            max_anzahl_chars += 10;
            *p_string = realloc(*p_string, sizeof(char) * max_anzahl_chars);
        }

        /*
            beendet den string bei whitespace mit \0 und verkleinert ihn auf die benötigte größe (leere chars nach \0 fallen weg)
        */
        if (c == ' ' || c == '\n' || c == '\t')
        {
            (*p_string)[anzahl_chars - 1] = '\0';
            *p_string = realloc(*p_string, sizeof(char) * anzahl_chars);
            return;
        }

        /*
            fügt eingelesenes zeichen zum string hinzu
        */
        (*p_string)[anzahl_chars - 1] = c;
    }   
}

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
    while (!feof(input_datei))
    {
        char *name;
        double preis;

        string_einlesen(&name, input_datei);
        fscanf(input_datei, "%lf", &preis);
        /*
            überspringt den whitespace nach dem preis, da string_einlesen sonst das leerzeichen als kategorie einliest
        */
        fgetc(input_datei);

        if (anzahl_kategorien == 0) 
        {
            neue_kategorie_hinzufügen(name, &preis);
            continue;
        }

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
        free(name);
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
    char *input_datei_pfad, *output_datei_pfad;

    printf("Speicherort der Input-Datei:\n");
    string_einlesen(&input_datei_pfad, stdin);

    printf("Speicherort der Ausgabe-Datei:\n");
    string_einlesen(&output_datei_pfad, stdin);

    //char *input_datei_pfad = "input.txt", *output_datei_pfad = "output.txt";

    FILE *input_datei = fopen(input_datei_pfad, "r");
    FILE *output_datei = fopen(output_datei_pfad, "w");

    free(input_datei_pfad);
    free(output_datei_pfad);

    daten_einlesen(input_datei);
    
    daten_in_datei_schreiben(output_datei);

    fclose(input_datei);
    fclose(output_datei);

    return 0;
}