#include <stdio.h>

/*
    Übung 2, Aufgabe 4
*/

int main(int argc, char const *argv[])
{
    int var1, var2, var3;

    printf("Var1: ");
    scanf("%d", &var1);

    printf("Var2: ");
    scanf("%d", &var2);

    printf("Var3: ");
    scanf("%d", &var3);
    
    if(var1 >= var2)
    {
        var1 += var2;
        var2 = var1 - var2;
        var1 -= var2;
    }

    if(var2 >= var3)
    {
        var3 += var2;
        var2 = var3 - var2;
        var3 -= var2;
    }

    if(var1 >= var2)
    {
        var1 += var2;
        var2 = var1 - var2;
        var1 -= var2;
    }

    printf("\n%d, %d, %d\n", var1, var2, var3);

    return 0;
}
