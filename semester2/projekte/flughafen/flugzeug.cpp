#include <ctime>
#include <iostream>
#include <chrono>
#include <flugzeug.h>
#include <airport.h>

#define ZEIT_BIS_ABSTURZ 200000   // Zeit die ein neu erschaffenes Flugzeug bis zum Absturz hat, 7200 Sekunden

Flugzeug::Flugzeug(void *flughafen, bool ist_in_der_luft)
{
    std::srand(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
    flugnummer = rand();
    this->ist_in_der_luft = ist_in_der_luft;
    ist_abgestürzt = false;
    this->flughafen = flughafen;
    zeit_seit_spawn = 0;

    //  fordert beim Flughafen eine Landung / einen Start an
    if (ist_in_der_luft) call_flughafen(MSG_LANDUNG_ANFORDERN);
    else call_flughafen(MSG_START_ANFORDERN);
}

//  sendet die übergebene Nachricht an den Flughafen
void Flugzeug::call_flughafen(int msg)
{
    ((Airport *)flughafen)->receive_call(msg, (void *) this);
}

//  updated das Flugzeug
void Flugzeug::tick()
{   
    // lässt das Flugzeug abstürzen wenn seine maximale Flugzeit überschritten ist und es nicht schon am Boden ist
    if ((zeit_seit_spawn >= ZEIT_BIS_ABSTURZ) && ist_in_der_luft)
    {
        ist_abgestürzt = true;
        call_flughafen(MSG_ABSTURZ);
    }

    zeit_seit_spawn += 1;
}