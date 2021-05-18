
// Json Lib
#include <ArduinoJson.h>

DynamicJsonDocument parseDataToJson()
{

  DynamicJsonDocument package(2048);


    // Prepare JSON document with correct array structure
  JsonObject deviceData = package.to<JsonObject>();
  JsonObject locationData = package.to<JsonObject>();
  JsonObject measurementData = package.to<JsonObject>();
    
  
  deviceData["deviceName"]      = deviceName;
  deviceData["mcuType"]         = mcuType;
  deviceData["sensorType"]      = sensorType;

  locationData["latitude"]      = latitude;
  locationData["longitude"]     = longitude;

  measurementData["temp"]       = tempCelcius;
  measurementData["humi"]       = humi;
  measurementData["heatIndex"]  = heatIndexCelcius;


  // Serialize JSON document
  String jsonPackage;
  serializeJson(package, jsonPackage);

  return package;
}


bool sendFunction(String jsonPackage)
{
  HTTPClient http;

  // Send request
  http.begin(serverName);
  int httpResponse = http.POST(jsonPackage);
  
  if(!http.POST(jsonPackage))
  {
    Serial.println("Failed to send package");
    return false;
  }

    // Read response and print to console
  Serial.println(http.getString() + " Has been sent");

  // Disconnect
  http.end();
  return true;
}
