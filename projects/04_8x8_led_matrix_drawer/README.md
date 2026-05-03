# 🔹 04 - LED Matrix Drawer Library / 04 - Librería de Dibujo para Matriz LED

[English](#english) | [Español](#espanol)

---

## 🇺🇸 English
<a id="english"></a>

### Overview
This project introduces a specialized Arduino library designed to control a **full 8x8 LED matrix (1088BS)**. Moving beyond basic sequential sweeps, this library provides a high-level abstraction for "drawing" static frames and complex animations by managing low-level multiplexing and timing.

### Features
* **Full 8x8 Support**: High-resolution icons and patterns using all 64 LEDs.
* **Configurable Pinout**: Flexible architecture that allows redefining row and column pins via software to match any hardware layout.
* **Frame Buffering**: Display static images defined as bitmaps.
* **Animation Engine**: Sequence-based playback with configurable frame delays.
* **Ghosting Prevention**: Implementation of high-impedance states and active-high/low logic to ensure visual clarity.

### Hardware Components
| Component | Quantity | Description |
| :--- | :--- | :--- |
| **Arduino Uno / Nano** | 1 | Control logic unit |
| **1088BS 8x8 LED Matrix** | 1 | Common Anode display |
| **Resistors (220Ω - 1kΩ)** | 8 | Current limiters for cathode lines |
| **Jumper Wires** | 24+ | Assorted connections |

> [!NOTE]
> For the complete part list, check the [BOM](../../shared/hardware/A-1088B8-Direct/bom.md) in the hardware folder.

## Hardware Documentation

This section contains technical specifications and wiring diagrams required to interface with the library.

### Technical Reference
For specific wiring details and coordinate mapping, refer to the following documents:

* 📍 [**Pinout Reference**](../../docs/hardware_ref/A-1088B8/pinout_reference.md) — Mapping of physical pins to rows and columns.
* 🔗 [**Connection Guide**](../../shared/hardware/A-1088B8-Direct/connections.md) — Step-by-step wiring for microcontrollers.
* 📄 [**LED Matrix Datasheet**](../../docs/datasheets/A-1088BS-1.pdf) — Full manufacturer specifications.

---

### Library Configuration
The library is designed for flexibility. You can modify the pin mapping without changing the core logic by editing the configuration files:
* `LedMatrixDrawer.h`: Defines the base pinout.
* `LedMatrixDrawerConfig.h`: Allows custom overrides for different PCB or breadboard layouts.

### Circuit Schematic
The library uses **row-at-a-time multiplexing**. To enable full functionality, the wiring maps 16 Arduino pins to the matrix.

![A-1088B8 Pinout](../../docs/hardware_ref/A-1088B8/A-1088B8_pinout.png)

![LED Matrix Schematic](../../shared/media/A-1088B8-Direct/circuit_schemma.png)

---

## 🇪🇸 Español
<a id="espanol"></a>

### Resumen
Este proyecto presenta una librería especializada de Arduino diseñada para controlar una **matriz LED completa de 8x8 (1088BS)**. Superando los barridos secuenciales básicos, esta librería proporciona una abstracción de alto nivel para "dibujar" cuadros estáticos y animaciones complejas gestionando el multiplexado y los tiempos de bajo nivel.

### Características
* **Soporte Completo 8x8**: Iconos y patrones de alta resolución utilizando los 64 LEDs.
* **Pinout Configurable**: Arquitectura flexible que permite redefinir los pines de filas y columnas por software para adaptarse a cualquier montaje.
* **Búfer de Cuadros**: Muestra imágenes estáticas definidas como mapas de bits (bitmaps).
* **Motor de Animación**: Reproducción basada en secuencias con retrasos de cuadro configurables.
* **Prevención de Ghosting**: Implementación de estados de alta impedancia y lógica activa para asegurar claridad visual.

### Componentes de Hardware
| Componente | Cantidad | Descripción |
| :--- | :--- | :--- |
| **Arduino Uno / Nano** | 1 | Unidad de lógica de control |
| **Matriz de LEDs 8x8 1088BS** | 1 | Pantalla de Ánodo Común |
| **Resistencias (220Ω - 1kΩ)** | 8 | Limitadores para líneas de cátodo |
| **Cables Jumper** | 24+ | Conexiones variadas |

> [!NOTA]
> Para la lista completa de componentes, ver el [BOM](../../shared/hardware/A-1088B8-Direct/bom.md) en la carpeta de hardware.

## Documentación de Hardware 

Esta sección contiene las especificaciones técnicas y diagramas de conexión necesarios para la librería.

### Referencia Técnica 
Para detalles específicos de conexiones y mapeo de coordenadas, vea los siguientes documentos:

* 📍 [**Referencia de Pines**](../../docs/hardware_ref/A-1088B8/pinout_reference.md) — Mapeo de pines físicos a filas y columnas.
* 🔗 [**Guía de Conexión**](../../shared/hardware/A-1088B8-Direct/connections.md) — Guía paso a paso para cableado a microcontroladores.
* 📄 [**Datasheet de la Matriz de LEDs**](../../docs/datasheets/A-1088BS-1.pdf) — Especificaciones completas del fabricante.

---

### Configuración de la Librería
La librería está diseñada para ser flexible. Es posible modificar el mapeo de pines sin cambiar la lógica central editando los archivos de configuración:
* `LedMatrixDrawer.h`: Define el pinout base.
* `LedMatrixDrawerConfig.h`: Permite personalizaciones para diferentes layouts de PCB o protoboard.

### Esquema del Circuito
La librería utiliza **multiplexado por filas**. Para habilitar la funcionalidad completa, el cableado mapea 16 pines de Arduino a la matriz.

![A-1088B8 Pinout](../../docs/hardware_ref/A-1088B8/A-1088B8_pinout.png)

![Esquema de la Matriz LED](../../shared/media/A-1088B8-Direct/circuit_schemma.png)