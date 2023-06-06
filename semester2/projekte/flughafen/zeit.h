#ifndef ZEIT_H
#define ZEIT_H

#include <string>

class Zeit
{
private:
    int jahr, monat, tag, stunden, minuten, sekunden;

public:
    Zeit(int j, int m, int t, int h, int min, int s);

    //  lässt die Zeit eine Sekunde weiterlaufen
    void tick();
    //  gibt die aktuelle Zeit als String im Format YYYY-MM-DD hh:mm:ss
    std::string get_time();
};

#endif