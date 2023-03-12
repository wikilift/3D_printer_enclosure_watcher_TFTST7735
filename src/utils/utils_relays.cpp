#include "utils/utils_relays.h"
#include "Arduino.h"
#include "constants/constants.h"
#include "service/tft_service.h"
static int counter = 0;
bool showText = true;       // Flag para alternar entre mostrar y ocultar el texto
unsigned long lastTime = 0; // Variable para almacenar el último tiempo en que se cambió el estado del flag
const unsigned long blinkInterval = 500;
bool goodVibes;
bool workTemp;
bool panic;
int evaluatePanic(float value)
{

    if (value < 40)
    {
        if (!goodVibes)
        {
            TFTService::getInstance().writeString(20, 105, "Good Vibes", ST7735_GREEN, 2);
            digitalWrite(PANIC_RELAY, LOW);
            goodVibes = true;
        }
        else
        {
            workTemp = false;
            panic=false;
        }

        return 0;
    }
    else if (value > 40 && value < 65)
    {
        if (!workTemp)
        {
            TFTService::getInstance().writeString(5, 105, "Working temp", ST7735_ORANGE, 2);
            digitalWrite(PANIC_RELAY, LOW);
            workTemp=true;
        }
        else
        {
            goodVibes=false;
            panic=false;

        }
        return 1;
    }
    else if (value > 65)
    {
        if (millis() - lastTime >= blinkInterval)
        {
            showText = !showText; // Cambiar el estado del flag
            lastTime = millis();  // Actualizar el tiempo del último cambio del flag
        }
        if (showText)
        {
            TFTService::getInstance().writeString(50, 105, "PANIC", ST7735_RED, 2);
            counter++;
        }
        else
        {
            TFTService::getInstance().eraseCoords(50, 105, 100, 20);
        }
         if (counter == 10)
        {
            digitalWrite(PANIC_RELAY, HIGH);
        }
        return -1;
   

       
    }
    else
    {
        return 0;
    }
}