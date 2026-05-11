# A1088BSDirect

[English](#english) | [Español](#espanol)

---

## 🇺🇸 English
<a id="english"></a>

A high-performance, direct-drive Arduino library for **1088BS 8x8 LED Matrices** (Common Anode). This library uses a benchmarked multiplexing engine to ensure flicker-free display and accurate animation timing.

---

### 🚀 Features
* **Ghosting Prevention**: Implements a "Row-Kill" logic to ensure crisp transitions between LEDs.
* **Calibrated Timing**: Uses a hardware-measured frequency (0.2108 sweeps/ms) to ensure `durationMs` matches real-world time.
* **Flexible Pinout**: Supports custom PCB layouts via a dedicated configuration header.
* **Low Memory Footprint**: Minimal overhead, ideal for ATmega328P (Uno/Nano) projects.

---

## 📁 Library Structure

```text
lib_a1088bs_direct
├── src
│   ├── A1088BSDirect.h        # Main Class & Logic
│   ├── A1088BSDirect.cpp      # Implementation
│   └── A1088BSDirectConfig.h  # User Pin Configuration
├── examples
│   └── BasicUsage             # Full Demo (Static + Animation)
├── keywords.txt               # IDE Syntax Highlighting
└── library.properties         # IDE Metadata
```
---

### 🛠️ Installation & Setup
1. **Move the Folder**: Move the `lib_a1088bs_direct` folder into your `Arduino/libraries` directory.
2. **Library Configuration**: The library is designed to be flexible. You can modify the pin mapping without changing the core logic by editing the configuration files:
    * `A1088BSDirect.h`: Defines the base pinout.
    * `A1088BSDirectConfig.h`: Allows customizations for different PCB or breadboard layouts.
3. **Verify Pinout**: Open `src/A1088BSDirectConfig.h` to verify that the pin mapping matches your physical wiring.
4. **Restart IDE**: Restart your Arduino IDE.
---

### 💻 Quick Start
To get started, initialize the library using the `LEDMATRIX_PINOUT` defined in `A1088BSDirectConfig.h` file. You can then use `displayFrame` for static images or `playAnimation` to iterate through an array of frames.

``` c++
#include <A1088BSDirect.h>
#include <A1088BSDirectConfig.h>

// 1. Static Frame: "X inside a rectangle"
const bool xRectFrame[8][8] = {
  {1,1,1,1,1,1,1,1}, {1,1,0,0,0,0,1,1}, {1,0,1,0,0,1,0,1}, {1,0,0,1,1,0,0,1},
  {1,0,0,1,1,0,0,1}, {1,0,1,0,0,1,0,1}, {1,1,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1}
};

// 2. Animation Frames: Neutral to Happy
const bool neutral_face[8][8] = {
  {0,0,1,1,1,1,0,0}, {0,1,0,0,0,0,1,0}, {1,0,1,0,0,1,0,1}, {1,0,0,0,0,0,0,1},
  {1,0,1,1,1,1,0,1}, {1,0,0,0,0,0,0,1}, {0,1,0,0,0,0,1,0}, {0,0,1,1,1,1,0,0}
};

const bool happy_face[8][8] = {
  {0,0,1,1,1,1,0,0}, {0,1,0,0,0,0,1,0}, {1,0,1,0,0,1,0,1}, {1,0,0,0,0,0,0,1},
  {1,0,1,0,0,1,0,1}, {1,0,0,1,1,0,0,1}, {0,1,0,0,0,0,1,0}, {0,0,1,1,1,1,0,0}
};

A1088BSDirect matrix(LEDMATRIX_PINOUT);

const bool* const emotion_anim[] = { &neutral_face[0][0], &happy_face[0][0] };
const uint8_t animCount = sizeof(emotion_anim) / sizeof(emotion_anim[0]);

void setup() { /* Handled by constructor */ }

void loop() {
  // Method 1: Static Frame (2 seconds)
  matrix.displayFrame(xRectFrame, 2000);

  delay(200);

  // Method 2: Animation (1 second per frame)
  matrix.playAnimation(emotion_anim, animCount, 1000);

  delay(1000);
}
```

---

### 🔌 Hardware Connections
The library is designed for **Common Anode** matrices. By default, the logic assumes:
* **Rows (Anodes)**: Triggered **HIGH** to provide power.
* **Columns (Cathodes)**: Triggered **LOW** to sink current.

For detailed schematics, wiring diagrams, and the reference PCB layout used during development, please refer to the project documentation:
👉 **[Reference Project & Wiring Guide](../../../projects/04_8x8_led_matrix_drawer/README.md)**

---

## 🇪🇸 Español
<a id="espanol"></a>

Una librería de Arduino de alto rendimiento para el control directo de **Matrices LED 1088BS 8x8** (Ánodo Común). Esta librería utiliza un motor de multiplexado calibrado para asegurar una visualización sin parpadeos y tiempos de animación precisos.

---

### 🚀 Características
* **Prevención de Ghosting**: Implementa una lógica de "limpieza de fila" (Row-Kill) para asegurar transiciones nítidas entre LEDs.
* **Sincronización Calibrada**: Utiliza una frecuencia medida por hardware (0.2108 barridos/ms) para asegurar que el tiempo en milisegundos sea real.
* **Pinout Flexible**: Soporta layouts de PCB personalizados mediante un encabezado de configuración dedicado.
* **Bajo Consumo de Memoria**: Sobrecarga mínima, ideal para proyectos con ATmega328P (Uno/Nano).

---

## 📁 Estructura de la librería

```text
lib_a1088bs_direct
├── src
│   ├── A1088BSDirect.h        # Main Class & Logic
│   ├── A1088BSDirect.cpp      # Implementation
│   └── A1088BSDirectConfig.h  # User Pin Configuration
├── examples
│   └── BasicUsage             # Full Demo (Static + Animation)
├── keywords.txt               # IDE Syntax Highlighting
└── library.properties         # IDE Metadata
```

---

### 🛠️ Instalación y Configuración
1. **Mover la Carpeta**: Mueva la carpeta `lib_a1088bs_direct` a su directorio de `Arduino/libraries`.
2. **Configuración de la Librería**: La librería está diseñada para ser flexible. Es posible modificar el mapeo de pines sin cambiar la lógica central editando los archivos de configuración:
    * `A1088BSDirect.h`: Define el pinout base.
    * `A1088BSDirectConfig.h`: Permite personalizaciones para diferentes layouts de PCB o protoboard.
3. **Verificar Configuración**: Abra `src/A1088BSDirectConfig.h` para verificar que el mapeo de pines coincida con su cableado físico.
4. **Reiniciar IDE**: Reinicie su IDE de Arduino.
---

### 💻 Inicio Rápido
Para comenzar, inicialice la librería utilizando el `LEDMATRIX_PINOUT` definido en el archivo `A1088BSDirectConfig.h`. Luego puede usar `displayFrame` para imágenes estáticas o `playAnimation` para iterar a través de un array de cuadros.


``` c++
#include <A1088BSDirect.h>
#include <A1088BSDirectConfig.h>

// 1. Static Frame: "X inside a rectangle"
const bool xRectFrame[8][8] = {
  {1,1,1,1,1,1,1,1}, {1,1,0,0,0,0,1,1}, {1,0,1,0,0,1,0,1}, {1,0,0,1,1,0,0,1},
  {1,0,0,1,1,0,0,1}, {1,0,1,0,0,1,0,1}, {1,1,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1}
};

// 2. Animation Frames: Neutral to Happy
const bool neutral_face[8][8] = {
  {0,0,1,1,1,1,0,0}, {0,1,0,0,0,0,1,0}, {1,0,1,0,0,1,0,1}, {1,0,0,0,0,0,0,1},
  {1,0,1,1,1,1,0,1}, {1,0,0,0,0,0,0,1}, {0,1,0,0,0,0,1,0}, {0,0,1,1,1,1,0,0}
};

const bool happy_face[8][8] = {
  {0,0,1,1,1,1,0,0}, {0,1,0,0,0,0,1,0}, {1,0,1,0,0,1,0,1}, {1,0,0,0,0,0,0,1},
  {1,0,1,0,0,1,0,1}, {1,0,0,1,1,0,0,1}, {0,1,0,0,0,0,1,0}, {0,0,1,1,1,1,0,0}
};

A1088BSDirect matrix(LEDMATRIX_PINOUT);

const bool* const emotion_anim[] = { &neutral_face[0][0], &happy_face[0][0] };
const uint8_t animCount = sizeof(emotion_anim) / sizeof(emotion_anim[0]);

void setup() { /* Handled by constructor */ }

void loop() {
  // Method 1: Static Frame (2 seconds)
  matrix.displayFrame(xRectFrame, 2000);

  delay(200);

  // Method 2: Animation (1 second per frame)
  matrix.playAnimation(emotion_anim, animCount, 1000);

  delay(1000);
}
```


---

### 🔌 Conexiones de Hardware
La librería está diseñada para matrices de **Ánodo Común**. Por defecto, la lógica asume:
* **Filas (Ánodos)**: Activadas en **ALTO** (HIGH) para proveer energía.
* **Columnas (Cátodos)**: Activadas en **BAJO** (LOW) para drenar corriente.

Para esquemas detallados, diagramas de cableado y el layout de PCB de referencia usado durante el desarrollo, consulte la documentación del proyecto:
👉 **[Guía de Conexión y Proyecto de Referencia](../../../projects/04_8x8_led_matrix_drawer/README.md)**

---