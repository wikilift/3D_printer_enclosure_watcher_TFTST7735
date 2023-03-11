#include "print_screen.h"
void writeString(Adafruit_ST7735 &tft, int x, int y, String str, uint16_t color, uint8_t size) {
  tft.setTextSize(size);
  int16_t x1, y1;
  uint16_t textWidth, textHeight;
  tft.getTextBounds(str, x, y, &x1, &y1, &textWidth, &textHeight);
  tft.fillRect(x1, y1, textWidth, textHeight, ST7735_BLACK);
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.print(str);
}