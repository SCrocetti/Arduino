# 03 - LED Matrix Sweep

Welcome to the **03 - LED Matrix Sweep** project!  
The purpose of this project is to make an 8x8 LED matrix sweep its leds forming an image represented as a boolean array starting from the LED at **row 2, column 2** and ending at **row 7, column 7**.

---

## Overview

In this project, we'll control a subset of an 8x8 LED matrix using an Arduino UNO. We'll activate the leds one row at the time making a sweep to give the ilusion of a fix image. Only the inner 6×6 area of the matrix (rows 2–7, columns 2–7) is used.

---

## Components

- 1 × Arduino UNO  
- 1 × 1088B8 8×8 LED Matrix  
- 6 × 10kΩ Resistors  
- Breadboard and jumper wires  

## Led matrix pinout
![Led matrix pinout](./asets/Led_matrix_8x8.png)

[Pinout reference](./asets/Pinout%20reference.md)

[Conections](./asets/Conections.md)

## Circuit Description

The 1088B8 LED matrix has 8 anode pins (rows) and 8 cathode pins (columns), connected in a specific pattern. We connect:

- **Even-numbered Arduino pins (2, 4, 6, 8, 10, 12)** to **row pins (anodes)** of the LED matrix from row 2 to 7.
- **Odd-numbered Arduino pins (3, 5, 7, 9, 11, 13)** to **column pins (cathodes)** of the LED matrix from column 2 to 7.

The code dynamically switches these pins HIGH and LOW to activate specific LEDs in a time-multiplexed fashion.

To prevent ghosting and LED backfeed, all unused cathodes are held HIGH (so they don’t sink current) while only one is pulled LOW at a time.

---

## Circuit Diagram

You can find the schematic and wiring diagram and the library for the led matrix in the `circuit/` folder.


![Shematic and wiring diagram](./asets/circuit_schemma.png)
