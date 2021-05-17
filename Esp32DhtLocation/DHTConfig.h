
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 34      // Wont interfere with WiFi connectivity
#define DHTTYPE DHT11  // Just the booring old DHT11
#define CELCIUS 0
#define FARENHEIT 1
DHT dht(DHTPIN, DHTTYPE);

//Globaly accessable Sensordata
float tempCelcius = NAN;
float heatIndexCelcius = NAN;

float humi = NAN;

float tempFarenheit = NAN;
float heatIndexFarenheit = NAN;

void CheckSensorDataCelcius() 
{
  tempCelcius = dht.readTemperature();
  humi = dht.readHumidity();
  heatIndexCelcius = dht.computeHeatIndex(tempCelcius,humi,CELCIUS);
}

void CheckSensorDataFarenheit()
{
  tempFarenheit = dht.convertCtoF(tempCelcius);
  heatIndexFarenheit = dht.computeHeatIndex(FARENHEIT);

  
} 
