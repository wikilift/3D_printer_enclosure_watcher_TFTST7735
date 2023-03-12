#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "constants/constants.h"
#include "service/tft_service.h"
void ConnectWiFi_STA()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        WiFi.disconnect();
    }
    Serial.println("");
    WiFi.mode(WIFI_STA);

    WiFi.begin(WIFI_SSID, WIFI_PASS);
    TFTService::getInstance().writeString(10, 10, "Connecting", ST7735_BLUE, 2);
    int x = 10;
    int y = 30;

    while (WiFi.status() != WL_CONNECTED)
    {

        TFTService::getInstance().writeString(x, y, "*", ST7735_CYAN, 2);
        x += 15;
        delay(300);
    }
    TFTService::getInstance().eraseTFT();
    myTft.drawFastHLine(5, 0, myTft.width(), ST7735_WHITE);
    myTft.drawFastHLine(5, myTft.height() - 1, myTft.width(), ST7735_WHITE);
    myTft.drawFastVLine(5, 0, myTft.height(), ST7735_WHITE);
    TFTService::getInstance().getTFT().drawFastVLine(myTft.width() - 1, 5, myTft.height(), ST7735_WHITE);

 myTft.drawBitmap(80, 70, humid, 22, 30,0x07FF);
 myTft.drawBitmap(110, 35, cloud, 45, 38,ST7735_YELLOW);
     myTft.drawBitmap(15, 8, CLOCK, 30, 28,ST7735_WHITE);
    Serial.println("");
    Serial.print("[WiFi] Started STA:\t");
    Serial.println(WIFI_SSID);
    Serial.print("[WiFi]  IP address:\t");
    Serial.println(WiFi.localIP());
}