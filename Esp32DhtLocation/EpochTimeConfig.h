
// Time Lib
#include "time.h"

// Variable to save current epoch time
unsigned long epochTime;

void initializeCurrentlLocationTime()
{

  // NTP server to request epoch time
  const char *ntpServer = "pool.ntp.org";
  // Fetch Local Time API
  const char *timeApiUrl = "http://worldtimeapi.org/api/ip";
  const char *timeNistUrl = "time.nist.gov";
  HTTPClient httpSocketClient;

  httpSocketClient.begin(timeApiUrl);

  int httpCode = httpSocketClient.GET();

  if (httpCode != 200)
  {
    printf("EPOCH API Probs ? \r\n");
    configTime(0, 0, ntpServer,timeNistUrl);
    return;
  }
  String response = httpSocketClient.getString();
  long offset = response.substring(response.indexOf("\"raw_offset\":") + 13, response.indexOf(",\"timezone\":")).toFloat();
  httpSocketClient.end();

  configTime(offset, 0, ntpServer);
  
}

void refreshEpochTime()
{
  epochTime = time(NULL);
}

