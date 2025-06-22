# 02-Relay, LEDs, and Tactile Switch

Welcome to the **02-Relay, LEDs, and Tactile Switch** project.  
The goal is to use a **tactile button** to send a signal to the **Arduino**, which will then **toggle a relay**. The relay in turn controls two LEDs that indicate its state.

---

## 🧰 Components Required

- 1 x Arduino Uno (or compatible board)  
- 1 x Relay module (Tongling JQC-3FF-S-Z)  
- 1 x Breadboard  
- 1 x Green LED  
- 1 x Red LED  
- 2 x 220Ω resistors (for LEDs)  
- 1 x Tactile pushbutton switch  
- 1 x 10kΩ resistor (pull-down for button)  
- Jumper wires  
- Power supply (5V from Arduino or external)

---

## 🔌 Circuit Description

The project uses a **relay to control two LEDs**, and a **tactile button** to tell the Arduino when to toggle the relay.

- 🔴 **Red LED**: ON by default, OFF when relay is active  
- 🟢 **Green LED**: OFF by default, ON when relay is active  
- 🔘 **Tactile Button**: Used to toggle the relay

---

### 1. 🧠 Relay Control (Arduino to Relay Module)

The relay is triggered using one of Arduino’s digital output pins.

- `IN` → Arduino digital pin (e.g., pin 7)  
- `VCC` → Arduino 5V  
- `GND` → Arduino GND  

> When the Arduino sets the pin LOW, the relay activates (assuming active-low logic).

---

### 2. 👆 Button Input (Tactile Switch to Arduino)

The tactile switch is connected as a digital input with a pull-down resistor.

- One leg of the button → Arduino digital pin (e.g., pin 2)  
- Same leg → 10kΩ resistor → GND  
- Opposite leg → 5V  

> When pressed, the pin reads HIGH. When released, it reads LOW.

---

### 3. 💡 Load Switching (Relay to LEDs)

The relay switches 5V to either of the LEDs depending on its state.

#### 🔴 Red LED (Normally ON)
- `COM` on relay → 5V  
- `NC` on relay → Anode of red LED  
- Cathode → 220Ω resistor → GND  

> ON when the relay is idle.

#### 🟢 Green LED (Activated ON)
- `COM` on relay → 5V  
- `NO` on relay → Anode of green LED  
- Cathode → 220Ω resistor → GND  

> ON only when the relay is activated.

---

## 🪛 Wiring Summary

```text
[Arduino Pin 7] ---> [IN on Relay Module]
[Arduino 5V] -----> [VCC on Relay Module]
[Arduino GND] ----> [GND on Relay Module]

[+5V] ------------> [COM on Relay]

[NC on Relay] ----> [Red LED + 220Ω] ---> [GND]
[NO on Relay] ----> [Green LED + 220Ω] ---> [GND]

[Button Side 1] ---> [Arduino Pin 2]
[Button Side 1] ---> [10kΩ Resistor] ---> [GND]
[Button Side 2] ---> [5V]