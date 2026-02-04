# 09-RFID-experiments

Welcome to the **09-RFID-experiments** project. The purpose of this project is to program and read RFID tags using the **RFID-RC522** module and an **Arduino**.

---

## Overview

In this project, we use the **MFRC522** library to read from and write to RFID tags.

- The system starts in **read mode** by default  
- Two **push buttons** are used to switch between **read** and **write** modes  
- Two **LEDs** indicate the current mode:
  - 🟢 **Green LED** → Read mode  
  - 🔴 **Red LED** → Write mode  

### Behavior

- **Read mode**
  - Reads the RFID tag UID and stored data
  - Sends the information to the serial console via USB

- **Write mode**
  - Writes a **fixed text** to the RFID tag
  - Useful for testing and validating tag programming
---

## Components

- Arduino (Uno / Nano / compatible board)
- RFID-RC522 module
- RFID tags or cards (13.56 MHz)
- 2 × Push buttons
- 2 × LEDs (1 green, 1 red)
- 2 × Resistors (220 Ω for LEDs)
- 2 × Resistors (10 kΩ for button pull-ups)
- Breadboard
- Jumper wires

---

## Circuit Description

### RFID-RC522 Connections

The RC522 module communicates with the Arduino using the **SPI** protocol.

| RC522 Pin | Arduino Pin |
|----------|-------------|
| SDA (SS) | D10 |
| SCK     | D13 |
| MOSI    | D11 |
| MISO    | D12 |
| RST     | D9  |
| 3.3V    | 3.3V |
| GND     | GND |

> ⚠️ **Important:** The RC522 operates at **3.3V**. Do **not** connect it to 5V.

---
### Leds

Each led is conected to a current limiting resistor  to **GND** and are powered by the digital output pins D4 for the green led and D5 for the red led

### Buttons (Using External Pull-Up Resistors)

Each button uses an **external pull-up resistor** to ensure a stable default logic level.

#### Button functions

The two buttons, one for setting the read mode and one for setting the write mode, are conected to the digital inputs D2 and D3 respectibly.

To set the mode, hold the respective button until the respective ligth turns on and the other one off, green for reading and red for writing 

#### Wiring

For **each button**:

- One terminal of the button → **GND**
- Other terminal of the button → **Digital input pin**
- **10 kΩ resistor** between the digital input pin and **5V**

This creates a pull-up configuration.



## Circuit Diagram

You can find the schematic and wiring diagram in the `circuit/` folder.

