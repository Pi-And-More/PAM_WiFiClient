# PAM_WiFiClient

Wrapper for the ESP8266Wifi.h with a lot of commonly used functions to allow for getting a webpage.

It contains the following functions:
//
// getURLParse, get the url url from the host host on port port and send each line 
// through the function g. The boolean fullContent determines whether only the header lines
// or all lines are send through to the function g
//
String getURLParse (char* host, String url, bool fullContent, void (*g)(String l), int port)
String getURLFullParse (char* host, String url, void (*g)(String l), int port)
String getURLBodyParse (char* host, String url, void (*g)(String l), int port)
String getURL (char* host, String url, int port)

You can read about it in more detail on https://piandmore.wordpress.com/tag/pam_wificlient
