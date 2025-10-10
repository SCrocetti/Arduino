# 02-Relay, LEDs, and Tactile Switch (with 9 V Battery Power)

Welcome to the **02-Relay, LEDs, and Tactile Switch** project.  
The goal is to use a **tactile button** to send a signal to the **Arduino**, which will **toggle a relay**.  
The relay will then **switch a 9 V DC battery** that powers two LEDs to indicate the relay’s state.

---

## 🧰 Components Required

- 1 × Arduino Uno (or compatible board)  
- 1 × Relay module (Tongling JQC-3FF-S-Z or similar 5 V coil)  
- 1 × Breadboard  
- 1 × Green LED  
- 1 × Red LED  
- 2 × 220 Ω resistors (for LEDs)  
- 1 × Tactile pushbutton switch  
- 1 × 10 kΩ resistor (pull-down for button)  
- 1 × 9 V battery + clip connector  
- Jumper wires  

> ⚠️ **Note:** The relay module’s coil is powered by the Arduino (5 V), but the **load circuit (LEDs)** is powered separately by the **9 V battery**.

---

## 🔌 Circuit Description

The project uses a **relay to switch a 9 V battery** that powers two LEDs.  
The **Arduino** controls the relay through a digital output pin, and a **tactile button** tells the Arduino when to toggle the relay.

- 🔴 **Red LED** – ON when relay is idle (NC contact)  
- 🟢 **Green LED** – ON when relay is active (NO contact)  
- 🔘 **Tactile Button** – Used to toggle the relay  

---

### 1. 🧠 Relay Control (Arduino to Relay Module)

| Relay Pin | Connection |
|------------|-------------|
| IN | Arduino digital pin 7 |
| VCC | Arduino 5 V |
| GND | Arduino GND |

> The Arduino triggers the relay (active LOW or HIGH depending on the module).

---

### 2. 👆 Button Input (Tactile Switch to Arduino)

| Button Pin | Connection |
|-------------|-------------|
| One leg | Arduino digital pin 3 |
| Same leg | 10 kΩ resistor → GND |
| Opposite leg | 5 V |

> When pressed, the pin reads HIGH. When released, it reads LOW.

---

### 3. 💡 Load Switching (Relay to 9 V LEDs)

The **relay** switches the **9 V battery** supply to the LEDs instead of the Arduino’s 5 V.

#### 🔴 Red LED (Normally ON)
- **9 V battery positive (+)** → `COM` on relay  
- `NC` on relay → Anode of **Red LED**  
- Cathode → **220 Ω resistor** → **9 V battery negative (−)**  

> Red LED is ON when relay is idle.

#### 🟢 Green LED (Activated ON)
- **9 V battery positive (+)** → `COM` on relay  
- `NO` on relay → Anode of **Green LED**  
- Cathode → **220 Ω resistor** → **9 V battery negative (−)**  

> Green LED turns ON when relay is activated.

---

## 🪛 Wiring Summary

```text
[Arduino Pin 7] ---> [IN on Relay Module]
[Arduino 5V] -----> [VCC on Relay Module]
[Arduino GND] ----> [GND on Relay Module]

[9V (+)] ---------> [COM on Relay]
[NC] --------------> [Red LED + 220Ω] ---> [9V (−)]
[NO] --------------> [Green LED + 220Ω] ---> [9V (−)]

[Button Side 1] ---> [Arduino Pin 3]
[Button Side 1] ---> [10kΩ Resistor] ---> [GND]
[Button Side 2] ---> [5V]
