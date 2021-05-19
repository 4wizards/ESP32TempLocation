
#include "includes.h"

void setup() {
 
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
    refreshEpochTime();
    checkSensorDataCelcius();
    //if (currentTemp > (previousTemp + tempDiff) || currentTemp < (previousTemp - tempDiff))
    //{
        sendFunction(parseDataToJson());
        serialPrintDataSets(); // Uncomment if serial check is necessary

    //}
    delay(SLEEPTIME);
  }
  
}
