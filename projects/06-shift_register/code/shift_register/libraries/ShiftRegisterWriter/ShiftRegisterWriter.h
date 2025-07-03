#pragma once
#include <Arduino.h>

/**
 * @class ShiftRegisterWriter
 * @brief Minimal wrapper around Arduino's `shiftOut()`.
 *
 * Provides a compile‑time **default** bit‑order (set in the constructor)
 * and a per‑call override, so you can toggle MSB/LSB without keeping two
 * separate objects.
 */
class ShiftRegisterWriter {
public:
    /**
     * @brief Construct a writer for a 74HC595‑style shift register.
     *
     * @param dataPin         MCU pin wired to SER (DS).
     * @param clockPin        MCU pin wired to SRCLK.
     * @param latchPin        MCU pin wired to RCLK.
     * @param defaultBitOrder Default bit‑order used by the one‑parameter
     *                        write call (`MSBFIRST` by default).
     */
    ShiftRegisterWriter(uint8_t dataPin,
                        uint8_t clockPin,
                        uint8_t latchPin,
                        uint8_t defaultBitOrder = MSBFIRST);

    /** @brief Configure the three pins as outputs. */
    void begin();

    /**
     * @brief Write one byte with the default bit‑order.
     *
     * Equivalent to `write(value, defaultBitOrder)`.
     *
     * @param value Byte to shift out.
     */
    void write(uint8_t value);

    /**
     * @brief Write one byte, choosing bit‑order on the fly.
     *
     * @param value    Byte to shift out.
     * @param bitOrder `MSBFIRST` or `LSBFIRST`.
     */
    void write(uint8_t value, uint8_t bitOrder);

private:
    uint8_t _dataPin;
    uint8_t _clockPin;
    uint8_t _latchPin;
    uint8_t _defaultBitOrder;
};
