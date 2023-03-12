#pragma once
#include "Arduino.h"
#define WIFI_SSID "casanana"
#define WIFI_PASS "L4N4n4y3lTh41M4nd4n!"

//! CLK D5
//! SDA D7
#define TFT_RST D4 // RST
#define TFT_CS D3  // CS
#define TFT_DC D2  // RS
#define PANIC_RELAY 5
extern const unsigned char windS[] PROGMEM;
extern const unsigned char pressure[] PROGMEM;
extern const unsigned char humid[];
extern const unsigned char CLOCK[] PROGMEM;
extern const unsigned char cloud[] PROGMEM;
extern const unsigned char windS[] PROGMEM;