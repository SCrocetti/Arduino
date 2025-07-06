#include <LedMatrixAndShiftRegisterDrawer.h>
#include <Arduino.h>
#include <avr/pgmspace.h>

// === CONFIG ===
constexpr uint8_t DATA_PIN  = 10;        // 74HC595 SER
constexpr uint8_t CLOCK_PIN = 12;        // 74HC595 SRCLK
constexpr uint8_t LATCH_PIN = 11;        // 74HC595 RCLK
constexpr uint8_t ROW_PINS[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // Matrix rows

LedMatrixAndShiftRegisterDrawer drawer(ROW_PINS,DATA_PIN, CLOCK_PIN, LATCH_PIN);
constexpr uint8_t patternM[8] PROGMEM = {
  0b10000001, 
  0b11000011,
  0b10100101,
  0b10011001,
  0b10000001,
  0b10000001,
  0b10000001,
  0b10000001
};
constexpr uint8_t patternI[8] PROGMEM= {
  0b11111111, 0b00011000, 0b00011000, 0b00011000,
  0b00011000, 0b00011000, 0b00011000, 0b11111111
};
constexpr uint8_t patternA[8] PROGMEM = {
  0b00111100, 0b01000010, 0b10000001, 0b10000001,
  0b11111111, 0b10000001, 0b10000001, 0b10000001
};
constexpr uint8_t patternU[8] PROGMEM = {
  0b10000001, 0b10000001, 0b10000001, 0b10000001,
  0b10000001, 0b10000001, 0b10000001, 0b01111110
};
constexpr uint8_t patternO[8] PROGMEM = {
  0b01111110, 0b10000001, 0b10000001, 0b10000001,
  0b10000001, 0b10000001, 0b10000001, 0b01111110
};
constexpr uint8_t patternR[8] PROGMEM = {
  0b11111110,
  0b10000001,
  0b10000001,
  0b10000001,
  0b11111110,
  0b10010000,
  0b10001000,
  0b10000100
};
const bool flipFlags[] = { false, false, false, false, false, false,false };  // M I A U mirrored alternately

uint8_t const* const animation[] = { patternM, patternI, patternA, patternU, patternM, patternO, patternR };
constexpr size_t patternCount = sizeof(animation) / sizeof(*animation);

void setup() {
  drawer.begin();
}

void loop() {
  drawer.drawAnimation(animation,patternCount,700);
}
