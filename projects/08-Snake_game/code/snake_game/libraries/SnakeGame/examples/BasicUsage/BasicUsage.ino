#include <Arduino.h>
#include "SnakeGame.h"

// Define hardware pins
const uint8_t ROW_PINS[8]     = {2, 3, 4, 5, 6, 7, 8, 9};
const uint8_t BUTTON_PINS[4]  = {A0, A1, A2, A3};
const uint8_t DATA_PIN        = 10;
const uint8_t CLOCK_PIN       = 12;
const uint8_t LATCH_PIN       = 11;
const unsigned long INTERVAL  = 750;  // milliseconds between snake moves

// Create game instance with hardware config and timing
SnakeGame game(ROW_PINS, DATA_PIN, CLOCK_PIN, LATCH_PIN, BUTTON_PINS, INTERVAL);

void setup() {
  game.begin();
}

void loop() {
  game.update();  // Updates game logic, input, and redraws the LED matrix
}
