#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

float Temp = 0;

void DS18B20setup()
{
  sensors.begin();  // Start up the library
}

void getDS18B20()
{ 

  sensors.requestTemperatures(); 
  
  Temp = sensors.getTempCByIndex(0);

  delay(500);
}
