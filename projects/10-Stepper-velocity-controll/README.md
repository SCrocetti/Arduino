# 10-Stepper-Velocity-Control

Welcome to the **10-Stepper-Velocity-Control** project.  
The purpose of this project is to control the **velocity and direction** of a **28BYJ-48 stepper motor** using an **Arduino UNO**, a **ULN2003 driver board**, a **potentiometer**, and an **external 6 V power supply made from 4× AA batteries**.

The potentiometer is used as an analog input, where **half of its range controls counterclockwise rotation** and the **other half controls clockwise rotation**, with the center position stopping the motor.

---

## Overview

In this project, the **Arduino UNO** reads the position of a **potentiometer** connected to its analog input (A0). The analog value (0–1023) is used to determine both the **direction** and **speed** of a **28BYJ-48 stepper motor**.

The motor is driven through a **ULN2003 Darlington transistor array**, while being powered by an **external 6 V battery pack (4× AA batteries)**. The Arduino is powered separately (via USB) and is only responsible for control logic.

---

## Potentiometer Signal Mapping

The potentiometer works as a **voltage divider**, producing a voltage between **0 V and 5 V**, which the Arduino converts into a digital value between **0 and 1023**.

This range is divided into two halves:

- **0 – 511** → Counterclockwise rotation  
  - 0 = maximum speed  
  - 511 = stop  

- **512 – 1023** → Clockwise rotation  
  - 512 = stop  
  - 1023 = maximum speed  

---

## Behavior

- Turning the potentiometer fully to the **left** causes the motor to rotate at **maximum speed in the counterclockwise direction**.
- As the potentiometer approaches the **center position**, the motor **slows down** until it **stops**.
- Passing the center point changes the **direction of rotation**.
- Turning the potentiometer fully to the **right** increases the speed in the **clockwise direction** until it reaches **maximum speed**.

---

## Components

- **Arduino UNO**  
  Reads the potentiometer value and generates control signals for the stepper motor.

- **28BYJ-48 Stepper Motor (5 V)**  
  Unipolar stepper motor used for speed and direction control.

- **ULN2003 Stepper Motor Driver Board**  
  Provides current amplification and protects the Arduino I/O pins.

- **Potentiometer (e.g., 10 kΩ)**  
  Used to control speed and direction.

- **4× AAA batteries (≈6 V total)**  
  External power supply for the stepper motor.

- **Battery holder for 4× AAA cells**

- **Jumper wires**

---

## Power Supply Strategy

- The **stepper motor and ULN2003** are powered by an **external 6 V supply** made from **4 AAA batteries connected in series**.
- The **Arduino UNO is powered via USB**.
- The Arduino **does not power the motor**.

This separation improves stability and prevents voltage drops or resets caused by motor current spikes.

---

## Circuit Description

### Potentiometer
- One outer pin → **Arduino 5 V**
- Other outer pin → **Arduino GND**
- Center (wiper) pin → **Arduino A0**

### ULN2003 Driver
- **IN1–IN4** → Arduino digital output pins
- **GND** → Arduino **GND**
- **VCC** → **+6 V from the AAA battery pack**

### Stepper Motor
- Connected directly to the ULN2003 motor connector

### Ground Reference (Critical)
The **negative terminal of the battery pack MUST be connected to Arduino GND** to ensure a common reference for control signals.

---

## Notes and Warnings

- Do **NOT** connect the 6 V battery pack to the Arduino **5 V pin**.
- Do **NOT** power the stepper motor from the Arduino.
- Ensure all grounds are connected.
- If the motor becomes hot or stalls, disconnect power immediately.

---

## Circuit Diagram

You can find the schematic and wiring diagram in the `circuit/` folder.