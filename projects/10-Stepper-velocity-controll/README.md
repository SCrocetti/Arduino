# 10-Stepper-Velocity-Control

Welcome to the **10-Stepper-Velocity-Control** project.  
The purpose of this project is to control the **velocity and direction** of a **28BYJ-48 stepper motor** using an **Arduino UNO** with the **stepper** library , a **ULN2003 driver board**, a **potentiometer**, and an **external 6 V power supply made from 4× AA batteries**.

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

### Where the max speed comes from

For stepper motors, **maximum speed is not a single fixed value** like it is for DC motors. Instead, it is inferred from the **datasheet step frequencies**, combined with the **step angle** and, in this case, the **gearbox reduction**.

From the datasheet:

- **Stride angle (internal motor)**: `5.625°`
- **Gear reduction**: `64 : 1`

This gives the number of steps per output shaft revolution:


``` math
  360° / (5.625° / 64) ≈ 4096 steps
```



So:

> **4096 steps = 1 full revolution of the output shaft**

---

### Key speed-related specifications

The most relevant datasheet parameters are:

- **Rated frequency**: `100 Hz`
- **Idle in-traction frequency**: `> 600 Hz`
- **Idle out-traction frequency**: `> 1000 Hz`

In practical terms:

- **100 Hz** → safe, reliable operation with usable torque  
- **600 Hz** → highest frequency at which the motor can **start from rest**  
- **1000 Hz** → highest frequency the motor can **sustain once already spinning**, with no load

---

### Converting frequency to RPM (output shaft)

Formula:

``` math
  RPM = (frequency × 60) / steps_per_revolution
```

**Safe working speed (recommended):**

``` math
  RPM = (100 × 60) / 4096 ≈ 1.46 RPM
```

**Practical upper limit (already spinning, no load):**

``` math
  RPM = (1000 × 60) / 4096 ≈ 14.6 RPM
```
---

### Real-world takeaway

- ✅ **Reliable usable speed**: **1–5 RPM**
- ⚠️ **Upper practical limit**: **~10–15 RPM**
- ❌ **Above this range**:
  - Missed steps
  - Negligible torque
  - Audible buzzing with little or no rotation

#### Step Timing and Delay Calculations

To control the speed of a stepper motor, we calculate the **time between steps** based on the desired rotational speed.


### Time per step

``` math
  t_step = 60 / (speed × stepsPerRevolution)
```

Where:
- `t_step` → time for a single step (seconds)
- `speed` → motor speed in **RPM**
- `stepsPerRevolution` → total steps for one full revolution

This formula converts RPM (revolutions per minute) into the delay needed between individual steps.

### Maximum delay window

``` math
  steps = maxDelay / t_step
```


If the available delay time is known, this formula tells us how many steps can be executed within that window.

### Combined expression

Substituting `t_step` into the equation:

``` math
  steps = (maxDelay × speed × stepsPerRevolution) / 60
```


For example, if `maxDelay = 30 ms`:


``` math
  steps = (30 / 1000 )× speed × stepsPerRevolution/ 60
```
reducing that we got 

``` math
  steps = speed × stepsPerRevolution/2000
```

substituing from the datasheet

``` math
  steps = speed × 4096/2000
```

aproximatly

``` math
  steps=speed  × 2
```
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

![Circuit schematic](./asets/circuit_shemma.png)