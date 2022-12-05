#include <stdbool.h>
#include <stdio.h>

/*
    Übung 4, Aufgabe 2
*/

int main(int argc, char const *argv[])
{
    int n;
    printf("Obergrenze: ");
    scanf("%d", &n);

    bool numbers[n];

    numbers[0] = false;
    numbers[1] = false;
    for (int i = 2; i < n; i++) numbers[i] = true;
    
    for (int i = 0; i * i < n; i++)
    {
        if (!numbers[i]) continue;

        for (int j = i * 2; j < n; j += i) numbers[j] = false;
    }
    
    printf("Primzahlen von 1 bis %d:\n", n);
    for (int i = 1; i < n; i++)
    {
        if (numbers[i]) printf("%d ", i);
    }
    printf("\n");

    return 0;
}
