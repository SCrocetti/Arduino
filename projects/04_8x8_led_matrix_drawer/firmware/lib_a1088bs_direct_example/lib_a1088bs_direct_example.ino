#include <A1088BSDirect.h>
#include <A1088BSDirectConfig.h>

// 1. Static Frame: "X inside a rectangle"
const bool xRectFrame[8][8] = {
  {1,1,1,1,1,1,1,1}, // Top border
  {1,1,0,0,0,0,1,1}, // X starts
  {1,0,1,0,0,1,0,1},
  {1,0,0,1,1,0,0,1},
  {1,0,0,1,1,0,0,1},
  {1,0,1,0,0,1,0,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,1,1,1,1,1}  // Bottom border
};

// 2. Animation Frames: "HELLO" (8x8)
const bool h_frame[8][8] = {
  {1,0,0,0,0,0,0,1}, {1,0,0,0,0,0,0,1}, {1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1}, {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1}, {1,0,0,0,0,0,0,1}
};

const bool e_frame[8][8] = {
  {1,1,1,1,1,1,1,1}, {1,0,0,0,0,0,0,0}, {1,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,0}, {1,1,1,1,1,1,1,0}, {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0}, {1,1,1,1,1,1,1,1}
};

const bool l_frame[8][8] = {
  {1,0,0,0,0,0,0,0}, {1,0,0,0,0,0,0,0}, {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0}, {1,0,0,0,0,0,0,0}, {1,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1}
};

const bool o_frame[8][8] = {
  {0,1,1,1,1,1,1,0}, {1,1,0,0,0,0,1,1}, {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1}, {1,0,0,0,0,0,0,1}, {1,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,1}, {0,1,1,1,1,1,1,0}
};

// Instance of your new library using the config pinout
A1088BSDirect matrix(LEDMATRIX_PINOUT);

// Animation array pointing to the frames
const bool* const hello_animation[] = {
  &h_frame[0][0],
  &e_frame[0][0],
  &l_frame[0][0],
  &l_frame[0][0],
  &o_frame[0][0]
};

const uint8_t animCount = sizeof(hello_animation) / sizeof(hello_animation[0]);

void setup() {
  // Initialization handled in constructor
}

void loop() {
  // --- Method 1: Display a single frame ---
  // Shows the "X in a Box" for 2 seconds
  matrix.displayFrame(xRectFrame, 2000);

  // Small gap of darkness (optional)
  delay(200);

  // --- Method 2: Play an animation ---
  // Plays HELLO with 800ms per letter
  matrix.playAnimation(hello_animation, animCount, 800);

  // Wait 1 second before restarting the whole loop
  delay(1000);
}