#include <stdio.h>

/*
    n zahlen sortieren
*/

int main(int argc, char const *argv[])
{
    int arrayLength;

    printf("#Zahlen: ");
    scanf("%d", &arrayLength);

    if (arrayLength <= 0)
    {
        return 1;
    }
    
    int a[arrayLength];

//  array einlesen
    for (size_t i = 0; i < arrayLength; i++)
    {
        printf("Zahl %d: ", (int)i);
        scanf("%d", &a[i]);
    }

//  sortieren
    for (size_t j = arrayLength - 1; j > 0; j--)
    {
        for (size_t i = 0; i < j; i++)
        {
            if (a[i] > a[i + 1])
            {
                a[i] += a[i + 1];
                a[i + 1] = a[i] - a[i + 1];
                a[i] -= a[i + 1];
            }      
        }
    }

//  array ausgeben
    for (size_t i = 0; i < arrayLength; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
