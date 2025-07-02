# 06-Shift register

Welcome to the **06-Shift register** project! The goal of this mini-lab is to create an Arduino library to send serial data to a **74HC595** shift register and visualize each transmitted byte by turning eight LEDs on or off.

## Overview
A shift register is an integrated circuit that converts serial data (one bit at a time) into parallel outputs (all eight bits at once). By cascading shift registers you can drive dozens of outputs while using only three GPIO pins on the Arduino.

In this project you will:

- Wire a 74HC595 to an Arduino Uno.
- Write a sketch that clocks out different patterns (text glyphs, counters, and animations).
- Observe the output on an array of eight LEDs.
- Learn how the **SRCLK**, **RCLK**, and **SER** signals interact.
- Expand the design to multiple registers (optional).

## Components

| Qty | Component                        | Notes                                       |
|-----|----------------------------------|---------------------------------------------|
| 1   | Arduino Uno (or compatible)      | Any 5 V Arduino board works                 |
| 1   | 74HC595 8-bit shift register     | DIP-16 package is easiest to breadboard     |
| 8   | LEDs                             | Any color; use diffused types for uniform brightness |
| 8   | 220 Ω resistors                  | Limits current through each LED            |
| 1   | Breadboard                       | Half-size is enough                         |
| 20+ | Jumper wires                     | M/M for breadboard connections              |
| 1   | USB cable                        | To power and program the Arduino            |
| *Optional* | Second 74HC595 + 8 LEDs | For 16-bit demo                             |

## Circuit Description

1. **Power & Ground**  
   - Connect **VCC** (pin 16) of the 74HC595 to the Arduino **5 V** pin.  
   - Connect **GND** (pins 8 & 13) to Arduino **GND**.

2. **Control Signals**  
   - **SER** (serial data, pin 14) → Arduino **D11**  
   - **SRCLK** (shift clock, pin 11) → Arduino **D13**  
   - **RCLK** (storage/latch clock, pin 12) → Arduino **D8**

3. **Reset & Output-Enable**  
   - Tie **MR** (reset, pin 10, active-low) to **5 V**.  
   - Tie **OE** (output enable, pin 13, active-low) to **GND**.

4. **Outputs to LEDs**  
   - **QA–QH** (pins 15, 1, 2, 3, 4, 5, 6, 7) each connect through a 220 Ω resistor to the anode of an LED.  
   - The cathodes of all LEDs go to **GND**.

> **Tip:** If the LEDs light in reverse order, swap the bit order in code or rotate the IC 180°.

### Example Arduino Pin Map

| 74HC595 Pin | Function   | Arduino Pin |
|-------------|------------|-------------|
| 14          | SER        | 11          |
| 11          | SRCLK      | 13          |
| 12          | RCLK       | 8           |
| 10          | ~MR        | 5 V         |
| 13          | ~OE        | GND         |
| 16          | VCC        | 5 V         |
| 8           | GND        | GND         |

## Circuit Diagram

You can follow the breadboard-friendly diagram below or open the accompanying **Fritzing** file in the project folder.

![Shematic and wiring diagram](./asets/circuit_schemma)