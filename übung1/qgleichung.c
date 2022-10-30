#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double a, b, c, d, wurzel, x1, x2;
    
    printf("Bitte Koeffizienten eingeben: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Koeffizienten a=%lf b=%lf c=%lf\n", a, b, c);
        
//  keine quadratische gleichung
    if (a == 0)
    {
        printf("keine quadratische Gleichung\n");

        x1 = -c / b;

        printf("Die Lösung ist x1=%lf\n", x1);

        return 0;
    }

    d = b * b - 4 * a * c;

//  reelle lösungen
    if(d >= 0) 
    {
        wurzel = sqrt(d);

        x1 = (-b + wurzel) / (2 * a);
        x2 = (-b - wurzel) / (2 * a);

        (wurzel == 0) ? printf("Die Lösung ist x1=%lf\n", x1) : printf("Die Lösungen sind x1=%lf x2=%lf\n", x1, x2);
    }
//  nicht reelle lösungen
    else 
    {
        printf("Es gibt keine reellen Lösungen\n");

        wurzel = sqrt(-d);

        double xa = -b / (2 * a); 
        double x1b =  wurzel / (2 * a);
        double x2b =  -wurzel / (2 * a);

        (x1b >= 0) ? printf("Die Lösungen sind x1=%lf+%lfi ", xa, x1b) : printf("Die Lösungen sind x1=%lf%lfi ", xa, x1b);
        (x2b >= 0) ? printf("x2=%lf+%lfi\n", xa, x2b) : printf("x2=%lf-%lfi\n", xa, x2b);
    }

    return 0;
}
