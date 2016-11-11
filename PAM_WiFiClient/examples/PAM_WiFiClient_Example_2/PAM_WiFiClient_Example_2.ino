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

bool foundRed = false;

void myReader (String webline) {
  if (webline.indexOf("Red")!=-1) {
    foundRed = true;
  }
}

void setup() {
  wifiConnect("YourSSID","YourPassword");
  getURLBodyParse("somehost.domain.com","/somePageLookingForRed.html",myReader);
}

void loop() {

}
