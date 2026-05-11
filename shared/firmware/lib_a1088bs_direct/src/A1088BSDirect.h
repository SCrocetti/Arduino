#pragma once
#include <Arduino.h>
#include "A1088BSDirectConfig.h"
/**
 * @brief Default pin mapping for the 1088BS 8x8 LED Matrix.
 * Maps [row][column][0:Anode, 1:Cathode]
 */
#ifndef LEDMATRIX_PINOUT
static const uint8_t LEDMATRIX_PINOUT[8][8][2] = {
  {{ 2,  3},{ 2,  5},{ 2,  7},{ 2,  9},{ 2, 11},{ 2, 13},{ 2, 15},{ 2, 17}},
  {{ 4,  3},{ 4,  5},{ 4,  7},{ 4,  9},{ 4, 11},{ 4, 13},{ 4, 15},{ 4, 17}},
  {{ 6,  3},{ 6,  5},{ 6,  7},{ 6,  9},{ 6, 11},{ 6, 13},{ 6, 15},{ 6, 17}},
  {{ 8,  3},{ 8,  5},{ 8,  7},{ 8,  9},{ 8, 11},{ 8, 13},{ 8, 15},{ 8, 17}},
  {{10,  3},{10,  5},{10,  7},{10,  9},{10, 11},{10, 13},{10, 15},{10, 17}},
  {{12,  3},{12,  5},{12,  7},{12,  9},{12, 11},{12, 13},{12, 15},{12, 17}},
  {{14,  3},{14,  5},{14,  7},{14,  9},{14, 11},{14, 13},{14, 15},{14, 17}},
  {{16,  3},{16,  5},{16,  7},{16,  9},{16, 11},{16, 13},{16, 15},{16, 17}}
};
#endif

class A1088BSDirect {
public:
  /**
   * @brief Construct a new A1088BSDirect object.
   * Initializes pins as outputs and clears the bus.
   * @param pins A 3D array mapping coordinates to physical Arduino pins.
   */
  explicit A1088BSDirect(const uint8_t pins[8][8][2] = LEDMATRIX_PINOUT);

  /**
   * @brief Renders a single 8x8 static frame using multiplexing.
   * @param frame 2D boolean array where true = LED ON.
   * @param durationMs Total time in milliseconds to display the frame.
   */
  void displayFrame(const bool frame[8][8], uint16_t durationMs);

  /**
   * @brief Plays a sequence of frames to create an animation.
   * @param frames Array of pointers to 8x8 bitmaps.
   * @param frameCount Total number of frames in the sequence.
   * @param frameDelayMs Time to display each individual frame.
   */
  void playAnimation(const bool* const frames[], uint8_t frameCount, uint16_t frameDelayMs);

private:
  const uint8_t _pins[8][8][2];
};