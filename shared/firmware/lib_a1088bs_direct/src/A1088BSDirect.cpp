#include "LedMatrixDrawer.h"

LedMatrixDrawer::LedMatrixDrawer(const uint8_t pins[6][6][2])
{
  memcpy(_pins, pins, sizeof _pins);
  for (uint8_t i=0;i<6;i++){
      uint8_t rowPin = _pins[i][0][0];   // [row][col=0][cat/an=0]
      uint8_t colPin = _pins[0][i][1];   // [row][col=0][cat/an=0]
      pinMode(rowPin, OUTPUT);
      pinMode(colPin, OUTPUT);
      digitalWrite(colPin, HIGH);
  }
}

void LedMatrixDrawer::sweepMatrix(const bool frame[6][6],
                                  uint16_t durationMs)
{
  const float frequency = 3.5f;
  const int   sweeps    = (int)(frequency * durationMs);

  for (int k = 0; k < sweeps; ++k) {
    for (int row = 0; row < 6; ++row) {

      uint8_t rowPin = _pins[row][0][0];   // [row][col=0][cat/an=0]
      digitalWrite(rowPin, HIGH);

      for (int col = 0; col < 6; ++col) {
        if (frame[row][col]) {
          uint8_t colPin = _pins[row][col][1]; // cat/an index 1
          digitalWrite(colPin, LOW);
        }
      }

      for (int col = 0; col < 6; ++col) {
        if (frame[row][col]) {
          uint8_t colPin = _pins[row][col][1];
          digitalWrite(colPin, HIGH);
        }
      }

      digitalWrite(rowPin, LOW);
    }
  }
}
void LedMatrixDrawer::sweepArray(const bool *const frames[], uint8_t frame_count,
                                 uint16_t frameDurationMs, uint16_t frameDelay) {
  for (uint8_t i = 0; i < frame_count; ++i) {
    const bool (*frame)[6] = reinterpret_cast<const bool (*)[6]>(frames[i]);
    sweepMatrix(frame, frameDurationMs);
    delay(frameDelay);
  }
}

