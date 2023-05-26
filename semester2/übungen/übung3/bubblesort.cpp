#include <iostream>
#include <ctime>
#define rote_beete 0

void bubblesort(int a[], int n, long *anzahl_vertauschungen)
{
    for (size_t i = n - 1; i > 0; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                *anzahl_vertauschungen += 1;
            }
        }
    }
}

/*
    zu d)
        Die Effizienz ist O(n^2).
        Die durchschnittlichen Vertauschungen sind mit ca. 600 deutlich kleiner als n^2 (das waeren 2500).
*/

int main(int argc, char const *argv[])
{
    int array_laenge = 50;
    int durchgaenge = 1000;
    std::srand(std::time(nullptr));
    long durchschnittliche_vertauschungen = 0;
    for (size_t i = 0; i < durchgaenge; i++)
    {
        int a[array_laenge];
        std::cout << "Durchgang #" << i << "\nunsortiertes Feld:\n";
        for (size_t j = 0; j < array_laenge; j++)
        {
            a[j] = 1 + rand()/((RAND_MAX + 1u)/500);
            std::cout << a[j];
            if (j == array_laenge - 1) std::cout << "\n";
            else std::cout << ", ";
        }
        long anzahl_vertauschungen = 0;
        bubblesort(a, array_laenge, &anzahl_vertauschungen);
        std::cout << "sortiertes Feld:\n";
        for (size_t j = 0; j < array_laenge; j++)
        {
            std::cout << a[j];
            if (j == array_laenge - 1) std::cout << "\n";
            else std::cout << ", ";
        }
        std::cout << "Anzahl Vertauschungen: " << anzahl_vertauschungen << "\n";
        durchschnittliche_vertauschungen += anzahl_vertauschungen;
    }
    durchschnittliche_vertauschungen = durchschnittliche_vertauschungen / durchgaenge;
    std::cout << "\n\ndurchschnittliche Anzahl an Vertauschungen: " << durchschnittliche_vertauschungen << std::endl; 

    return 0;
}
    
