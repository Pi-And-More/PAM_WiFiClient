//////////////////////////////////////////////////////////////////////
//
//                    PI and more
//              PAM_WiFiClient library
//
// https://piandmore.wordpress.com/tag/pam_wificlient
//
//////////////////////////////////////////////////////////////////////
//
// Include the PAM_WiFiClient header
//
#include <PAM_WiFiClient.h>

//
// Include the ESP8266WiFi library
//
#include <ESP8266WiFi.h>

//
// The urlEncode function will do as it's name suggest, convert
// a char array to a url encoded String.
//
String urlEncode (const char* msg) {
  const char *hex = "0123456789abcdef";
  String encodedMsg = "";

  while (*msg!='\0') {
    if (('a'<=*msg && *msg<='z') || ('A'<=*msg && *msg<='Z') || ('0'<=*msg && *msg<='9') || *msg=='/') {
      encodedMsg += *msg;
    } else {
      encodedMsg += '%';
      encodedMsg += hex[*msg >> 4];
      encodedMsg += hex[*msg & 15];
    }
    msg++;
  }
  return encodedMsg;
}

//
// The doSerial function which is used as a parameter if we want to see all output
// of the requested webpage.
//
void doSerial (String webLine) {
  Serial.println(webLine);
}

//
// The doNothing function which is used as a parameter if we do not care about
// the webpage result, aka fire and forget
//
void doNothing (String webLine) {
}

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
String getURLParse (String host, String url, bool fullContent, void (*g)(String l), int port) {
  String lastline;
  boolean inPage;
  inPage = false;
  WiFiClient client;
  char xhost[50];
  host.toCharArray(xhost,50);
  //
  // Try to connect to the host. If unsuccesful, quit the function with the error URLNOCONNECT
  //
  if (!client.connect(xhost,port)) {
    return URLNOCONNECT;
  }
  //
  // Send the HTTP GET request
  //
  client.print("GET " + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  //
  // Wait for an answer but if none is given within 5 seconds
  // quite the function with the error URLTIMEOUT
  //
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      client.stop();
      return URLTIMEOUT;
    }
  }
  //
  // Go through all the lines. When we encounter an empty line
  // we know that the header is done and the remaining lines
  // are the body of the page. The boolean inPage, which initially
  // is set to false, will turn true. The function g is called if
  // if want the full content to be send to the function,
  // boolean fullContent, or if we are in the main page.
  //
  lastline = "";
  while(client.available()){
    String line = client.readStringUntil('\r');
    line.replace("\n","");
    if (line.length()>0) {
      lastline = line;
    }
    if (fullContent || inPage) {
      g(line);
    }
    if (line.length()==0) {
      inPage = true;
    }
  }
  return lastline;
}

String getURLParse (String host, String url, bool fullContent, void (*g)(String l)) {
  return getURLParse(host,url,fullContent,g,80);
}

String getURLFullParse (String host, String url, void (*g)(String l), int port) {
  return getURLParse(host,url,true,g,port);
}

String getURLFullParse (String host, String url, void (*g)(String l)) {
  return getURLParse(host,url,true,g,80);
}

String getURLBodyParse (String host, String url, void (*g)(String l), int port) {
  return getURLParse(host,url,false,g,port);
}

String getURLBodyParse (String host, String url, void (*g)(String l)) {
  return getURLParse(host,url,false,g,80);
}

String getURL (String host, String url, int port) {
  return getURLParse(host,url,false,doNothing,port);
}

String getURL (String host, String url) {
  return getURLParse(host,url,false,doNothing,80);
}
