
#include "time.h"
// Variable to save current epoch time
unsigned long epochTime; 

void EpochTimeInit()
{
  configTime(3600, 0, "pool.ntp.org", "time.nist.gov");
  while (true)
    {
      epochTime = time(NULL);

      if (epochTime == 28800) {
        delay(2000);
      }
      else
      {
        break;
      }
    }
    Serial.printf("Epochtime Initialized. Current Time %lu", epochTime);
}
