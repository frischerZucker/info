#include <iostream>
#include <map>
#define rote_beete 0

/*
    Nimmt ein nichtleeres Int-Array und dessen Länge an und gibt das Element zurück, das am häufigsten in diesem vorkommt.
    Kommen mehrere Zahlen mit der maximales Häufigkeit vor, wird davon die mit dem niedrigsten Index im übergebenen Array zurückgegeben.
*/
int plateau(int A[], int n)
{
    if (n == 1) return A[0];

    std::map<int, int> zahlen_anzahl;
    
    /*
        geht alle Werte des Arrays durch und erhöht den in der Map zu diesem Wert (als Key) gehörenden Wert
    */
    for (size_t i = 0; i < n; i++) 
    {
        zahlen_anzahl[A[i]] += 1;
    }
    
    /*
        geht die Map durch und legt den Key als plateau fest, der den größten zu ihm gehörenden Wert hat
    */
    auto itr = zahlen_anzahl.begin();
    int plateau = itr->first;
    for (itr; itr != zahlen_anzahl.end(); itr++)
    {
        if (itr->second > zahlen_anzahl[plateau]) plateau = itr->first;
    }    

    return plateau;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 4, 5, 2, 1, 4, 6, 9, 0, 4, 0, 5, 3, 5, 4, 1, 7, 5};
    int n = 24;

    std::cout << "Plateau: " << plateau(a, n) << std::endl;

    return 0;
}
