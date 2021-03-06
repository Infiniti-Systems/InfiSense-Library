#include <Arduino.h>
#line 1 "c:\\Users\\ARPIT\\Documents\\Arduino\\libraries\\InfiSense-Library\\examples\\InfiSense-Example-Code\\InfiSense-Example-Code.ino"
/* 
  SFE_BMP180 altitude example sketch

  This sketch shows how to use the Bosch BMP180 pressure sensor
  as an altimiter.
  https://www.sparkfun.com/products/11824

  Like most pressure sensors, the BMP180 measures absolute pressure.
  Since absolute pressure varies with altitude, you can use the pressure
  to determine your altitude.

  Because pressure also varies with weather, you must first take a pressure
  reading at a known baseline altitude. Then you can measure variations
  from that pressure

  Hardware connections:

  - (GND) to GND
  + (VDD) to 3.3V

  (WARNING: do not connect + to 5V or the sensor will be damaged!)

  You will also need to connect the I2C pins (SCL and SDA) to your
  Arduino. The pins are different on different Arduinos:

  Any Arduino pins labeled:  SDA  SCL
  Uno, Redboard, Pro:        A4   A5
  Mega2560, Due:             20   21
  Leonardo:                   2    3

  Leave the IO (VDDIO) pin unconnected. This pin is for connecting
  the BMP180 to systems with lower logic levels such as 1.8V

  Have fun! -Your friends at SparkFun.

  The SFE_BMP180 library uses floating-point equations developed by the
  Weather Station Data Logger project: http://wmrx00.sourceforge.net/

  Our example code uses the "beerware" license. You can do anything
  you like with this code. No really, anything. If you find it useful,
  buy me a beer someday.

  V10 Mike Grusin, SparkFun Electronics 10/24/2013
  V1.1.2 Updates for Arduino 1.6.4 5/2015
*/

#include "InfiSense.h"
#include "InfiCloud.h"

#define TOKEN "1sfdg12fg4sfda2fsgag5ehg5g1sfaA" // Put here your Ubidots TOKEN
#define WIFI_SSID "INFINITY"                    // Put here your Wi-Fi SSID
#define WIFI_PASSWORD "        "                // Put here your Wi-Fi password
#define HOST_ADDRESS "http://ptsv2.com/t/306ro-1551957130/post"
//http://ptsv2.com/t/306ro-1551957130/post        FOR data post on test site
//http://ptsv2.com/t/306ro-1551957130             for checking dumps through browser

InfiSense agri;
InfiCloud client(TOKEN);
LcdDisplay lcd;

boolean DEBUG_InfiSense = false;

#line 63 "c:\\Users\\ARPIT\\Documents\\Arduino\\libraries\\InfiSense-Library\\examples\\InfiSense-Example-Code\\InfiSense-Example-Code.ino"
void setup();
#line 72 "c:\\Users\\ARPIT\\Documents\\Arduino\\libraries\\InfiSense-Library\\examples\\InfiSense-Example-Code\\InfiSense-Example-Code.ino"
void loop();
#line 63 "c:\\Users\\ARPIT\\Documents\\Arduino\\libraries\\InfiSense-Library\\examples\\InfiSense-Example-Code\\InfiSense-Example-Code.ino"
void setup()
{
  Serial.begin(9600);
  agri.begin(DEBUG_InfiSense);
  lcd.begin();
  client.setDebug(true);
  client.attachLEDToStatus(true);
}

void loop()
{
  // agri.readSoilSensor();
  float temperature = agri.readDS18B20();
  float UVIndex = agri.readUVSensor();
  // agri.readML8511();
  // agri.readRainSensor();
  // agri.readBMEAltitude();
  float AirHumidity = agri.readBMEAirHumidity();
  // agri.readBMEAirPressure();
  // agri.readBMEAirTemp();
  // agri.readLUXSensor();
  // agri.readBH1750();
  // agri.triggerPump(1);
  // agri.readBatteryVoltage();

  // agri.triggerPumpOn();
  // agri.triggerLedOn();
  // delay(3000);
  // agri.triggerPumpOff();
  // agri.triggerLedOff();
  // delay(1000);

  // agri.turnLEDOn();
  // delay(1000);
  // agri.turnLEDOff();
  // delay(1000);
  // client.connectToWiFi(WIFI_SSID, WIFI_PASSWORD);
  // client.add("temp", temperature);
  // client.add("UVIndex", UVIndex);
  // client.add("Air_Humidity", AirHumidity);
  // client.makePayload();
  // client.sendToCloud(HOST_ADDRESS);
  // delay(10000);
}

