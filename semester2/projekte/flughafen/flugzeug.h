#ifndef FLUGZEUG_H
#define FLUGZEUG_H

class Flugzeug
{
private:
    int zeit_seit_spawn;
    bool ist_in_der_luft;
    void *flughafen;    //  muss void sein, um Include von Airport zu vermeiden, da ansonsten ein Kreis aus Includes entsteht

    void call_flughafen(int msg);

public:
    int flugnummer;
    bool ist_abgestürzt;
    Flugzeug(void *flughafen, bool ist_in_der_luft);

    void tick();    //  updated das Flugzeug und seine Werte
};

#endif