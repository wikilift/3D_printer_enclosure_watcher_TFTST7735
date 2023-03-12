
#pragma once    
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

class DhtService {
public:
    static DhtService& getInstance() {
        static DhtService instance;
        return instance;
    }
    float getTemperature();
    float getHumidity();
private:
    DhtService();
    DHT_Unified dht;
    uint32_t delayMS;
};
