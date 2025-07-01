#pragma once
#include <Arduino.h>

/* If the sketch didn’t #define LEDMATRIX_PINOUT, fall back to this */
#ifndef LEDMATRIX_PINOUT
static const uint8_t LEDMATRIX_PINOUT[6][6][2] = {
  {{ 2,  3},{ 2,  5},{ 2,  7},{ 2,  9},{ 2, 11},{ 2, 13}},
  {{ 4,  3},{ 4,  5},{ 4,  7},{ 4,  9},{ 4, 11},{ 4, 13}},
  {{ 6,  3},{ 6,  5},{ 6,  7},{ 6,  9},{ 6, 11},{ 6, 13}},
  {{ 8,  3},{ 8,  5},{ 8,  7},{ 8,  9},{ 8, 11},{ 8, 13}},
  {{10,  3},{10,  5},{10,  7},{10,  9},{10, 11},{10, 13}},
  {{12,  3},{12,  5},{12,  7},{12,  9},{12, 11},{12, 13}}
};
#endif

class LedMatrixAndShiftRegisterDrawer {
public:
  /* NOTE the parameter and member type: pointer to [6][6][2] */
  explicit LedMatrixAndShiftRegisterDrawer(const uint8_t  pins [6][6][2] = LEDMATRIX_PINOUT);

  void sweepMatrix(const bool frame[6][6], uint16_t durationMs);
  void sweepArray(const bool *const frames[], uint8_t frame_count,
                uint16_t frameDurationMs, uint16_t frameDelay);


private:
  const uint8_t _pins [6][6][2];   // <-- three indices!
};
