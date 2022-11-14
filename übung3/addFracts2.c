#include <stdio.h>

/*
    Übung 2, Aufgabe 1
    ---
    zwei brüche eingeben und addieren und als kernbruch ausgeben
*/

void swapVars(int *pa, int *pb)
{
        *pa += *pb;
        *pb = *pa - *pb;
        *pa -= *pb;
}

int getGgt(int *pa, int *pb)
{
    int a = *pa;
    int b = *pb;

    if (a == b) return a;
    
    if (a < b) swapVars(&a, &b);
    
    while (a != b)
    {        
        while (a - b > 0) a -= b;
        swapVars(&a, &b);
    }

    return a;
}

int main(int argc, char const *argv[])
{
    /*
        a, b -> bruch1
        c, d -> bruch2
        tempb -> zwischenspeicher für b
    */
    int a, b, c, d, tempb, ggt;

    printf("a/b + c/d\na: ");
    scanf("%d", &a);
    printf("\nb: ");
    scanf("%d", &b);
    printf("\nc: ");
    scanf("%d", &c);
    printf("\nd: ");
    scanf("%d", &d);

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

    ggt = getGgt(&a, &b);
    printf("größter gemeinsamer Teiler: %d\n", ggt);

    a = a / ggt;
    b = b / ggt;

    printf("Ergebnis als Kernbruch: %d/%d", a, b);

    return 0;
}
