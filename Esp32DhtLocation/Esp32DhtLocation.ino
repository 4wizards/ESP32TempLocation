#include "includes.h"

//Main file 

void setup() 
{
    Serial.begin(115200);
    delay(100);
    WiFiConnectionInit();// This Section should be started before other functions, Without WiFi nothing will work....
    delay(100);
    dht.begin();
    delay(100);
    locationInit();
    delay(100);
    initializeCurrentlLocationTime();

}

void loop() 
{
  while(WiFi.status() == WL_CONNECTED)
  {
    checkSensorDataCelcius();
    if (currentTemp > (previousTemp + tempDiff) || currentTemp < (previousTemp - tempDiff))
    {
      
    }
    
  }
  
}
