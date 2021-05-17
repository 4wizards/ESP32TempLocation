
#include "HTTPClient.h"
#include <WiFi.h>
#include <Arduino_JSON.h>


// Wifi Hotspot connection settings and functions
//Here we create the login credentials for the wifi connection

const char *SSID = "WIFI_SSID";
const char *PWD = "WIFI_PASSWORD";

void WiFiConnectionInit()
{
  WiFi.begin(SSID, PWD);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) 
  {
    delay(666);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("------------YOU ARE NOW CONNECTED TO THE INTERNET-------------");
  Serial.println(" Connected to the Wireless network of spells with IP Address: ");
  Serial.println(WiFi.localIP());
}
