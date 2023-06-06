#ifndef MSG_H
#define MSG_H

/*
    Definitionen der verschiedenen Nachrichten zur Kommunikation zwischen Flugzeugen, GC, AC und Airport
*/

#define MSG_ABSTURZ 0
#define MSG_FLUG_UMGELEITET 1

//  landen
#define MSG_LANDUNG_ANFORDERN 10
#define MSG_LANDUNG AKZEPTIERT 11
#define MSG_LANDUNG_VERZÖGERT 12
#define MSG_FLUGZEUT_LANDET 13

//  starten
#define MSG_START_ANFORDERN 20
#define MSG_START_AKZEPTIERT 21
#define MSG_START_VERZÖGERT 22
#define MSG_FLUGZEUG_STARTET 23

#endif