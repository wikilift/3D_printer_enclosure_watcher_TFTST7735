#include "TaskScheduler.h"
#include <NTPClient.h>
#include "service/tft_service.h"
#include "Arduino.h"
#include <utils/utils_relays.h>
#include "service/runner.hpp"
#include "service/dht_service.h"
static float last_temp = 0.f;
static float last_hum = 0.f;
void panicCallback()
{

    evaluatePanic(DhtService::getInstance().getTemperature());

}

void updateTime()
{

    time_client.update();
    TFTService::getInstance().writeString(55, 15, time_client.getFormattedTime(), ST7735_WHITE, 2);
}

void updateTemp()
{
    float currentTemp = DhtService::getInstance().getTemperature();
    //Serial.print(currentTemp);
    if (currentTemp != last_temp)
    {
        unsigned int myVar = ST7735_GREEN;
        if (currentTemp > 40 && currentTemp < 65)
        {
            myVar = ST7735_YELLOW;
        }
        else if (currentTemp > 65)
        {
            myVar = ST7735_RED;
        }
        TFTService::getInstance().writeString(10, 45, String(currentTemp) + "C", myVar, 3);
        last_temp = currentTemp;
    }
}
void evaluateHumidity()
{
    float currentHum = DhtService::getInstance().getHumidity();
    if (currentHum != last_hum)
    {
        TFTService::getInstance().writeString(25, 82, String(currentHum), 0x07FF, 2);

        last_hum = currentHum;
    }
}
Task panicTask(1000, TASK_FOREVER, &panicCallback);
Task timeTask(1000, TASK_FOREVER, &updateTime);
Task tempTask(1000, TASK_FOREVER, &updateTemp);
Task humidityTask(6500, TASK_FOREVER, &evaluateHumidity);