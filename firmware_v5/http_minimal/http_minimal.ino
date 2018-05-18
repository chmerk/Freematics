#include <FreematicsPlus.h>
#include "HTTPsfde.h"

// #define STATE_NET_READY 0x10

#define WIFI_SSID "WIFI SSID" 
#define WIFI_PASSWORD "WIFI PASSWORD"

#define HTTP_HOST "http://ptsv2.com/t/freemsimtest/post"
// #define HTTP_PORT 80

// #define HTTP_API_KEY "OPTIONAL API KEY"
// #define HTTP_CONTENT_TYPE "application/json"

// class State {
// public:
//   bool check(byte flags) { return (m_state & flags) == flags; }
//   void set(byte flags) { m_state |= flags; }
//   void clear(byte flags) { m_state &= ~flags; }
// private:
//   byte m_state = 0;
// };

// State state;

UDPClientWIFI net;
HTTPClientX http; 

const char* data = "Hallo duda!";

void setup() {

    Serial.begin(115200);
    Serial.println("Starting to begin! ;-)");

    for (byte attempts = 0; attempts < 3; attempts++) {
        if (!net.begin()) continue;
        Serial.print("WIFI(SSID:");
        Serial.print(WIFI_SSID);
        Serial.print(")...");
        if (net.setup(WIFI_SSID, WIFI_PASSWORD)) {
            //BLE.println("WIFI OK");
            Serial.println("OK");
            //state.set(STATE_NET_READY);
            break;
        } else {
            Serial.println("NO");
        }
    }

    if (!http.open(HTTP_HOST)){
        Serial.println("HTTP: NO");
    } else {
        Serial.println("HTTP: YES");
        //http.addHeader("Content-Type", HTTP_CONTENT_TYPE);
        //http.addHeader("x-im-apikey", HTTP_API_KEY);
    }

    http.send(data);
}

void loop() {

}
