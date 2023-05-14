#include <iostream>
#define rote_beete 0

int *merge(int *linke_liste, int n_links, int *rechte_liste, int n_rechts);
int *mergesort(int *liste, int n);

void mergesort_ip(int *liste, int anfang_der_liste, int ende_der_liste);
void merge_ip(int *liste, int l, int r, int ende_rechte_liste);

int *mergesort(int *liste, int n)
{
    if (n <= 1) return liste;

    int *linke_liste, *rechte_liste;
    int n_links, n_rechts;

    linke_liste = liste;
    n_links = n / 2;
    rechte_liste = (liste + n / 2);
    n_rechts = n - n_links;

    linke_liste = mergesort(linke_liste, n_links);
    rechte_liste = mergesort(rechte_liste, n_rechts);

    return merge(linke_liste, n_links, rechte_liste, n_rechts);
}

int *merge(int *linke_liste, int n_links, int *rechte_liste, int n_rechts)
{
    int *neue_liste = (int*) malloc(sizeof(int) * (n_links + n_rechts));
    int i = 0, l = 0, r = 0;
    
    while (l < n_links && r < n_rechts)
    {
        if (linke_liste[l] <= rechte_liste[r])
        {
            neue_liste[i] = linke_liste[l];
            l += 1;
        }
        else
        {
            neue_liste[i] = rechte_liste[r];
            r += 1;
        }
        i += 1;
    }
    
    while (l < n_links)
    {
        neue_liste[i] = linke_liste[l];
        l += 1;
        i += 1;
    }
    while (r < n_rechts)
    {
        neue_liste[i] = rechte_liste[r];
        r += 1;
        i += 1;
    }

    return neue_liste;
}

void mergesort_ip(int *liste, int anfang_der_liste, int ende_der_liste)
{
    // Liste hat nur noch ein Element
    if (anfang_der_liste == ende_der_liste) return;

    int mitte_der_liste = (anfang_der_liste + ende_der_liste) / 2;

    mergesort_ip(liste, anfang_der_liste, mitte_der_liste);
    mergesort_ip(liste, mitte_der_liste + 1, ende_der_liste);

    merge_ip(liste, anfang_der_liste, mitte_der_liste, ende_der_liste);
}

void merge_ip(int *liste, int l, int r, int ende_rechte_liste)
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

int main(int argc, char const *argv[])
{
    int a[] = {4, 6, 1, 2, 78, 3, 1, 12};
    int n = 8;

    // int *c = mergesort(a, n);
    mergesort_ip(a, 0, n - 1);

    for (size_t i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
