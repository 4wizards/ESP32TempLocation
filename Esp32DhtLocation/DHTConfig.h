
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 34      // Wont interfere with WiFi connectivity
#define DHTTYPE DHT11  // Just the booring old DHT11

DHT dht(DHTPIN, DHTTYPE);
