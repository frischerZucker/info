#include <iostream>
using namespace std;

void mergesort(int *liste, int anfang_der_liste, int ende_der_liste);
void merge(int *liste, int l, int r, int ende_rechte_liste);
 
void mergesort(int *liste, int anfang_der_liste, int ende_der_liste)
{
    if (anfang_der_liste == ende_der_liste) return;

    int mitte_der_liste = (anfang_der_liste + ende_der_liste) / 2;

    mergesort(liste, anfang_der_liste, mitte_der_liste);
    mergesort(liste, mitte_der_liste + 1, ende_der_liste);

    merge(liste, anfang_der_liste, mitte_der_liste, ende_der_liste);
}

void merge(int *liste, int l, int r, int ende_rechte_liste)
{
    int l2 = r + 1;
 
    while (l <= r && l2 <= ende_rechte_liste) 
    {
        if (liste[l] >= liste[l2])  
        {
            int tmp = liste[l2];
            
            for (size_t i = l2; i > l; i -= 1)
            {
                liste[i] = liste[i - 1];
            }
            
            liste[l] = tmp;
 
            r++;
            l2++;
        }
        l++;
    }
}
 
int main()
{
    int a[] = {4, 6, 1, 2, 78, 3, 1, 12};
    int n = 8;
 
    mergesort(a, 0, n - 1);
 
    for (size_t i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}