#include <iostream>
#include <vector>

/*
    first-in-first-out Warteschlange
*/
template <typename T> class Warteschlange
{
private:
    int MAX_LAENGE, laenge;
    T DEFAULT_ELEMENT;      //  Element das von pop_erstes_element zurückgegeben wird, wenn die Warteschlange leer ist
    std::vector<T> liste;

    bool ist_leer();
    bool ist_voll();

public:
    Warteschlange(int max_laenge, T default_element);
    
    /*
        Fügt das übergebene Element zur Warteschlange hinzu.
        Gibt 0 zurück wenn das Hinzufügen funktioniert hat und 1 wenn die Warteschlange falsch ist.
    */
    int element_hinzufuegen(T element);
    /*
        Gibt das erste Element der Warteschlange zurück und entfernt es aus dieser.
        Ist die Warteschlange leer wird das DEFAULT_ELEMENT zurückgegeben.
    */
    T pop_erstes_element();
};

template <typename T> Warteschlange<T>::Warteschlange(int max_laenge, T default_element)
{
    MAX_LAENGE = max_laenge;
    DEFAULT_ELEMENT = default_element;
    laenge = 0;
}

template <typename T> bool Warteschlange<T>::ist_leer()
{
    return laenge <= 0;
}

template <typename T> bool Warteschlange<T>::ist_voll()
{
    return laenge >= MAX_LAENGE;
}

template <typename T> int Warteschlange<T>::element_hinzufuegen(T element)
{
    if (this->ist_voll())
    {
        std::cerr << "Die Warteschlange ist voll!";
        return 1;
    }
    laenge += 1;
    liste.push_back(element);
    return 0;
}

/*
    Gibt das erste Element der Warteschlange zurück und entfernt es aus ihr.
*/
template <typename T> T Warteschlange<T>::pop_erstes_element()
{
    if (Warteschlange<T>::ist_leer())
    {
        std::cerr << "Die Warteschlange ist leer!";
        return DEFAULT_ELEMENT;
    }
    laenge -= 1;
    T element = *liste.begin();
    liste.erase(liste.begin());
    return element;
}
