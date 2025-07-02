#include <ShiftRegisterWriter.h>

// Shift‑register pins
const uint8_t DATA_PIN  = 11;
const uint8_t CLOCK_PIN = 13;
const uint8_t LATCH_PIN = 8;

ShiftRegisterWriter display(DATA_PIN, CLOCK_PIN, LATCH_PIN);

const uint8_t pattern[] = {
  0b10000000,
  0b01000000,
  0b00100000,
  0b00010000,
  0b00001000,
  0b00000100,
  0b00000010,
  0b00000001
};

void setup() {
  display.begin();                // sets pinMode for DATA/CLOCK/LATCH
}

void loop() {
  for (uint8_t i = 0; i < sizeof(pattern); ++i) {
    display.write(pattern[i]);    // send one byte to the shift register
    delay(1000);                  // wait 1 s before the next frame
  }
}