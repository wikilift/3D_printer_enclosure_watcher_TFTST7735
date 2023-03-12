
#include "constants/constants.h"
#include "service/tft_service.h"
#include "callback/callbacks.hpp"
#include <TaskScheduler.h>
#include <service/runner.hpp>

Scheduler runner;




void setup(void)
{

  Serial.begin(115200);

  pinMode(PANIC_RELAY, OUTPUT);
  digitalWrite(PANIC_RELAY, LOW);
  TFTService::getInstance().init();

  runner.init();
  

  runner.addTask(timeTask);
  runner.addTask(tempTask);
  runner.addTask(humidityTask);
  runner.addTask(panicTask);
  //delay(1000);

  timeTask.enable();
  tempTask.enable();
  humidityTask.enable();
  panicTask.enable();
  Serial.println("[INFO] All task was launch");

  
}
void loop()
{

  
 runner.execute();
 
}