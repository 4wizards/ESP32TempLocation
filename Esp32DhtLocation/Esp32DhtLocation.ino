#include "Includes.h"

//Main file

void setup() 
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    delay(500);
    WiFiConnectionInit();
    dhtSensor.begin();

}

void loop() 
{
  while(WiFi.status() == WL_CONNECTED)
  {
    Serial.println(".");
    delay(1000);
    
  }
  
}
