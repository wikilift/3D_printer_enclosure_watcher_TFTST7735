#pragma once
#include <Adafruit_ST7735.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
class TFTService
{
public:
  static TFTService &getInstance();
  Adafruit_ST7735 &getTFT() { return tft; }
  void init();
  void writeString(int x, int y, String str, uint16_t color, uint8_t size);
  void eraseTFT();
  void eraseCoords(int x, int y, int width, int height);
  NTPClient &getTimeClient();

private:
  TFTService();
  TFTService(const TFTService &);
  void operator=(const TFTService &);
  Adafruit_ST7735 tft;
  WiFiUDP ntpUDP;
  NTPClient timeClient;
};


extern NTPClient &time_client;
extern Adafruit_ST7735 &myTft;