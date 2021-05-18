
//GPS Coordinates in globaly reachable variables
float latitude = 0.0;
float longitude = 0.0;
double accuracy = 0.0;

WifiLocation location(GOOGLE_MAPS_API);

void locationInit()
{

  location_t loc = location.getGeoFromWiFi();
  latitude = loc.lat;
  longitude = loc.lon;

  //Serial Monitor print-outs
  
  Serial.println("Location request data");
  
  Serial.println("Latitude: " + String(loc.lat, 7));
  Serial.println("Longitude: " + String(loc.lon, 7));
  Serial.println("Accuracy: " + String(loc.accuracy));

}