#include <iostream>
#include <airport.h>

Airport::Airport(Zeit *zeit)
{
    this->zeit = zeit;
}

Airport::~Airport()
{
}

void Airport::tick()
{
    //  updated alle flugzeuge
    auto itr = flugzeuge.begin();
    for (size_t i = 0; i < flugzeuge.size(); i++) 
    {
        flugzeuge.at(i).tick();
        if (flugzeuge.at(i).ist_abgestürzt) flugzeuge.erase(flugzeuge.begin() + i);
    }

    if (flugzeuge.size() > 0) std::cout << "#flugzeuge: " << flugzeuge.size() << std::endl;
}

/*
    wird aufgerufen um eine Nachricht an den Flughafen zu senden
*/
void Airport::receive_call(int msg, void *sender)
{
    switch (msg)
    {
    case MSG_ABSTURZ:
        std::cout << zeit->get_time() << ": Flug " << ((Flugzeug *) sender)->flugnummer << " ist abgestürzt." << std::endl;
        break;
    
    case MSG_LANDUNG_ANFORDERN:
        std::cout << zeit->get_time() << ": Flug " << ((Flugzeug *) sender)->flugnummer << " fordert Landung an." << std::endl;
        flugzeuge.push_back(*((Flugzeug *) sender));
        break;
    
    case MSG_START_ANFORDERN:
        std::cout << zeit->get_time() << ": Flug " << ((Flugzeug *) sender)->flugnummer << " fordert start an." << std::endl;
        flugzeuge.push_back(*((Flugzeug *) sender));
        break;

    default:
        break;
    }
}
