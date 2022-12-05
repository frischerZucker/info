#include <stdio.h>

/*
    Übung 5, Aufgabe 1
*/

int main(int argc, char const *argv[])
{
    double v1[3], v2[3], c[3][3];

    printf("Matrix v1:\n");
    for (int i = 0; i < 3; i++) scanf("%lf", &v1[i]);  

    printf("Matrix v2:\n");
    for (int i = 0; i < 3; i++) scanf("%lf", &v2[i]);   

    printf("v1 * v2T: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = v1[i] * v2[j];   
            printf("%lf ", c[i][j]);
        }
        printf("\n");
    }      
    
    return 0;
}
