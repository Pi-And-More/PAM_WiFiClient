#ifndef PAM_WiFiClient_H
#define PAM_WiFiClient_H

//
// URLNOCONNECT is returned if the connection to the host could not be made
//
#define URLNOCONNECT "ERR:noconnect"
//
// URLTIMEOUT is returned if a connection was made but the retrieving the
// page timed out
//
#define URLTIMEOUT "ERR:timeout"

#include <Arduino.h>

String getURL (String, String);
String getURL (String, String, int);
String getURLFullParse (String, String, void (*)(String));
String getURLFullParse (String, String, void (*)(String), int);
String getURLBodyParse (String, String, void (*)(String));
String getURLBodyParse (String, String, void (*)(String), int);
String getURLParse (String, String, bool, void (*)(String));
String getURLParse (String, String, bool, void (*)(String), int);
void doNothing (String);
void doSerial (String);

#endif
