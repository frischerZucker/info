#include <stdio.h>

/*
    Übung 2, Aufgabe 1
*/

int main(int argc, char const *argv[])
{
    int a, b, c;

    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);

    c = a;
    a = b;
    b = c;

    printf("\na: %d | b: %d\n", a, b);

    return(0);
}