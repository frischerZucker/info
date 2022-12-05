#include <stdio.h>

/*
    Übung 2, Aufgabe 2
*/

int main(int argc, char const *argv[])
{
    int a, b;

    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);

    a += b;
    b = a - b;
    a -= b;

    printf("\na: %d | b: %d\n", a, b);

    return(0);
}
