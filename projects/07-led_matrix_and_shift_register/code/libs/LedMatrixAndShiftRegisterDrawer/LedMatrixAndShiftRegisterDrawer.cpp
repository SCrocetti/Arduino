#include <ShiftRegisterWriter.h>
#include <LedMatrixAndShiftRegisterDrawer.h>
#include <Arduino.h>
#include <avr/pgmspace.h>

/* ------------------------------------------------------------------ */
/* Constructor                                                        */
/* ------------------------------------------------------------------ */
LedMatrixAndShiftRegisterDrawer::LedMatrixAndShiftRegisterDrawer(
        const uint8_t rowPins[8],
        uint8_t dataPin,
        uint8_t clockPin,
        uint8_t latchPin)
    : _rowPins{},                                        // zero‑initialise the array
      _registerWriter(dataPin, clockPin, latchPin, MSBFIRST)   // construct properly
{
    // copy the caller’s row pin array
    memcpy(_rowPins, rowPins, 8);
}

/* ------------------------------------------------------------------ */
/* Public methods                                                     */
/* ------------------------------------------------------------------ */

void LedMatrixAndShiftRegisterDrawer::begin(){
  for(uint8_t row=0;row<8;row++){
        pinMode(_rowPins[row], OUTPUT);
      }
    _registerWriter.begin();
    _registerWriter.write(COLUMNS_RESETED, MSBFIRST);
}

void LedMatrixAndShiftRegisterDrawer::drawPattern(const uint8_t* patternPtr){
  drawPattern(patternPtr, false);
}
void LedMatrixAndShiftRegisterDrawer::drawPattern(const uint8_t* patternPtr,  bool flipBits){
  uint8_t bitOrder = flipBits ? MSBFIRST : LSBFIRST;
  for (uint8_t row = 0; row < 8; ++row)
  {
    uint8_t bits = patternPtr[row];

    digitalWrite(_rowPins[row], HIGH);
    _registerWriter.write(bits, bitOrder);
    _registerWriter.write(COLUMNS_RESETED, MSBFIRST);
    digitalWrite(_rowPins[row], LOW);
  }
}
void LedMatrixAndShiftRegisterDrawer::drawPattern(const uint8_t* patternPtr, unsigned long durationMs){
  drawPattern(patternPtr, false,  (unsigned long)durationMs);
}


void LedMatrixAndShiftRegisterDrawer::drawPattern(const uint8_t* patternPtr, bool flipBits, unsigned long durationMs)
{
  const unsigned long FRAME_US = 973UL; // time per frame in microseconds
  unsigned long frames = durationMs * 1000 / FRAME_US;

  for (unsigned long frame = 0; frame < frames; frame++) {
    drawPattern(patternPtr,flipBits);
  }
}

void LedMatrixAndShiftRegisterDrawer::drawAnimation(const uint8_t* const animation[],
                   const bool           flipPattern[],
                   uint8_t              patternCount,
                   uint16_t             frameTimeMs)
{
    for (uint8_t pattern = 0; pattern < patternCount; ++pattern)
    {
        drawPattern(animation[pattern], false, (unsigned long)frameTimeMs);
    }
}

void LedMatrixAndShiftRegisterDrawer::drawAnimation(const uint8_t* const animation[],
                   uint8_t              patternCount,
                   uint16_t             frameTimeMs)
{
    for (uint8_t pattern = 0; pattern < patternCount; ++pattern)
    {
        drawPattern(animation[pattern], (unsigned long)frameTimeMs); // render one frame
    }
}
