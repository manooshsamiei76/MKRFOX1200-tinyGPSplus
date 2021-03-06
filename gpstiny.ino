
#include <TinyGPS++.h>
#include <SigFox.h>

float lngGPS = 0; // longitude
float latGPS = 0; // latitude
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;

void setup() 
{
  Serial.begin(115200);
  Serial1.begin(GPSBaud);
}

void loop() 
{

  if (gps.altitude.isUpdated() || gps.satellites.isUpdated() )
  {
    latGPS = gps.location.lat(); 
    lngGPS = gps.location.lng(); 
    Serial.print(" Latitude: "); 
    Serial.println(latGPS ,6); // print up to 6 digits
    Serial.print(" Longitude: ");
    Serial.println(lngGPS, 6); // print up to 6 digits
    delay(500);
  }

  while (Serial1.available() > 0)
    gps.encode(Serial1.read());
}

