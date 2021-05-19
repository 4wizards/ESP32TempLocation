#include "WifiLocation.h"
//GPS Coordinates in globaly reachable variables
float latitude = 0.0;
float longitude = 0.0;

WifiLocation location(SECRET_GOOGLEAPI);

void locationInit()
{

  location_t loc = location.getGeoFromWiFi();
  latitude = float(loc.lat);
  longitude = float(loc.lon);

  //Serial Monitor print-outs
  
  Serial.println("Location request data");
  Serial.println(location.getSurroundingWiFiJson());
  Serial.println("Latitude: " + String(loc.lat, 7));
  Serial.println("Longitude: " + String(loc.lon, 7));
  Serial.println("Accuracy: " + String(loc.accuracy));

}
