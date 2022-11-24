#include <stdio.h>

/*
    Übung 4, Aufgabe 1
*/

int main(int argc, char const *argv[])
{
    int a_length, b_length, c_length;

//  a einlesen
    printf("#Zahlen von a[]: ");
    scanf("%d", &a_length);

    int a[a_length];

    for (int i = 0; i < a_length; i++)
    {
        printf("Zahl %d: ", (int)i);
        scanf("%d", &a[i]);
    }

//  b einlesen
    printf("#Zahlen von b[]: ");
    scanf("%d", &b_length);

    int b[b_length];

    for (int i = 0; i < b_length; i++)
    {
        printf("Zahl %d: ", (int)i);
        scanf("%d", &b[i]);
    }

    c_length = a_length + b_length;

    int c[c_length];

//  a und b zu c hinzufügen
    for (int i = 0; i < a_length; i++) c[i] = a[i];
    for (int i = 0; i < b_length; i++) c[i + a_length] = b[i];

//  c sortieren
    for (int j = c_length - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (c[i] > c[i + 1])
            {
                c[i] += c[i + 1];
                c[i + 1] = c[i] - c[i + 1];
                c[i] -= c[i + 1];
            }      
        }
    }

//  array c ausgeben
    printf("\nc: ");
    for (int i = 0; i < c_length; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
