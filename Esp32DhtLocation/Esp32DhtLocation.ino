#include "config.h"
#include "WiFiConnectionConfig.h"
#include "HTTPPostConfig.h"
#include "DHTConfig.h"
#include "GoogleMapsApi.h"
#include "EpochTimeConfig.h"

//Main file

void setup() 
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    delay(500);
    WiFiConnectionInit();// This Section should be started before other functions, Without WiFi nothing will work....
    dht.begin();
    gpsInit()

}

void loop() 
{
  while(WiFi.status() == WL_CONNECTED)
  {
    Serial.println(".");
    delay(1000);
    
  }
  
}
