# PAM_WiFiClient

Wrapper for the ESP8266Wifi.h with a lot of commonly used functions to allow for getting a webpage.

It contains the following functions:
//
// There are four members in the family of functions for getURL:
// - getURLParse which is the main function that the others use
// - getURL which is a fire and forget request type. It does return the last line for error messages, if needed
// - getURLBodyParse which sends all the body lines through a supplied function
// - getURLFullParse which sends all lines, header and body, through a supplied function
//
// Each of these functions exists in two variations, one with a supplied port and one without
// in which case port 80 is assumed.
//

//
// getURLParse, get the url url from the host host on port port and send each line 
// through the function g. The boolean fullContent determines whether only the header lines
// or all lines are send through to the function g
//
String getURLParse (String host, String url, bool fullContent, void (*g)(String l), int port)
String getURLParse (String host, String url, bool fullContent, void (*g)(String l))
String getURLFullParse (String host, String url, void (*g)(String l), int port)
String getURLFullParse (String host, String url, void (*g)(String l))
String getURLBodyParse (String host, String url, void (*g)(String l), int port)
String getURLBodyParse (String host, String url, void (*g)(String l))
String getURL (String host, String url, int port)
String getURL (String host, String url)

//
// The urlEncode function will do as it's name suggest, convert
// a char array to a url encoded String.
//
String urlEncode (const char* msg)

//
// The doNothing function which is used as a parameter if we do not care about
// the webpage result, aka fire and forget
//
void doNothing (String webLine)

//
// The doSerial function which is used as a parameter if we want to see all output
// of the requested webpage.
//
void doSerial (String webLine)

You can read about it in more detail on https://piandmore.wordpress.com/tag/pam_wificlient
