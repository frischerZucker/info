#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Projekt 2, Text formatieren
    ---
    aufgabe:
        text aus datei einlesen
        text mit maximaler zeilenausnutzung in zeilen mit n > 0 zeichen in neue datei schreiben
    ---
    TODO:
        lineLength müsste eigentlich beim start als parameter angegeben werden
*/

/*
    gibt den übergebenen string als fehlermeldung aus und beendet das programm
*/
void error(char errMsg[])
{
    printf("\nERROR: %s\n", errMsg);
    exit(1);
}

/*
    gibt die übergebene zeile in der konsole aus und speichert sie in outputFile
*/
void outputLine(char line[], FILE *file)
{
    printf("%s\n", line);
    fprintf(file, "%s\n", line);
}

int main(int argc, char const *argv[])
{
    /*
        liest je einen dateipfad für die input- & outputdatei ein
    */
    char inFilePath[100], outFilePath[100];
    printf("Pfad zur Input-Datei: ");
    scanf("%s", inFilePath);
    printf("Pfad zur Output-Datei: ");
    scanf("%s", outFilePath);

    FILE *inputFile = fopen(inFilePath, "r"); 
    if(inputFile == NULL) error("Input-Datei kann nicht geöffnet werden!\n-> Der angegebene Dateipfad ist länger als 100 Zeichen oder die Datei existiert nicht.");

    FILE *outputFile = fopen(outFilePath, "w");

    int lineLength;
    printf("gewünschte Zeilenlänge: ");
    scanf("%d", &lineLength);

    printf("------------------\n");
    
    char c, lastC;                      //aus datei ausgelesenes zeichen, zuletzt ausgelesenes zeichen
    char line[lineLength + 1];          //aktive zeile in die geschrieben wird
    char nextLine[lineLength + 1];      //zwischenspeicher für die nächste zeile
    char temp[lineLength + 1];          //zwischenspeicher für abgeschnittene worte

    /*
        setzt null-terminator-zeichen ans ende der strings, um ihr ende zu definieren 
    */
    line[lineLength] = '\0';
    nextLine[lineLength] = '\0';
    temp[lineLength] = '\0';

    /*
        indexvariablen für line, nextLine, temp
    */
    int i = 0,
        j = 0,
        k = 0;                 

    /*
        liest jedes zeichen aus inputFile einzeln ein
    */
    while ((c = fgetc(inputFile)) != EOF)
    {
        /*
            speichert ausgelesene zeichen in line, bis die vorgegebene zeilenlänge erreicht ist
            '\n' wird dabei durch ' ' ersetzt
        */
        if (i < lineLength)
        {
            if (c == '\n') c = ' ';
            
            line[i] = c;

            lastC = c;

            i++;

            continue;
        }
        /*
            der folgende code wird nur ausgeführt, wenn die maximale zeilenlänge erreicht, bzw überschritten wurde

            i wird um eins verringert, damit es wieder innerhalb der zeilelänge liegt
        */
        i -= 1;

        if (c == '\n') c = ' ';

        /*
            schaut ob entweder das aktuell oder zuletzt eingelesene zeichen nicht ' ' oder '\n' ist, da dann durch den zeilenumbruch ein wort abgeschnitten wurde
        */
        if (!(lastC == ' ' || c == ' '))
        {
            j = 0;

            /*
                geht vom ende der zeile aus alle zeichen durch, bis ein ' ' gefunden wird, speichert sie in temp und löscht sie aus line
                temp beinhaltet dann den anfang des abgeschnittenen wortes aus line in umgekehrter reihenfolge
            */
            while (line[i] != ' ')
            {
                if (j > lineLength) error("Die angegebene Zeilenlänge ist kleiner als manche Wörter des Textes!");

                temp[j] = line[i];
                line[i] = ' ';
                                        
                j++;
                i -= 1;
            }

            /*
                setzt i auf die anzahl der gebufferten zeichen, damit i wenn die nächste zeile bearbeitet wird auf das richtige zeichen zeigt
            */
            i = j;

            k = 0;

            /*
                speichert temp in richtiger reihenfolge in nextline, 
            */
            for (j -= 1; j >= 0 ; j -= 1)
            {
                nextLine[k] = temp[j];
                k++;
            }

            /*
                gibt die fertige zeile aus und schreibt sie in outputFile
            */
            outputLine(line, outputFile);

            /*
                kopiert die in nextLine gebufferten zeichen des abgschnittenen wortes in line
            */
            strcpy(line, nextLine);
        }
        /*
            falls das aktuell oder zuletzt eingelesene zeichen entweder '\n' oder ' ' ist, wurde kein wort abgeschnitten
            die zeile wird so wie sie ist ausgegeben und in outputFile geschrieben
            i wird zurückgesetzt
        */
        else
        {
            outputLine(line, outputFile);
            i = 0;
        }
            
        /*
            überspringt, bzw verhindert ' ' am zeilenanfang
        */
        if (c == ' ') continue;

        line[i] = c;
            
        lastC = c;

        i++;
    }

    /*
        löscht aus der vorletzten zeile übriggebliebene zeichen
    */
    for (i; i < lineLength; i++) line[i] = ' ';
    
    /*
        gibt die letzte zeile aus und schreibt sie in outputFile
    */
    outputLine(line, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}