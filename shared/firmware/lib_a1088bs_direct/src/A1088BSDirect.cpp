#include "A1088BSDirect.h"

A1088BSDirect::A1088BSDirect(const uint8_t pins[8][8][2])
{
  // Copy provided pin mapping into the class instance
  memcpy(_pins, pins, sizeof _pins);
  
  // Configure Matrix I/O
  for (uint8_t i = 0; i < 8; i++) {
      // Direct pin access: index 0 for Row Anodes, index 1 for Column Cathodes
      uint8_t rowPin = _pins[i][0][0];   
      uint8_t colPin = _pins[0][i][1];   
      
      pinMode(rowPin, OUTPUT);
      pinMode(colPin, OUTPUT);
      
      // Start-up safety: Set Cathodes HIGH (Inactive) to prevent initial ghosting
      digitalWrite(colPin, HIGH);
      digitalWrite(rowPin, LOW);
  }
}

void A1088BSDirect::displayFrame(const bool frame[8][8], uint16_t durationMs) {
  // Benchmark-derived constant: 1ms / 4.744ms per sweep = 0.2108 sweeps per ms.
  const float frequency = 0.2108f; 
  const int sweeps = (int)(frequency * durationMs);

  for (int k = 0; k < sweeps; ++k) {
    for (int row = 0; row < 8; ++row) {
      uint8_t rowPin = _pins[row][0][0];

      // 1. Column Setup: Define which LEDs in this row will sink current.
      for (int col = 0; col < 8; ++col) {
        // LOW = ON (sink), HIGH = OFF (block) for Common Anode matrices
        digitalWrite(_pins[row][col][1], frame[row][col] ? LOW : HIGH);
      }

      // 2. Pulse: Activate the specific row anode.
      digitalWrite(rowPin, HIGH);
      
      // 3. POV Delay: Maintain state to satisfy human visual persistence.
      delayMicroseconds(500); 

      // 4. Ghosting Prevention: Kill the row circuit before moving to the next set.
      digitalWrite(rowPin, LOW); 
    }
  }
}

void A1088BSDirect::playAnimation(const bool *const frames[], uint8_t frame_count,
                                 uint16_t frameDurationMs) {
  for (uint8_t i = 0; i < frame_count; ++i) {
    // Cast the flat pointer from the array into the 8x8 matrix format expected by displayFrame
    const bool (*frame)[8] = reinterpret_cast<const bool (*)[8]>(frames[i]);
    displayFrame(frame, frameDurationMs);
  }
}