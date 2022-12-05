#include <stdio.h>

/*
    Übung 5, Aufgabe 3
    ---
    ä, ö, ü werden als zwei zeichen erkannt
*/

int main(int argc, char const *argv[])
{
    char chars[128];

    printf("Zeichenkette: ");
    scanf("%128s", chars);
    
    char *c = chars;

    while (*c != '\0') c++;
    
    printf("#chars: %ld\n", c - chars);

    return 0;
}