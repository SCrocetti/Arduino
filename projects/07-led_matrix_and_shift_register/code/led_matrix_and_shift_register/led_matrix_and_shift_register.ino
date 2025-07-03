#include <Arduino.h>
#include <avr/pgmspace.h>
#include "ShiftRegisterWriter.h"

// === CONFIG ===
constexpr bool COL_ACTIVE_LOW = true;    // columns active LOW (invert bits)
constexpr uint8_t DATA_PIN  = 11;        // 74HC595 SER
constexpr uint8_t CLOCK_PIN = 13;        // 74HC595 SRCLK
constexpr uint8_t LATCH_PIN = 10;        // 74HC595 RCLK
constexpr uint8_t ROW_PINS[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // Matrix rows

// Columns reset pattern (all off)
constexpr uint8_t COLUMNS_RESETED = COL_ACTIVE_LOW ? 0xFF : 0x00;

// Create ShiftRegisterWriter instance with default MSBFIRST (ignored if you use dynamic write)
ShiftRegisterWriter registerWriter(DATA_PIN, CLOCK_PIN, LATCH_PIN, MSBFIRST);

// === PROGMEM patterns for letters M, I, A, U ===
constexpr uint8_t patternM[8] PROGMEM = {
  0b10000001, 0b11000011, 0b10100101, 0b10011001,
  0b10000001, 0b10000001, 0b10000001, 0b00000000
};
constexpr uint8_t patternI[8] PROGMEM = {
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

const bool flipFlags[] = { false, true, false, true };  // M I A U mirrored alternately

uint8_t const* const animation[] = { patternM, patternI, patternA, patternU };
constexpr size_t patternCount = sizeof(animation) / sizeof(*animation);

// === Helper: read byte from PROGMEM or RAM ===
static inline uint8_t readByte(const uint8_t* addr) {
#ifdef __AVR__
  return pgm_read_byte(addr);
#else
  return *addr;
#endif
}

// === Helper: bit-reverse an 8-bit byte ===
static inline uint8_t reverse8(uint8_t b) {
  b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
  b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
  b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
  return b;
}

// === Draw a pattern with optional bit order flip ===
void drawPattern(const uint8_t* patternPtr, bool flipBits)
{
  uint8_t bitOrder = flipBits ? LSBFIRST : MSBFIRST;

  for (uint8_t row = 0; row < 8; ++row)
  {
    uint8_t bits = readByte(patternPtr + row);
    if (!bits) continue;

    uint8_t colData = COL_ACTIVE_LOW ? ~bits : bits;
    if (flipBits) colData = reverse8(colData);

    digitalWrite(ROW_PINS[row], HIGH);
    registerWriter.write(colData, bitOrder);
    registerWriter.write(COLUMNS_RESETED, bitOrder);
    digitalWrite(ROW_PINS[row], LOW);
  }
}

void drawAnimation(uint8_t const* const animation[],uint8_t patternCount,){
  for(uint8_t frame=0;frame<patternCount;frame++){
    static bool flip = false;

    drawPattern(animation[frame], flip);
    delay(500);

    flip = !flip;  
  }
}
// Show a sequence of 8×8 frames with optional per‑frame flipping.
//  animation    : array of pointers to 8‑row patterns (PROGMEM or RAM)
//  flipPattern  : array of booleans; true  ➜ show frame flipped
//  patternCount : number of frames in the animation
void drawAnimation(const uint8_t* const animation[],
                   const bool          flipPattern[],
                   uint8_t             patternCount)
{
    for (uint8_t frame = 0; frame < patternCount; ++frame)
    {
        bool flip = flipPattern[frame];          // per‑frame flag
        drawPattern(animation[frame], flip);     // render one frame
        delay(500);                              // hold 500 ms
    }
}
void setup() {
  for (uint8_t pin : ROW_PINS) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
  registerWriter.begin();
}

void loop() {
    drawAnimation(patternPointers, flipFlags,
                  sizeof(patternPointers) / sizeof(*patternPointers));
}

