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
    TFTService::getInstance().writeString(0, 10, "Connecting", ST7735_BLUE, 2);
    int x = 5;
    int y = 30;

    while (WiFi.status() != WL_CONNECTED)
    {
       
        TFTService::getInstance().writeString(x, y, "*", ST7735_CYAN, 2);
        x += 15;
         delay(300);
    }
    TFTService::getInstance().eraseTFT();
    Serial.println("");
    Serial.print("[WiFi] Started STA:\t");
    Serial.println(WIFI_SSID);
    Serial.print("[WiFi]  IP address:\t");
    Serial.println(WiFi.localIP());
}