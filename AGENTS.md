# Arduino Projects Repository

## Structure
- Each project lives in `projects/<NN>-project_name/`

### New structure (recommended)
```
<project>/
├── README.md
├── firmware/     # Arduino sketches (.ino)
├── hardware/     # Circuit diagrams (.kicad_sch)
├── media/       # Photos, videos
└── docs/        # Documentation (optional)
```

### Legacy structure
```
<project>/
├── README.md
├── code/        # Arduino sketches (.ino)
├── circuit/     # Circuit diagrams (.kicad_sch)
├── asets/       # Media (typo preserved)
└── libs/       # Internal libraries
```

> **Note:** The repository has a mixed structure:
> - Projects 01-03 use the **new structure** (firmware/hardware/media/docs)
> - Projects 05-10 use the **legacy structure** (code/circuit/asets)
> - Project 04 was not created

## Projects
- `01_toggle_led_system/` - GPIO control, LED blinking with button
- `02_relay_dc_switching/` - Power isolation with relay
- `03_full_8x8_led_matrix_sweep/` - Manual 8x8 matrix control without drivers
- `05-led_matrix_sweep/` - Library for 6x6 subset of 8x8 matrix
- `06-shift_register/` - 74HC595 shift register control
- `07-led_matrix_shift_register/` - Matrix with shift register (11 pins)
- `08-Snake_game/` - Playable snake on LED matrix
- `09-RFID-experiments/` - RC522 RFID read/write
- `10-Stepper-velocity-controll/` - 28BYJ-48 stepper with potentiometer

## Working with Arduino
- Open `.ino` files in Arduino IDE
- Test by uploading to physical hardware
- Schematics in `hardware/*.kicad_sch` or `circuit/*.kicad_sch`