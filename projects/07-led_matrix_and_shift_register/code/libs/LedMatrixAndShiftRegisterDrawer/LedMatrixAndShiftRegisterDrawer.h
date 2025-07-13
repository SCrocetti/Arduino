#pragma once
#include <ShiftRegisterWriter.h>
#include <Arduino.h>


class LedMatrixAndShiftRegisterDrawer {
public:
  /**
  * @brief Construct a drawer for the led matrix using a shift register
  *
  * @param rowPins         Pinout of the rows of the led matrix
  * @param dataPin         MCU pin wired to SER (DS) of the shift register.
  * @param clockPin        MCU pin wired to SRCLK  of the shift register.
  * @param latchPin        MCU pin wired to RCLK  of the shift register.
  */
  LedMatrixAndShiftRegisterDrawer(const uint8_t  rowPins[8],
                                            uint8_t dataPin,
                                            uint8_t clockPin,
                                            uint8_t latchPin);

  /** @brief Configure the three shift register pins and the eigth row pins as outputs. */
  void begin();

 /**
  * Draws a static 8x8 pattern for aprox 1 mili
  *
  * @param patternPtr Pointer to the 8-byte pattern array.
  */
  void drawPattern(const uint8_t* patternPtrs);
  /**
   * Draws a static 8x8 pattern for aprox 1 mili
   * with optional horizontal bit-flipping.
   *
   * @param patternPtr Pointer to the 8-byte pattern array.
   * @param flipBits If true, bits will be flipped before display.
   */
  void drawPattern(const uint8_t* patternPtr, bool flipBits);
  /**
  * Draws a static 8x8 pattern for the specified duration in milliseconds.
  *
  * @param patternPtr Pointer to the 8-byte pattern array.
  * @param durationMs Duration to display the pattern in milliseconds.
  */
  void drawPattern(const uint8_t* patternPtr, unsigned long durationMs);
  /**
   * Draws a static 8x8 pattern for the specified duration in milliseconds,
   * with optional horizontal bit-flipping.
   *
   * @param patternPtr Pointer to the 8-byte pattern array.
   * @param flipBits If true, bits will be flipped before display.
   * @param durationMs Duration to display the pattern in milliseconds.
   */
  void drawPattern(const uint8_t* patternPtr, bool flipBits, unsigned long durationMs);
  /**
   * Plays an animation consisting of multiple 8x8 patterns without flipping.
   *
   * @param animation Array of pointers to 8-row patterns (PROGMEM or RAM).
   * @param patternCount Number of frames in the animation.
   * @param frameTimeMs How long (in milliseconds) to show each frame.
   */
  void drawAnimation(const uint8_t* const animation[], uint8_t patternCount, uint16_t frameTimeMs);
  /**
   * Plays an animation consisting of multiple 8x8 patterns with optional per-frame flipping.
   *
   * @param animation Array of pointers to 8-row patterns (PROGMEM or RAM).
   * @param flipPattern Array of booleans; true ➜ show frame flipped.
   * @param patternCount Number of frames in the animation.
   * @param frameTimeMs How long (in milliseconds) to show each frame.
   */
  void drawAnimation(const uint8_t* const animation[],const bool flipPattern[],uint8_t patternCount,uint16_t frameTimeMs);

private:
  const uint8_t _rowPins [8];   // <-- three indices!
  ShiftRegisterWriter _registerWriter;
  static constexpr uint8_t COLUMNS_RESETED = 0b11111111;
};
