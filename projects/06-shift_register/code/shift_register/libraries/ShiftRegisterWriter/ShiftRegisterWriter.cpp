#include "ShiftRegisterWriter.h"

/* ------------------------------------------------------------------ */
/* Constructor                                                        */
/* ------------------------------------------------------------------ */
ShiftRegisterWriter::ShiftRegisterWriter(uint8_t dataPin,
                                         uint8_t clockPin,
                                         uint8_t latchPin,
                                         uint8_t defaultBitOrder)
    : _dataPin(dataPin),
      _clockPin(clockPin),
      _latchPin(latchPin),
      _defaultBitOrder(defaultBitOrder) {}

/* ------------------------------------------------------------------ */
/* Public methods                                                     */
/* ------------------------------------------------------------------ */
void ShiftRegisterWriter::begin()
{
    pinMode(_dataPin,  OUTPUT);
    pinMode(_clockPin, OUTPUT);
    pinMode(_latchPin, OUTPUT);
}

void ShiftRegisterWriter::write(uint8_t value)
{
    // Delegate to the two‑parameter overload with the default bit‑order.
    write(value, _defaultBitOrder);
}

void ShiftRegisterWriter::write(uint8_t value, uint8_t bitOrder)
{ 
    digitalWrite(_latchPin, LOW);
    shiftOut(_dataPin, _clockPin, bitOrder, value);
    digitalWrite(_latchPin, HIGH);
}
