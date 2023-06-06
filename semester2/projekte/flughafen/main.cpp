#include <iostream>
#include <vector>
#include <ctime>
#include <zeit.h>
#include <warteschlange.cpp>
#include <airport.h>
#include <flugzeug.h>

#define rote_beete 0

int main(int argc, char const *argv[])
{
    std::srand(std::time(nullptr));

    //  initialisiert die simulierte Zeit als 2023-06-05 19:22:00
    Zeit zeit(2023, 6, 5, 19, 22, 0);

    Airport airport(&zeit);

    Flugzeug f(&airport, true);
    int a = 0;
    while (1)
    {
        if (a < 100 && a >= 0) Flugzeug a(&airport, true);
        a += 1;

        zeit.tick();    //  lässt die simulierte Zeit um eine Sekunde weiterlaufen

        airport.tick();
    }
    
    return 0;
}
