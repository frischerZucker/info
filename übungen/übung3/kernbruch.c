#include <stdio.h>

/*
    Übung 3, Aufgabe 3
    ---
    kernbruch berechnen
*/

/*
    tauscht die werte auf die die übergebenen pointer zeigen
*/
void swapVars(int *pa, int *pb)
{
        *pa += *pb;
        *pb = *pa - *pb;
        *pa -= *pb;
}

int main(int argc, char const *argv[])
{
    /*
        a, b -> bruch zur berechnung des ggt
        c, d -> variablen zur ausgabe des kernbruchs, da a und b während des berechnens des ggt verändert werden
    */
    int a, b, c, d;

    printf("a/b\na: ");
    scanf("%d", &a);
    printf("\nb: ");
    scanf("%d", &b);

    c = a;
    d = b;

    /*
        zähler = nenner = ggt -> springt direkt zur ausgabe
    */
    if (a == b) goto ausgabe;
    
    /*
        sorgt dafür dass a immer größer als b ist 
    */
    if (a < b) swapVars(&a, &b);
    
    /*
        sucht den ggt mithilfe des euklidischen algorithmus
    */
    while (a != b)
    {        
        while (a - b > 0) a -= b;
        swapVars(&a, &b);
    }

    ausgabe:
    printf("Kernbruch: %d/%d\n", c / a, d / a);

    return 0;
}
