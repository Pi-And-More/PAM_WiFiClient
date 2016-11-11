//////////////////////////////////////////////////////////////////////
//
//                    PI and more
//              PAM_WiFiClient library
//
// https://piandmore.wordpress.com/tag/pam_wificlient
//
//////////////////////////////////////////////////////////////////////
//
// Include the PAM_WiFiClient library
//
#include <PAM_WiFiClient.h>
//
// Include the PAM_WiFiConnect library
//
#include <PAM_WiFiConnect.h>

void setup() {
  wifiConnect("YourSSID","YourPassword");
  getURL("myhost.domain.com","/index.php?started=myhost");
}

void loop() {

}
