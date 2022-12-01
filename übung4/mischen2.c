#include <stdio.h>
#include <stdbool.h>

/*
    Übung 4, Aufgabe 1
    ---
    lösungsweg eher wie erwartet
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
        printf("Zahl %d: ", i);
        scanf("%d", &a[i]);
    }

//  b einlesen
    printf("\n#Zahlen von b[]: ");
    scanf("%d", &b_length);

    int b[b_length];

    for (int i = 0; i < b_length; i++)
    {
        printf("Zahl %d: ", i);
        scanf("%d", &b[i]);
    }

    c_length = a_length + b_length;

    int c[c_length];

    bool a_active = (a[0] < b[0]);

    int i = 0, j = 0;

    while (i + j < c_length)
    {
        /*
            fügt so lange a[i] zu c[i+j]hinzu, bis b[i] > a[i] oder i außerhalb von a[] liegt
        */
        if (a_active)
        {
            while (a[i] < b[j])
            {
                if (i >= a_length) goto end;
                c[i + j] = a[i];
                i++;
            }
        }
        /*
            fügt so lange b[j] zu c[j+i] hinzu, bis a[i]] > b[j] oder j außerhalb von b[] liegt
        */
        else
        {
            while (b[j] < a[i])
            {
                if (j >= b_length) goto end;
                c[i + j] = b[j];
                j++;
            }
        } 

        a_active = a_active ? false : true;   
    }

    end:
    if (a_active) for (j; j < b_length; j++) c[i + j] = b[j];
    else for (i; i < a_length; i++) c[i + j] = a[i];

//  array c ausgeben
    printf("\nc: ");
    for (int i = 0; i < c_length; i++) 
    {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
