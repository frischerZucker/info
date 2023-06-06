#include <zeit.h>

#define MAX_SEKUNDEN 60
#define MAX_MINUTEN 60
#define MAX_STUNDEN 24
#define MAX_TAGE 30
#define MAX_MONATE 12
#define MAX_JAHRE 69420

Zeit::Zeit(int j, int m, int t, int h, int min, int s)
{
    jahr = j;
    monat = m;
    tag = t;
    stunden = h;
    minuten = min;
    sekunden = s;
}

std::string Zeit::get_time()
{
    std::string zeit_string;

    zeit_string += std::to_string(jahr) + "-";
    zeit_string += ((monat < 10) ? "0" : "") + std::to_string(monat) + "-";
    zeit_string += ((tag < 10) ? "0" : "") + std::to_string(tag) + " ";
    zeit_string += ((stunden < 10) ? "0" : "")  + std::to_string(stunden) + ":";
    zeit_string += ((minuten < 10) ? "0" : "")  + std::to_string(minuten) + ":";
    zeit_string += ((sekunden < 10) ? "0" : "")  + std::to_string(sekunden);

    return zeit_string;
}

void Zeit::tick()
{
    sekunden += 1;
    if (sekunden <= MAX_SEKUNDEN) return;

    sekunden = 0;
    minuten += 1;
    if (minuten <= MAX_MINUTEN) return;

    minuten = 0;
    stunden += 1;
    if (stunden <= MAX_STUNDEN) return;

    stunden = 0;
    tag += 1;
    if (tag <= MAX_TAGE) return;

    tag = 0;
    monat += 1;
    if (monat <= MAX_MONATE) return;

    monat = 0;
    jahr += 1;
    if (minuten <= MAX_JAHRE) jahr = 0;
}
