/******************************************************************************
* Custom HTTP Class for SFDE Project...
* Work in progress
******************************************************************************/

#include <HTTPClient.h>

//To Do:
//Klasse HTTPClientX noch umbenennen
//Methodenrümpfe in .cpp Datei auslagern?!?
class HTTPClientX : public HTTPClient 
{
  public:
    bool open(String host, int port) {   //port wird bisher nicht verwendet
      if (HTTPClient::begin(host)) {
        Serial.println("Opened HTTP connection!");
      }
      
    }
    bool send(const char* data) {
      Serial.print("Sending Data: ");
      int postResult = HTTPClient::sendRequest("POST", data);
      Serial.print("POST: ");
      Serial.println(postResult);
      return true;
    }
};