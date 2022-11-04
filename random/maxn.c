#include <stdio.h>

/*
    maximum von n zahlen
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

    for (size_t i = 0; i < arrayLength; i++)
    {
        printf("Zahl %d: ", (int)i);
        scanf("%d", &a[i]);
    }
    
    int max = a[0];

    for (size_t i = 1; i < arrayLength; i++)
    {
        if (a[i] > max) max = a[i];        
    }
    
    printf("\nMaximum: %d\n", max);

    return 0;
}
