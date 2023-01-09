#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Projekt: Kassenzettel berechnen
    -------------------------------
    %ms in scanf() kein standard c - trotzdem nutzen?
    -> alternativ scan_string_with_unknown_length() um zu kleine / große strings zu verhindern
*/

struct Kategorie
{
    char *name;
    int anzahl;
    double gesamtpreis;
};

/*
    global damit sie nicht ständig an funktionen übergeben werden müssen und sie sowieso die ganze laufzeit über "leben"
*/
struct Kategorie *kategorien;
int anzahl_kategorien = 0;

/*
    liest string mit vorher unbekannter länge aus dem übergebenen stream ein und speichert ihn in p_string mit passender länge
    standard-c-konforme alternative zu %ms in scanf()
*/
void scan_string_with_unknown_length(char **p_string, FILE *stream)
{
    /*
        current_size -> aktuelle anzahl an chars im string
        max_size -> bei aktuell zugewiesenem speicher maximale anzahl an chars
    */
    int current_size = 0, max_size = 10;

    /*
        allocated max_size chars für den einzulesenden string in p_string
    */
    *p_string = malloc(sizeof(char) * max_size);
    
    char c;

    /*
        ließt so lange einzelne zeichen aus input_file ein, bis das ende der datei erreicht ist
    */
    while ((c = fgetc(stream)) != EOF)
    {
        /*
            wenn die aktuelle anzahl an zeichen das maximum erreicht, wird das maximum verdoppelt und dem p_string entsprechender speicher zugewiesen
        */
        if (current_size == max_size)
        {
            max_size *= 2;
            *p_string = realloc(*p_string, sizeof(char) * max_size);
        }

        /*
            wenn das trennzeichen (' ') eingelesen wird, wird p_string '\0' hinzugefügt um den string zu beenden
            und p_string der für die aktuelle anzahl an chars benötigte speicher zugewiesen um übeerschüssig zugewiesenen speicehr zu vermeiden;
            funktion wird beendet
        */
        if (c == ' ' || c == '\n' || c == '\t')
        {
            (*p_string)[current_size] = '\0';

            *p_string = realloc(*p_string, current_size + 1);

            return;
        }
        
        /*
            fügt c zum in p_string gespeicherten string hinzu
        */
        (*p_string)[current_size] = c;

        current_size++;
    }
}

/*
    fügt eine neue warenkategorie zum array hinzu
*/
void add_new_category(char *name, double *preis)
{
    anzahl_kategorien++;

    /*
        nutzt malloc um array zu erzeugen falls noch keine kategorie vorhanden und realloc um es anderenfalls zu erweitern
    */
    kategorien = (kategorien == NULL) ? malloc(sizeof(struct Kategorie)) : realloc(kategorien, anzahl_kategorien * sizeof(struct Kategorie));
    
    kategorien[anzahl_kategorien - 1].anzahl = 1;
    kategorien[anzahl_kategorien - 1].gesamtpreis = *preis;
    kategorien[anzahl_kategorien - 1].name = malloc(sizeof(name));
    strcpy(kategorien[anzahl_kategorien - 1].name, name);
}

/*
    fügt item zu bereits existierender kategorie hinzu
*/
void add_to_existing_category(int index, double *preis)
{
    kategorien[index].anzahl++;
    kategorien[index].gesamtpreis += *preis;
}

/*
    liest kategorie-preis-paare aus input_file ein und speichert sie in kategorien
*/
void read_data_from_file(FILE *input_file)
{
    while (!feof(input_file))
    {
        char *name;
        double preis;

        scan_string_with_unknown_length(&name, input_file);
        fscanf(input_file, "%lf", &preis);
        /*
            bugfix, überspringt whitespace nach dem preis, da sonst der preis noch mal zur kategorie " " hinzugefügt würde
            nicht notwendig wenn scanf("%ms", name) statt scan_string_with_unknown_length(&name, input_file) genutzt wird
        */
        fgetc(input_file);

        /*
            schaut ob die kategorie schon existiert
            j -> fügt preis zu kategorie hinzu
            n -> erstellt neue kategorie
        */
        for (int i = 0; i < anzahl_kategorien; i++)
        {
            if (strcmp(kategorien[i].name, name) != 0) continue;

            add_to_existing_category(i, &preis);

            goto loop_end;
        }
        
        add_new_category(name, &preis); 

        loop_end:
        free(name);
    }
}

void print_results_to_file(FILE *output_file)
{
    double gesamtpreis = 0; //summe der preise aller kategorien
    
    for (int i = 0; i < anzahl_kategorien; i++)
    {
        gesamtpreis += kategorien[i].gesamtpreis;
        
        fprintf(output_file, "\t%s: %.2f, %d Produkte, Mittelwert: %.2f\n", kategorien[i].name, kategorien[i].gesamtpreis, kategorien[i].anzahl, kategorien[i].gesamtpreis / kategorien[i].anzahl);
    }

    fprintf(output_file, "-------------------------------\n\tSumme: %.2f\n", gesamtpreis);
}

int main(int argc, char const *argv[])
{    
    char *input_file_path, *output_file_path;
    
    printf("Pfad zur Input-Datei: ");
    scan_string_with_unknown_length(&input_file_path, stdin);
    printf("Pfad zur Output-Datei: ");
    scan_string_with_unknown_length(&output_file_path, stdin);

    FILE *input_file = fopen(input_file_path, "r");
    FILE *output_file = fopen(output_file_path, "w");

    free(input_file_path); 
    free(output_file_path);

    read_data_from_file(input_file);

    print_results_to_file(output_file);

    return 0;
}
