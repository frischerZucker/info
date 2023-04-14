#include <stdio.h>

/*
    Projekt 3, Teil 1 -> Text verschlüsseln
    ---
    aufgabe:
       text aus datei einlesen
       polyalphabetisch verschlüsseln
    ---
    TODO:
*/

int main(int argc, char const *argv[])
{
    char zuordnung[265];
    char i = 'a';

    zuordnung[i] = 'z';
    zuordnung[i - 32] = 'Z';

    for (i += 1; i <= 'z'; i++)
    {
        zuordnung[i] = i - 1;
        zuordnung[i - 32] = i - 33;
    }    

    FILE *inputFile = fopen("raw.txt", "r");
    FILE *ouputFile = fopen("encrypted.txt", "w");

    char c;

    printf("verschlüsselt:\n");
    /*
        ließt inputFile zeichenweise ein
        speichert das ihnen zugeordnete verschlüsselte zeichen in outputFile
    */
    while ((c = fgetc(inputFile)) != EOF)
    {
        printf("%c", (zuordnung[c] == NULL) ? c : zuordnung[c]);
        fputc((zuordnung[c] == NULL) ? c : zuordnung[c], ouputFile);
    }

    fclose(inputFile);
    fclose(ouputFile);

    return 0;
}
