#include <iostream>

/*
    Übung 1, Aufgabe 2
    ---
    ggT zweier Zahlen
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

long ggT(long a, long b)
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

//  ggT mit Zwischenergebnissen
long ggT_v(long a, long b)
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
        while (a - b > 0) 
        {
            a -= b;
            std::cout << "a=" << a << ", b=" << b << std::endl;
        }
        variablen_tauschen(&a, &b);
    }

    return a;
}

int main()
{
    long a, b;

    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    std::cout << ggT(std::abs(a), std::abs(b));    
    // std::cout << ggT_v(std::abs(a), std::abs(b));

    return 0;
}
