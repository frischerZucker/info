#include <stdio.h>

/*
    Übung 3, Aufgabe 1
    ---
    zwei brüche eingeben und addieren
*/

int main(int argc, char const *argv[])
{
    /*
        a, b -> bruch1
        c, d -> bruch2
        tempb -> zwischenspeicher für b
    */
    int a, b, c, d, tempb;
    
    printf("a/b + c/d\na: ");
    scanf("%d", &a);
    printf("\nb: ");
    scanf("%d", &b);
    printf("\nc: ");
    scanf("%d", &c);
    printf("\nd: ");
    scanf("%d", &d);

    if (b == 0 || d == 0)
    {
        printf("Einer der Brüche ist undefiniert, da der Nenner 0 ist!\n    ");
        return 1;
    }

    if(b == d) a += c;
    else
    {
        tempb = b;

        a *= d;
        b *= d;

        c *= tempb;

        a += c;
    }
    

    printf("Ergebnis: %d/%d\n", a, b);

    return 0;
}
