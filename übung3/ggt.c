#include <stdio.h>

/*
    Übung 3, Aufgabe 2
    ---
    größten gemeinsamen teiler zweier zahlen finden
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
    int a, b;

    printf("Zahl 1: ");
    scanf("%d", &a);
    printf("\nZahl 2: ");
    scanf("%d", &b);

    /*
        die zahlen selber sind ihr ggt -> springt direkt zur ausgabe
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
    printf("größter gemeinsamer Teiler: %d\n", a);

    return 0;
}
