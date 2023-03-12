#include "tft_service.h"
#include "constants/constants.h"
#include "connection/conect_wifi.hpp"
TFTService::TFTService() : tft(TFT_CS, TFT_DC, TFT_RST), timeClient(ntpUDP, "pool.ntp.org")
{
}

void TFTService::init()
{
    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(ST7735_BLACK);
    tft.setRotation(3);
    // layout
    tft.drawFastHLine(5, 0, tft.width(), ST7735_WHITE);
    tft.drawFastHLine(5, tft.height() - 1, tft.width(), ST7735_WHITE);
    tft.drawFastVLine(5, 0, tft.height(), ST7735_WHITE);
    tft.drawFastVLine(tft.width() - 1, 5, tft.height(), ST7735_WHITE);
    ConnectWiFi_STA();
    timeClient.begin();
    timeClient.setTimeOffset(3600);
}

TFTService &TFTService::getInstance()
{
    static TFTService instance;
    return instance;
}

void TFTService::writeString(int x, int y, String str, uint16_t color, uint8_t size)
{
    tft.setTextSize(size);
    int16_t x1, y1;
    uint16_t textWidth, textHeight;
    tft.getTextBounds(str, x, y, &x1, &y1, &textWidth, &textHeight);
    tft.fillRect(x1, y1, textWidth, textHeight, ST7735_BLACK);
    tft.setCursor(x, y);
    tft.setTextColor(color);
    tft.print(str);
}
void TFTService::eraseTFT()
{
    tft.fillScreen(ST7735_BLACK);
}

void TFTService::eraseCoords(int x, int y, int width, int height)
{
    tft.fillRect(x, y, width, height, ST7735_BLACK);
}
NTPClient &TFTService::getTimeClient()
{
    return timeClient;
}
NTPClient &time_client = TFTService::getInstance().getTimeClient();
Adafruit_ST7735 &myTft=TFTService::getInstance().getTFT();