
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#include "connection/conect_wifi.hpp"
#include "service/tft_service.h"

WiFiClient wifiClient;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");


void setup(void)
{
  Serial.begin(115200);

  TFTService::getInstance().init();

  ConnectWiFi_STA();
  timeClient.begin();
  timeClient.setTimeOffset(3600);
}
void loop()
{
  timeClient.update();
  TFTService::getInstance().writeString(25, 10, timeClient.getFormattedTime(), ST7735_WHITE, 2);

  TFTService::getInstance().writeString(40, 40, "25C", ST7735_YELLOW, 4);

  TFTService::getInstance().writeString(8, 90, "Humidity:60%", ST7735_BLUE, 2);
  // writeString(tft, 35, 10, timeClient.getFormattedTime(), ST7735_WHITE, 2);
  delay(1000);
}