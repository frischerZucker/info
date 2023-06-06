#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include <messages.h>
#include <zeit.h>
#include <flugzeug.h>

class Airport
{
private:
    std::vector<Flugzeug> flugzeuge;
    Zeit *zeit;
    
public:
    Airport(Zeit *zeit);
    ~Airport();

    void tick();
    void receive_call(int msg, void *flugzeug);
};

#endif