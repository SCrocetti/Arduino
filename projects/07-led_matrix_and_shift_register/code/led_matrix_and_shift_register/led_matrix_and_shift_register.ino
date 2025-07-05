#include <ShiftRegisterWriter.h>

#include <Arduino.h>
#include <avr/pgmspace.h>

// === CONFIG ===
const bool SYSTEM_ON=true;
constexpr uint8_t DATA_PIN  = 10;        // 74HC595 SER
constexpr uint8_t CLOCK_PIN = 12;        // 74HC595 SRCLK
constexpr uint8_t LATCH_PIN = 11;        // 74HC595 RCLK
constexpr uint8_t ROW_PINS[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // Matrix rows

// Columns reset pattern (all off)
constexpr uint8_t COLUMNS_RESETED = 0b11111111;

// Create ShiftRegisterWriter instance with default MSBFIRST (ignored if you use dynamic write)
ShiftRegisterWriter registerWriter(DATA_PIN, CLOCK_PIN, LATCH_PIN, MSBFIRST);
// === Inverted PROGMEM patterns for letters M, I, A, U ===
constexpr uint8_t patternM_INV[8] PROGMEM = {
  0b01111110,
  0b00111100,
  0b01011010,
  0b01100110,
  0b01111110,
  0b01111110,
  0b01111110,
  0b01111110
};

constexpr uint8_t patternI_INV[8] PROGMEM = {
  0b00000000,
  0b11100111,
  0b11100111,
  0b11100111,
  0b11100111,
  0b11100111,
  0b11100111,
  0b00000000
};

constexpr uint8_t patternA_INV[8] PROGMEM = {
  0b11000011,
  0b10111101,
  0b01111110,
  0b01111110,
  0b00000000,
  0b01111110,
  0b01111110,
  0b01111110
};

constexpr uint8_t patternU_INV[8] PROGMEM = {
  0b01111110,
  0b01111110,
  0b01111110,
  0b01111110,
  0b01111110,
  0b01111110,
  0b01111110,
  0b10000001
};
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

// === Helper: read byte from PROGMEM or RAM ===
static inline uint8_t readByte(const uint8_t* addr) {
#ifdef __AVR__
  return pgm_read_byte(addr);
#else
  return *addr;
#endif
}

// === Draw a pattern with optional bit order flip ===
void drawPattern(const uint8_t* patternPtr, bool flipBits, unsigned long durationMs)
{
  const unsigned long FRAME_US = 973UL; // time per frame in micros
  unsigned long frames = durationMs*1000 / FRAME_US;
  uint8_t bitOrder = flipBits ? MSBFIRST : LSBFIRST;

  for(unsigned long frame=0;frame<frames;frame++){
    for (uint8_t row = 0; row < 8; ++row)
    {
      uint8_t bits = ~readByte(patternPtr+row);

      digitalWrite(ROW_PINS[row], HIGH);
      registerWriter.write(bits, bitOrder);
      registerWriter.write(COLUMNS_RESETED, MSBFIRST);
      digitalWrite(ROW_PINS[row], LOW);
    }
  }
}

// Show a sequence of 8×8 frames with optional per‑frame flipping.
//  animation     : array of pointers to 8‑row patterns (PROGMEM or RAM)
//  flipPattern   : array of booleans; true ➜ show frame flipped
//  patternCount  : number of frames in the animation
//  frameTimeMs   : how long to keep each frame on screen
void drawAnimation(const uint8_t* const animation[],
                   const bool           flipPattern[],
                   uint8_t              patternCount,
                   uint16_t             frameTimeMs)
{
    for (uint8_t pattern = 0; pattern < patternCount; ++pattern)
    {
        bool flip = flipPattern[pattern];          // per‑frame flag
        drawPattern(animation[pattern], flip,frameTimeMs);     // render one frame
    }
}
void setup() {
  if(SYSTEM_ON){
    Serial.begin(9600); 
    for(uint8_t row=0;row<8;row++){
        pinMode(ROW_PINS[row], OUTPUT);
      }
    registerWriter.begin();
    registerWriter.write(COLUMNS_RESETED, MSBFIRST);
  }
}

void loop() {
  if(SYSTEM_ON){
    drawAnimation(animation,flipFlags,patternCount,700);
      
  }
}
