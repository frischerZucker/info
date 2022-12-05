#include <stdio.h>

/*
    Übung 2, Aufgabe 3
*/

int main(int argc, char const *argv[])
{
    int a, b, c, max;

    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);
    
    printf("c: ");
    scanf("%d", &c);

    if (a >= b && a >= c)
    {
        max = a;
    } else if (b >= a && b >= c)
    {
        max = b;
    } else
    {
        max = c;
    }
    
    printf("Maximum: %d\n", max);

    return 0;
}