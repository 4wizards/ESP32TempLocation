
#include "includes.h"

void setup() {
 
  Serial.begin(115200);
  delay(100);
  WiFiConnectionInit();// This Section should be started before other functions, Without WiFi nothing will work....
  dht.begin();
  newLocationApiGet(getMyPublicIP());
  initializeCurrentlLocationTime();
  refreshEpochTime();
  delay(100);
  
}

void loop() 
{
  while(WiFi.status() == WL_CONNECTED)
  {
    refreshEpochTime();
    checkSensorDataCelcius();
    
    //if (currentTemp > (previousTemp + tempDiff) || currentTemp < (previousTemp - tempDiff))
    //{
        if(epochTime> 1600000000){
        sendFunction(parseDataToJson());
        serialPrintDataSets(); // Uncomment if serial check is necessary
        }
    //}
    delay(SLEEPTIME);
  }
  
}
