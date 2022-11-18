#include <stdio.h>

/*
    Projekt 3, Teil 1 -> Text verschlüsseln
    ---
    aufgabe:
        text aus datei einlesen
        polyalphabetisch verschlüsseln
    ---
    TODO:
        klappt noch nicht wirklich, da manche buchstaben häufiger vorkommen als andere, obwohl dies im durchschnitt nicht der fall ist
*/

int main(int argc, char const *argv[])
{
    /*
        anzahl an zeichen zwischen 'A' und 'a' in der ascii-tabelle
    */
    const int CHAR_DIF = 32;

    const char DECRYPTED_CHARS[] = {'e','n','i','s','r','a','t','d','h','u','l','c','g','m','o','b','w','f','k','z','p','v','j','y','x','q'};

    int count_of_encrypted_chars[256];  //anzahl wie oft die jeweiligen zeichen im verschlüsselten text vorkommen
    int number_of_chars = 0;            //anzahl aller zeichen des ver schlüsselten texts

    FILE *input_file = fopen("encrypted.txt", "r");
    FILE *ouput_file = fopen("decrypted.txt", "w");

    char c;

    /*
        zählt wie oft zeichen jewweils vorkommen
    */
    while ((c = fgetc(input_file)) != EOF)
    {
        /*
            überspringt das aktuelle zeichen, falls es kein buchstabe ist
        */
        if (c < 65 || (c > 90 && c < 97) || c > 122) continue;
        
        if (c <= 90 && c >= 65) count_of_encrypted_chars[c + CHAR_DIF]++;
        else count_of_encrypted_chars[c]++;

        number_of_chars++;
    }

    printf("%d chars found\n", number_of_chars);
    for (int i = 'a'; i <= 'z'; i++) printf("#%c: %d\n", i, count_of_encrypted_chars[i]);
    
    int max = 0;        //aktuelles maximum
    int last_max = -1;  //maximum der letzten iteration

    char char_max;                      //am häufigsten vorkommendes zeichen
    char sorted_encrypted_chars[26];    //verschlüsselte zeichen absteigens nach ihrer häufigkeit sortiert

    printf("chars nach häufigkeit sortiert:\n");
    for(int j = 0; j < 26; j++) {
        for (int i = 'a'; i <= 'z'; i++) 
        {
            if (max > count_of_encrypted_chars[i]) continue;
            if (last_max != -1 && count_of_encrypted_chars[i] >= last_max) continue;

            max = count_of_encrypted_chars[i];
            char_max = i;
        }
        last_max = max;
        max = 0;

        sorted_encrypted_chars[j] = char_max;
        printf("%c ", sorted_encrypted_chars[j]);
    }

    fclose(input_file);
    input_file = fopen("encrypted.txt", "r");

    while ((c = fgetc(input_file)) != EOF)
    {
        /*
            überspringt das aktuelle zeichen, falls es kein buchstabe ist
        */
        if (c < 65 || (c > 90 && c < 97) || c > 122) fputc(c, ouput_file);
        
        if (c <= 90 && c >= 65) c += CHAR_DIF;

        for (int i = 0; i < 26; i++)
        {
            if (c == sorted_encrypted_chars[i])
            {
                fputc(DECRYPTED_CHARS[i], ouput_file);
                break;
            }
            
        }
        
    }

    fclose(input_file);
    fclose(ouput_file);

    return 0;
}
