#include <iostream>
#include <ctime>

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

int main(int argc, char const *argv[])
{
    int array_länge = 50;
    int durchgänge = 1000;
    std::srand(std::time(nullptr));
    long durchschnittliche_vertauschungen = 0;
    for (size_t i = 0; i < durchgänge; i++)
    {
        int a[array_länge];
        std::cout << "Durchgang #" << i << "\nunsortiertes Feld:\n";
        for (size_t j = 0; j < array_länge; j++)
        {
            a[j] = 1 + rand()/((RAND_MAX + 1u)/500);
            std::cout << a[j];
            if (j == array_länge - 1) std::cout << "\n";
            else std::cout << ", ";
        }
        long anzahl_vertauschungen = 0;
        bubblesort(a, array_länge, &anzahl_vertauschungen);
        std::cout << "sortiertes Feld:\n";
        for (size_t j = 0; j < array_länge; j++)
        {
            std::cout << a[j];
            if (j == array_länge - 1) std::cout << "\n";
            else std::cout << ", ";
        }
        std::cout << "Anzahl Vertauschungen: " << anzahl_vertauschungen << "\n";
        durchschnittliche_vertauschungen += anzahl_vertauschungen;
    }
    durchschnittliche_vertauschungen = durchschnittliche_vertauschungen / durchgänge;
    std::cout << "\n\ndurchschnittliche Anzahl an Vertauschungen: " << durchschnittliche_vertauschungen << std::endl; 

    return 0;
}
    