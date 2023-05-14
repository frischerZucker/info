#include <iostream>
#include <map>

/*
    a)  Das Programm "funktioniert" theoretisch bis n=93, da dies die größte Fibonacci-Zahl (ca. 1,2*10^19) ist, die in den datentyp long long (max ca. 1,8 * 10^19) passt.
        Wirklich praktisch zu funktionieren hört das Programm schon deutlich früher auf. 
        Bei n=50 benötigt es zum Beispiel schon 40730022147 rekursive Aufrufe und dafür ca. 1,5 Minuten zur Berechnung von fibonacci_zahl(50)=20365011074.
*/

/*
    Berechnet der n-te Fibonacci-Zahl dynamisch und gibt diese Zahl zurück.

    Argumente:
        n: die wie vielte Fibonacci-Zahl berechnet werden soll
        rekursive_aufrufe: Pointer auf einen long, in dem die Anzahl der rekursiven Aufrufe gezählt wird
        gemerkte_zahlen: Array in der schon berechnete Fibonacci-Zahlen gemerkt werden
*/
long fibonacci_zahl(int n, long *rekursive_aufrufe, long gemerkte_zahlen[])
{
    *rekursive_aufrufe += 1;

    if (n == 0 || n == 1) 
    {
        gemerkte_zahlen[n] = 1;
        return 1;
    }

    if (gemerkte_zahlen[n] != 0) 
    {
        return gemerkte_zahlen[n];
    }
    else
    {
        gemerkte_zahlen[n] = fibonacci_zahl(n - 1, rekursive_aufrufe, gemerkte_zahlen) + fibonacci_zahl(n - 2, rekursive_aufrufe, gemerkte_zahlen);
        return gemerkte_zahlen[n];
    }
}

/*
    Berechnet die n-te Fibonacci-Zahl und gibt diese Zahl zurück.

    Argumente:
        n: die wie vielte Fibonacci-Zahl berechnet werden soll
        rekursive_aufrufe: Pointer auf einen long, in dem die Anzahl der rekursiven Aufrufe gezählt wird
        dynamisch: Legt fest ob die Fibonacci-Zahl dynamisch berechnet werden soll.
                   Falls true, werden die Parameter an die dynamische Version der Funktion übergeben.
*/
long fibonacci_zahl(int n, long *rekursive_aufrufe, bool dynamisch)
{
    if (dynamisch)
    {
        long gemerkte_zahlen2[n + 1];
        for (size_t i = 0; i < n + 1; i++) gemerkte_zahlen2[i] = 0;
        
        return fibonacci_zahl(n, rekursive_aufrufe, gemerkte_zahlen2);
    }

    *rekursive_aufrufe += 1;

    if (n == 0 || n == 1) return 1;

    return fibonacci_zahl(n - 1, rekursive_aufrufe, false) + fibonacci_zahl(n - 2, rekursive_aufrufe, false);
}

int main(int argc, char const *argv[])
{
    long rekursive_aufrufe = 0;
    for (int n = 0; n <= 20; n++)
    {
        std::cout << "n=" << n << ": " << fibonacci_zahl(n, &rekursive_aufrufe, true) << ", " << rekursive_aufrufe << " rekursive Aufrufe" << std::endl;
    }
    
    return 0;
}
