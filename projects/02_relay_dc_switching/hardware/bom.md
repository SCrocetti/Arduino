# 📑 Bill of Materials: 02 - Relay DC Switching

[English](#english) | [Español](#espanol)

---

## 🇺🇸 English
<a id="english"></a>

### 🛠️ Core Components
| Ref | Component | Value | Package | Description |
| :--- | :--- | :--- | :--- | :--- |
| **U1** | Arduino Uno | R3 | Board | Main Microcontroller |
| **K1** | Relay Module | 5V Coil | Module | JQC-3FF-S-Z or similar |
| **D1** | Green LED | 5mm | THT | Active State Indicator |
| **D2** | Red LED | 5mm | THT | Idle State Indicator |
| **R1, R2**| Resistor | 10kΩ* | Axial | LED Current Limiter (for 9V) |
| **R3** | Resistor | 10kΩ | Axial | Button Pull-down |
| **S1** | Push Button | 6x6mm | 4-pin THT | Tactile Switch |
| **BT1** | Battery | 9V | PP3 | External Load Power |

> \* *Note: 10kΩ resistors for the LEDs will result in very low brightness. Consider 470Ω - 1kΩ if using standard LEDs with a 9V source.*

### 🔌 Connection & Prototyping
* **Breadboard**: 1x Full-size.
* **9V Battery Clip**: 1x with jumper wire ends.
* **Jumper Wires**: Assorted Male-to-Male (M-M).

---

## 🇪🇸 Español
<a id="espanol"></a>

### 🛠️ Componentes Principales
| Ref | Componente | Valor | Encapsulado | Descripción |
| :--- | :--- | :--- | :--- | :--- |
| **U1** | Arduino Uno | R3 | Placa | Microcontrolador Principal |
| **K1** | Módulo Relé | Bobina 5V | Módulo | JQC-3FF-S-Z o similar |
| **D1** | LED Verde | 5mm | THT | Indicador de Estado Activo |
| **D2** | LED Rojo | 5mm | THT | Indicador de Estado Inactivo |
| **R1, R2**| Resistencia | 10kΩ* | Axial | Limitador LED (para 9V) |
| **R3** | Resistencia | 10kΩ | Axial | Pull-down de Botón |
| **S1** | Pulsador | 6x6mm | 4-pin THT | Interruptor Táctico |
| **BT1** | Batería | 9V | PP3 | Energía de Carga Externa |

---