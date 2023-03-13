#include "dht_service.h"
#include "math.h"

#define DHTPIN 3
#define DHTTYPE DHT11
 sensor_t sensor;
DhtService::DhtService() : dht(DHTPIN, DHTTYPE)
{
    dht.begin();
    delay(2000);
    
    dht.temperature().getSensor(&sensor);

    delayMS = sensor.min_delay / 1000;
    sensor.min_delay=1000;
    dht.temperature().getSensor(&sensor);
  
    dht.humidity().getSensor(&sensor);
  
}

float DhtService::getTemperature()
{
    //dht.begin();
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    
    if (isnan(event.temperature))
    {
             return 1.0;
    }
    return ceil(event.temperature * 10) / 10;
}

float DhtService::getHumidity()
{
    sensors_event_t event;
    dht.humidity().getEvent(&event);
    if (isnan(event.relative_humidity))
    {
        return 1.0;
    }
    return ceil(event.relative_humidity * 10) / 10;
}
