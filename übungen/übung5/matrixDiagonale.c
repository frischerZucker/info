#include <stdio.h>

/*
    Übung 5, Aufgabe 2
*/

int main(int argc, char const *argv[])
{
    double matrix[3][3];

    for (int i = 0; i < 3; i++)
    {
        printf("Zeile #%d:\n", i);
        for (int j = 0; j < 3; j++) scanf("%lf", &matrix[i][j]);
    }

    double *c = &matrix[0][0];

    for (int i = 0; i < 3; i++) printf("%lf ", *(c + i + 3 * i));
    
    return 0;
}
