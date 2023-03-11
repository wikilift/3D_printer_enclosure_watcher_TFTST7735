#include "tft_service.h"
#include "constants/constants.h"
TFTService::TFTService() : tft(TFT_CS, TFT_DC, TFT_RST)
{
}

void TFTService::init()
{
    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(ST7735_BLACK);
    tft.setRotation(3);
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