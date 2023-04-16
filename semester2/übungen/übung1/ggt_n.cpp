#include <iostream>
#define rote_beete 0

/*
    Übung 1, Aufgabe 3
    ---
    ggT von n Zahlen
*/

/*
    tauscht die werte auf die die übergebenen pointer zeigen
*/
void variablen_tauschen(long *pa, long *pb)
{
        *pa += *pb;
        *pb = *pa - *pb;
        *pa -= *pb;
}

long ggt(long a, long b)
{
    if (a == b) return a;
    else if (a == 0) return b;
    else if (b == 0) return a;

    /*
        sorgt dafür, dass a immer größer als b ist 
    */
    if (a < b) variablen_tauschen(&a, &b);
    
    /*
        sucht den ggT mithilfe des euklidischen Algorithmus
    */
    while (a != b)
    {        
        while (a - b > 0) a -= b;
        variablen_tauschen(&a, &b);
    }

    return a;
}

// long ggt_n_rekursiv(long zahlen[], int n)
// {
//     if (n == 1) return zahlen[0];

//     if (n % 2 == 0) n = n / 2;
//     else n = (n / 2) + 1;
    
//     for (size_t i = 0; i < n; i++)
//     {
//         zahlen[i] = ggt(zahlen[2 * i], zahlen[2 * i + 1]);
//     }

//     ggt_n(zahlen, n);
// }

long ggt_n(long zahlen[], int n)
{
    long ggt_ = ggt(zahlen[0], zahlen[1]);
    
    for (size_t i = 2; i < n; i++)
    {
        ggt_ = ggt(zahlen[i], ggt_);
    }
    
    return ggt_;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cout << "Anzahl an Zahlen: ";
    std::cin >> n;

    long zahlen[n];
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "Zahl" << i << ": ";
        std::cin >> zahlen[i];
    }

    std::cout << "ggT: " << ggt_n(zahlen, n) << std::endl;    

    return 0;
}
