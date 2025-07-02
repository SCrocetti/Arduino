#pragma once
#include <Arduino.h>

class ShiftRegisterWriter {
  public:
    ShiftRegisterWriter(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t bitOrder = MSBFIRST);

    void begin();
    void write(uint8_t value);

  private:
    uint8_t _dataPin;
    uint8_t _clockPin;
    uint8_t _latchPin;
    uint8_t _bitOrder;
};