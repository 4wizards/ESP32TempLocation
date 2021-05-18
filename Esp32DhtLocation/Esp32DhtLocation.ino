

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

<<<<<<< Updated upstream
void loop() {
  Serial.println(WIFI_HOTSPOTNAME);
  // put your main code here, to run repeatedly:

=======
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
    delay(1000*10);
  }
  
>>>>>>> Stashed changes
}
